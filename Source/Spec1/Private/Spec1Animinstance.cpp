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
	//�ٵ� �޽� ����
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_BODY(TEXT("SkeletalMesh'/Game/Frank_RPG_Dual/Skeletal_Meshes/SK_Mannequin.SK_Mannequin'"));
	if (SK_BODY.Succeeded())
	{
		//ĳ���Ϳ��� ��ӵ� �޽ÿ� ���̷�Ż �޽� ����
		GetMesh()->SetSkeletalMesh(SK_BODY.Object);
	}
	//�ִϸ��̼� ��� ����
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	//�ִϸ��̼� �������Ʈ �������� Ŭ������ �������� ���̱� ������ �� �������� _C�� �ٿ�����
	static ConstructorHelpers::FClassFinder<UAnimInstance> BLADER_ANIM(
		TEXT("AnimBlueprint'/Game/Frank_RPG_Dual/Animations/AnimBP_Blader.AnimBP_Blader_C'"));
	if (BLADER_ANIM.Succeeded())
	{
		//�ִϸ��̼� �������Ʈ�� ����
		GetMesh()->SetAnimInstanceClass(BLADER_ANIM.Class);
	}
}
