// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef TPT_Warrior_generated_h
#error "Warrior.generated.h already included, missing '#pragma once' in Warrior.h"
#endif
#define TPT_Warrior_generated_h

#define TPT_Source_TPT_Warrior_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetDirectionToPlayer) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_FromPosition); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutDirection); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->GetDirectionToPlayer(Z_Param_Out_FromPosition,Z_Param_Out_OutDirection); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTryInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TryInteract(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCollideWithItem) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CollideWithItem(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_Warrior_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetDirectionToPlayer) \
	{ \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_FromPosition); \
		P_GET_STRUCT_REF(FVector,Z_Param_Out_OutDirection); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->GetDirectionToPlayer(Z_Param_Out_FromPosition,Z_Param_Out_OutDirection); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTryInteract) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TryInteract(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCollideWithItem) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent); \
		P_GET_OBJECT(AActor,Z_Param_OtherActor); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp); \
		P_GET_PROPERTY(UIntProperty,Z_Param_OtherBodyIndex); \
		P_GET_UBOOL(Z_Param_bFromSweep); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CollideWithItem(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_Warrior_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAWarrior(); \
	friend TPT_API class UClass* Z_Construct_UClass_AWarrior(); \
	public: \
	DECLARE_CLASS(AWarrior, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(AWarrior) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_Warrior_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesAWarrior(); \
	friend TPT_API class UClass* Z_Construct_UClass_AWarrior(); \
	public: \
	DECLARE_CLASS(AWarrior, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(AWarrior) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_Warrior_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AWarrior(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AWarrior) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWarrior); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWarrior); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWarrior(AWarrior&&); \
	NO_API AWarrior(const AWarrior&); \
public:


#define TPT_Source_TPT_Warrior_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWarrior(AWarrior&&); \
	NO_API AWarrior(const AWarrior&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWarrior); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWarrior); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWarrior)


#define TPT_Source_TPT_Warrior_h_11_PRIVATE_PROPERTY_OFFSET
#define TPT_Source_TPT_Warrior_h_8_PROLOG
#define TPT_Source_TPT_Warrior_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_Warrior_h_11_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_Warrior_h_11_RPC_WRAPPERS \
	TPT_Source_TPT_Warrior_h_11_INCLASS \
	TPT_Source_TPT_Warrior_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TPT_Source_TPT_Warrior_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_Warrior_h_11_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_Warrior_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	TPT_Source_TPT_Warrior_h_11_INCLASS_NO_PURE_DECLS \
	TPT_Source_TPT_Warrior_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TPT_Source_TPT_Warrior_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
