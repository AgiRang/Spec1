// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SPEC1_Spec1Character_generated_h
#error "Spec1Character.generated.h already included, missing '#pragma once' in Spec1Character.h"
#endif
#define SPEC1_Spec1Character_generated_h

#define Spec1_Source_Spec1_Spec1Character_h_12_SPARSE_DATA
#define Spec1_Source_Spec1_Spec1Character_h_12_RPC_WRAPPERS
#define Spec1_Source_Spec1_Spec1Character_h_12_RPC_WRAPPERS_NO_PURE_DECLS
#define Spec1_Source_Spec1_Spec1Character_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASpec1Character(); \
	friend struct Z_Construct_UClass_ASpec1Character_Statics; \
public: \
	DECLARE_CLASS(ASpec1Character, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Spec1"), NO_API) \
	DECLARE_SERIALIZER(ASpec1Character)


#define Spec1_Source_Spec1_Spec1Character_h_12_INCLASS \
private: \
	static void StaticRegisterNativesASpec1Character(); \
	friend struct Z_Construct_UClass_ASpec1Character_Statics; \
public: \
	DECLARE_CLASS(ASpec1Character, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Spec1"), NO_API) \
	DECLARE_SERIALIZER(ASpec1Character)


#define Spec1_Source_Spec1_Spec1Character_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASpec1Character(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASpec1Character) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpec1Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpec1Character); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpec1Character(ASpec1Character&&); \
	NO_API ASpec1Character(const ASpec1Character&); \
public:


#define Spec1_Source_Spec1_Spec1Character_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASpec1Character(ASpec1Character&&); \
	NO_API ASpec1Character(const ASpec1Character&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASpec1Character); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASpec1Character); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASpec1Character)


#define Spec1_Source_Spec1_Spec1Character_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ASpec1Character, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ASpec1Character, FollowCamera); }


#define Spec1_Source_Spec1_Spec1Character_h_9_PROLOG
#define Spec1_Source_Spec1_Spec1Character_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Spec1_Source_Spec1_Spec1Character_h_12_PRIVATE_PROPERTY_OFFSET \
	Spec1_Source_Spec1_Spec1Character_h_12_SPARSE_DATA \
	Spec1_Source_Spec1_Spec1Character_h_12_RPC_WRAPPERS \
	Spec1_Source_Spec1_Spec1Character_h_12_INCLASS \
	Spec1_Source_Spec1_Spec1Character_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Spec1_Source_Spec1_Spec1Character_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Spec1_Source_Spec1_Spec1Character_h_12_PRIVATE_PROPERTY_OFFSET \
	Spec1_Source_Spec1_Spec1Character_h_12_SPARSE_DATA \
	Spec1_Source_Spec1_Spec1Character_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	Spec1_Source_Spec1_Spec1Character_h_12_INCLASS_NO_PURE_DECLS \
	Spec1_Source_Spec1_Spec1Character_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SPEC1_API UClass* StaticClass<class ASpec1Character>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Spec1_Source_Spec1_Spec1Character_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
