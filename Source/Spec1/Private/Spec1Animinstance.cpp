// Fill out your copyright notice in the Description page of Project Settings.


#include "Spec1Animinstance.h"

USpec1Animinstance::USpec1Animinstance()
{
	bIsAttack = false;
}

void USpec1Animinstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void USpec1Animinstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
}

void USpec1Animinstance::Attack()
{
	//Attack Montage
	FString path = L"AnimBlueprint'/Game/BP_CPlayerAnimation.BP_CPlayerAnimation_C'";
	ConstructorHelpers::FClassFinder<UAnimInstance> animInstance(*path);
	if (animInstance.Succeeded())
	{
		AnimInstance = animInstance.Class;
		GetMesh()->SetAnimInstanceClass(AnimInstance);
	}
	//바디 메시 설정
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(TEXT("SkeletalMesh'/Game/Frank_RPG_Dual/Skeletal_Meshes/SK_Mannequin.SK_Mannequin'"));
	if (SK_BODY.Succeeded())
	{
		//캐릭터에서 상속된 메시에 스켈레탈 메시 설정
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	}
	//애니메이션 모드 설정
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	//애니메이션 블루프린트 가져오기 클래스를 가져오는 것이기 때문에 맨 마지막에 _C를 붙여아함
	static ConstructorHelpers::FClassFinder<UAnimInstance> BLADER_ANIM(
		TEXT("AnimBlueprint'/Game/Frank_RPG_Dual/Animations/AnimBP_Blader.AnimBP_Blader_C'"));
	if (BLADER_ANIM.Succeeded())
	{
		//애니메이션 블루프린트를 설정
		GetMesh()->SetAnimInstanceClass(BLADER_ANIM.Class);
	}
}
