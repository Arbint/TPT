// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AInventoryActor;
#ifdef TPT_InventoryComponent_generated_h
#error "InventoryComponent.generated.h already included, missing '#pragma once' in InventoryComponent.h"
#endif
#define TPT_InventoryComponent_generated_h

#define TPT_Source_TPT_InventoryComponent_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRemoveFromInventory) \
	{ \
		P_GET_OBJECT(AInventoryActor,Z_Param_ActorToRemove); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RemoveFromInventory(Z_Param_ActorToRemove); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddToInventory) \
	{ \
		P_GET_OBJECT(AInventoryActor,Z_Param_ActorToAdd); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->AddToInventory(Z_Param_ActorToAdd); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_InventoryComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRemoveFromInventory) \
	{ \
		P_GET_OBJECT(AInventoryActor,Z_Param_ActorToRemove); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->RemoveFromInventory(Z_Param_ActorToRemove); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddToInventory) \
	{ \
		P_GET_OBJECT(AInventoryActor,Z_Param_ActorToAdd); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=this->AddToInventory(Z_Param_ActorToAdd); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_InventoryComponent_h_13_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUInventoryComponent(); \
	friend TPT_API class UClass* Z_Construct_UClass_UInventoryComponent(); \
	public: \
	DECLARE_CLASS(UInventoryComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(UInventoryComponent) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_InventoryComponent_h_13_INCLASS \
	private: \
	static void StaticRegisterNativesUInventoryComponent(); \
	friend TPT_API class UClass* Z_Construct_UClass_UInventoryComponent(); \
	public: \
	DECLARE_CLASS(UInventoryComponent, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(UInventoryComponent) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_InventoryComponent_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UInventoryComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UInventoryComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryComponent(UInventoryComponent&&); \
	NO_API UInventoryComponent(const UInventoryComponent&); \
public:


#define TPT_Source_TPT_InventoryComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UInventoryComponent(UInventoryComponent&&); \
	NO_API UInventoryComponent(const UInventoryComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UInventoryComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UInventoryComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UInventoryComponent)


#define TPT_Source_TPT_InventoryComponent_h_13_PRIVATE_PROPERTY_OFFSET
#define TPT_Source_TPT_InventoryComponent_h_10_PROLOG
#define TPT_Source_TPT_InventoryComponent_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_InventoryComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_InventoryComponent_h_13_RPC_WRAPPERS \
	TPT_Source_TPT_InventoryComponent_h_13_INCLASS \
	TPT_Source_TPT_InventoryComponent_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TPT_Source_TPT_InventoryComponent_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_InventoryComponent_h_13_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_InventoryComponent_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	TPT_Source_TPT_InventoryComponent_h_13_INCLASS_NO_PURE_DECLS \
	TPT_Source_TPT_InventoryComponent_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TPT_Source_TPT_InventoryComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
