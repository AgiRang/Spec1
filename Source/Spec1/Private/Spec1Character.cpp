// Copyright Epic Games, Inc. All Rights Reserved.

#include "Spec1Character.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "TimerManager.h"

#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"

//////////////////////////////////////////////////////////////////////////
// ASpec1Character

ASpec1Character::ASpec1Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	bAttackA = false;
	bAttackB = false;
	bLMouseDown = false;
	bRMouseDown = false;
	ComboCount = 0;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input


void ASpec1Character::LMouseDown()
{
	UE_LOG(LogTemp, Warning, TEXT("LMouseDown()"));
	bLMouseDown = true;

	if (bAttackA == false) {
		DoAttackA();
	}
}

void ASpec1Character::RMouseDown()
{
	UE_LOG(LogTemp, Warning, TEXT("RMouseDown()"));
	bRMouseDown = true;

	if (bAttackB == false) {
		DoAttackB();
	}
}

void ASpec1Character::DoAttackA()
{
	UE_LOG(LogTemp, Warning, TEXT("AttackA()"));
	bLMouseDown = true;

	UAnimInstance* Animinstance = GetMesh()->GetAnimInstance();
	if (!Animinstance || !Boss_Attack_HandAndSwordSwing_M) return;

	//clean status
	bAttackA = true;
	const char* comboList[] = { "HandAndSwordSwing01","HandAndSwordSwing02","HandAndSwordSwing03" };

	if (!(Animinstance->Montage_IsPlaying(Boss_Attack_HandAndSwordSwing_M))) {
		Animinstance->Montage_Play(Boss_Attack_HandAndSwordSwing_M);
	}
	else {
		Animinstance->Montage_Play(Boss_Attack_HandAndSwordSwing_M);
		Animinstance->Montage_JumpToSection(FName(comboList[ComboCount]), Boss_Attack_HandAndSwordSwing_M);
	}
}

void ASpec1Character::DoAttackB()
{
	UE_LOG(LogTemp, Warning, TEXT("AttackB()"));
	bRMouseDown = true;
}

void ASpec1Character::EndAttackA()
{
	UE_LOG(LogTemp, Warning, TEXT("EndAttackA()"));
	bAttackA = false;
}

void ASpec1Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Dash", IE_Released, this, &ASpec1Character::Dash);
	PlayerInputComponent->BindAction("LMB", IE_Pressed, this, &ASpec1Character::DoAttackA);
	PlayerInputComponent->BindAction("RMB", IE_Pressed, this, &ASpec1Character::DoAttackB);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASpec1Character::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASpec1Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ASpec1Character::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ASpec1Character::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASpec1Character::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASpec1Character::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ASpec1Character::OnResetVR);
}

void ASpec1Character::Dash()
{
	if (CanDash) {
		CanDash = false;
		LaunchCharacter(FVector(FollowCamera->GetForwardVector().X, FollowCamera->GetForwardVector().Y, 0) * 8000, true, true);
	
	}
}

void ASpec1Character::StopDash()
{
	GetCharacterMovement()->StopMovementImmediately();

}

void ASpec1Character::ResetDash()
{
	CanDash = true;
}


void ASpec1Character::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ASpec1Character::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void ASpec1Character::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void ASpec1Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASpec1Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ASpec1Character::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ASpec1Character::MoveRight(float Value)
{
	if ( (Controller != NULL) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
