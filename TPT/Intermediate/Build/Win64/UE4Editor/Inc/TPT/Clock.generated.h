// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TPT_Clock_generated_h
#error "Clock.generated.h already included, missing '#pragma once' in Clock.h"
#endif
#define TPT_Clock_generated_h

#define TPT_Source_TPT_Clock_h_11_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTimeChanged) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Hours); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Minutes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TimeChanged(Z_Param_Hours,Z_Param_Minutes); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_Clock_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTimeChanged) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_Hours); \
		P_GET_PROPERTY(UIntProperty,Z_Param_Minutes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->TimeChanged(Z_Param_Hours,Z_Param_Minutes); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_Clock_h_11_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAClock(); \
	friend TPT_API class UClass* Z_Construct_UClass_AClock(); \
	public: \
	DECLARE_CLASS(AClock, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(AClock) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_Clock_h_11_INCLASS \
	private: \
	static void StaticRegisterNativesAClock(); \
	friend TPT_API class UClass* Z_Construct_UClass_AClock(); \
	public: \
	DECLARE_CLASS(AClock, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(AClock) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_Clock_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AClock(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AClock) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AClock); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AClock); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AClock(AClock&&); \
	NO_API AClock(const AClock&); \
public:


#define TPT_Source_TPT_Clock_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AClock(AClock&&); \
	NO_API AClock(const AClock&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AClock); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AClock); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AClock)


#define TPT_Source_TPT_Clock_h_11_PRIVATE_PROPERTY_OFFSET
#define TPT_Source_TPT_Clock_h_8_PROLOG
#define TPT_Source_TPT_Clock_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_Clock_h_11_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_Clock_h_11_RPC_WRAPPERS \
	TPT_Source_TPT_Clock_h_11_INCLASS \
	TPT_Source_TPT_Clock_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TPT_Source_TPT_Clock_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_Clock_h_11_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_Clock_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	TPT_Source_TPT_Clock_h_11_INCLASS_NO_PURE_DECLS \
	TPT_Source_TPT_Clock_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TPT_Source_TPT_Clock_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
