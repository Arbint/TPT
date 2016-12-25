// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TPT_MulticastDelegateListener_generated_h
#error "MulticastDelegateListener.generated.h already included, missing '#pragma once' in MulticastDelegateListener.h"
#endif
#define TPT_MulticastDelegateListener_generated_h

#define TPT_Source_TPT_MulticastDelegateListener_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEndPlay) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_EndPlayReason); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->EndPlay(EEndPlayReason::Type(Z_Param_EndPlayReason)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execToggleLight) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ToggleLight(); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_MulticastDelegateListener_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEndPlay) \
	{ \
		P_GET_PROPERTY(UByteProperty,Z_Param_EndPlayReason); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->EndPlay(EEndPlayReason::Type(Z_Param_EndPlayReason)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execToggleLight) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->ToggleLight(); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_MulticastDelegateListener_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAMulticastDelegateListener(); \
	friend TPT_API class UClass* Z_Construct_UClass_AMulticastDelegateListener(); \
	public: \
	DECLARE_CLASS(AMulticastDelegateListener, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(AMulticastDelegateListener) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_MulticastDelegateListener_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesAMulticastDelegateListener(); \
	friend TPT_API class UClass* Z_Construct_UClass_AMulticastDelegateListener(); \
	public: \
	DECLARE_CLASS(AMulticastDelegateListener, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(AMulticastDelegateListener) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_MulticastDelegateListener_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMulticastDelegateListener(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMulticastDelegateListener) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMulticastDelegateListener); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMulticastDelegateListener); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMulticastDelegateListener(AMulticastDelegateListener&&); \
	NO_API AMulticastDelegateListener(const AMulticastDelegateListener&); \
public:


#define TPT_Source_TPT_MulticastDelegateListener_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMulticastDelegateListener(AMulticastDelegateListener&&); \
	NO_API AMulticastDelegateListener(const AMulticastDelegateListener&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMulticastDelegateListener); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMulticastDelegateListener); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMulticastDelegateListener)


#define TPT_Source_TPT_MulticastDelegateListener_h_11_PRIVATE_PROPERTY_OFFSET
#define TPT_Source_TPT_MulticastDelegateListener_h_8_PROLOG
#define TPT_Source_TPT_MulticastDelegateListener_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_MulticastDelegateListener_h_11_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_MulticastDelegateListener_h_11_RPC_WRAPPERS \
	TPT_Source_TPT_MulticastDelegateListener_h_11_INCLASS \
	TPT_Source_TPT_MulticastDelegateListener_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TPT_Source_TPT_MulticastDelegateListener_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_MulticastDelegateListener_h_11_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_MulticastDelegateListener_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	TPT_Source_TPT_MulticastDelegateListener_h_11_INCLASS_NO_PURE_DECLS \
	TPT_Source_TPT_MulticastDelegateListener_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TPT_Source_TPT_MulticastDelegateListener_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
