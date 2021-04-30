// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Spec1Animinstance.generated.h"
/**
 * 
 */
UCLASS(transient,Blueprintable,hideCategories=AnimInstance,BlueprintType)
class USpec1Animinstance :public UAnimInstance
{
	GENERATED_BODY()
public:

	USpec1Animinstance();
	
	virtual void NativeBeginPlay()override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
	UFUNCTION(BlueprintCallable)
		void Attack();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Spec1Animinstance, meta = (AllowprivateAccess = "true"))
		bool bIsAttack;

};
