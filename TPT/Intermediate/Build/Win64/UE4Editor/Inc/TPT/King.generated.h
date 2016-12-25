// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AKing;
#ifdef TPT_King_generated_h
#error "King.generated.h already included, missing '#pragma once' in King.h"
#endif
#define TPT_King_generated_h

#define TPT_Source_TPT_Chap8_King_h_13_DELEGATE \
struct _Script_TPT_eventOnKingDeathSignature_Parms \
{ \
	AKing* DeadKing; \
}; \
static inline void FOnKingDeathSignature_DelegateWrapper(const FMulticastScriptDelegate& OnKingDeathSignature, AKing* DeadKing) \
{ \
	_Script_TPT_eventOnKingDeathSignature_Parms Parms; \
	Parms.DeadKing=DeadKing; \
	OnKingDeathSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}




#define TPT_Source_TPT_Chap8_King_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDie) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Die(); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_Chap8_King_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDie) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Die(); \
		P_NATIVE_END; \
	}


#define TPT_Source_TPT_Chap8_King_h_19_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesAKing(); \
	friend TPT_API class UClass* Z_Construct_UClass_AKing(); \
	public: \
	DECLARE_CLASS(AKing, AStaticMeshActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(AKing) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_Chap8_King_h_19_INCLASS \
	private: \
	static void StaticRegisterNativesAKing(); \
	friend TPT_API class UClass* Z_Construct_UClass_AKing(); \
	public: \
	DECLARE_CLASS(AKing, AStaticMeshActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/TPT"), NO_API) \
	DECLARE_SERIALIZER(AKing) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define TPT_Source_TPT_Chap8_King_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AKing(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AKing) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AKing); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AKing); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AKing(AKing&&); \
	NO_API AKing(const AKing&); \
public:


#define TPT_Source_TPT_Chap8_King_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AKing(AKing&&); \
	NO_API AKing(const AKing&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AKing); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AKing); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AKing)


#define TPT_Source_TPT_Chap8_King_h_19_PRIVATE_PROPERTY_OFFSET
#define TPT_Source_TPT_Chap8_King_h_16_PROLOG
#define TPT_Source_TPT_Chap8_King_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_Chap8_King_h_19_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_Chap8_King_h_19_RPC_WRAPPERS \
	TPT_Source_TPT_Chap8_King_h_19_INCLASS \
	TPT_Source_TPT_Chap8_King_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define TPT_Source_TPT_Chap8_King_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	TPT_Source_TPT_Chap8_King_h_19_PRIVATE_PROPERTY_OFFSET \
	TPT_Source_TPT_Chap8_King_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	TPT_Source_TPT_Chap8_King_h_19_INCLASS_NO_PURE_DECLS \
	TPT_Source_TPT_Chap8_King_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID TPT_Source_TPT_Chap8_King_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
