// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
class AInventoryActor;
class AWeapon_Base;
#ifdef TPT_TPTCharacter_generated_h
#error "TPTCharacter.generated.h already included, missing '#pragma once' in TPTCharacter.h"
#endif
#define TPT_TPTCharacter_generated_h

#define TPT_Source_TPT_TPTCharacter_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execPrintName) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PrintName(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNotifyHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_MyComp); \
		P_GET_OBJECT(AActor,Z_Param_Other); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent); \
		P_GET_UBOOL(Z_Param_bSelfMoved); \
		P_GET_STRUCT(FVector,Z_Param_HitLocaiton); \
		P_GET_STRUCT(FVector,Z_Param_HitNormal); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->NotifyHit(Z_Param_MyComp,Z_Param_Other,Z_Param_OtherComponent,Z_Param_bSelfMoved,Z_Param_HitLocaiton,Z_Param_HitNormal,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTakeItem) \
	{ \
		P_GET_OBJECT(AInventoryActor,Z_Param_InventoryItem); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TakeItem(Z_Param_InventoryItem); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDropItem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DropItem(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTrySmartPtrWithClass) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TrySmartPtrWithClass(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateUnversalFunction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CreateUnversalFunction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateAxeOnMe) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CreateAxeOnMe(Z_Param_height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDeleteUnvFuc) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DeleteUnvFuc(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDeleteWeapon) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DeleteWeapon(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateWeapon) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AWeapon_Base**)Z_Param__Result=this->CreateWeapon(); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_TPTCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execPrintName) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->PrintName(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNotifyHit) \
	{ \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_MyComp); \
		P_GET_OBJECT(AActor,Z_Param_Other); \
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComponent); \
		P_GET_UBOOL(Z_Param_bSelfMoved); \
		P_GET_STRUCT(FVector,Z_Param_HitLocaiton); \
		P_GET_STRUCT(FVector,Z_Param_HitNormal); \
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse); \
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->NotifyHit(Z_Param_MyComp,Z_Param_Other,Z_Param_OtherComponent,Z_Param_bSelfMoved,Z_Param_HitLocaiton,Z_Param_HitNormal,Z_Param_NormalImpulse,Z_Param_Out_Hit); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTakeItem) \
	{ \
		P_GET_OBJECT(AInventoryActor,Z_Param_InventoryItem); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TakeItem(Z_Param_InventoryItem); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDropItem) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DropItem(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execTrySmartPtrWithClass) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TrySmartPtrWithClass(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateUnversalFunction) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CreateUnversalFunction(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateAxeOnMe) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_height); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->CreateAxeOnMe(Z_Param_height); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDeleteUnvFuc) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DeleteUnvFuc(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDeleteWeapon) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->DeleteWeapon(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCreateWeapon) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(AWeapon_Base**)Z_Param__Result=this->CreateWeapon(); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_TPTCharacter_h_21_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesATPTCharacter(); \
	friend TPT_API class UClass* Z_Construct_UClass_ATPTCharacter(); \
	public: \
	DECLARE_CLASS(ATPTCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(ATPTCharacter) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_TPTCharacter_h_21_INCLASS \
	private: \
	static void StaticRegisterNativesATPTCharacter(); \
	friend TPT_API class UClass* Z_Construct_UClass_ATPTCharacter(); \
	public: \
	DECLARE_CLASS(ATPTCharacter, ACharacter, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(ATPTCharacter) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_TPTCharacter_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ATPTCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ATPTCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATPTCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATPTCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATPTCharacter(ATPTCharacter&&); \
	NO_API ATPTCharacter(const ATPTCharacter&); \
public:


#define TPT_Source_TPT_TPTCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATPTCharacter(ATPTCharacter&&); \
	NO_API ATPTCharacter(const ATPTCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATPTCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATPTCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATPTCharacter)


#define TPT_Source_TPT_TPTCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(ATPTCharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(ATPTCharacter, FollowCamera); }


#define TPT_Source_TPT_TPTCharacter_h_18_PROLOG
#define TPT_Source_TPT_TPTCharacter_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_TPTCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_TPTCharacter_h_21_RPC_WRAPPERS \
	TPT_Source_TPT_TPTCharacter_h_21_INCLASS \
	TPT_Source_TPT_TPTCharacter_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TPT_Source_TPT_TPTCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_TPTCharacter_h_21_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_TPTCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	TPT_Source_TPT_TPTCharacter_h_21_INCLASS_NO_PURE_DECLS \
	TPT_Source_TPT_TPTCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TPT_Source_TPT_TPTCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
