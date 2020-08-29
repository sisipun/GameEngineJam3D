// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef MYGAME_MyGameGameModeBase_generated_h
#error "MyGameGameModeBase.generated.h already included, missing '#pragma once' in MyGameGameModeBase.h"
#endif
#define MYGAME_MyGameGameModeBase_generated_h

#define MyGame_Source_MyGame_MyGameGameModeBase_h_15_RPC_WRAPPERS
#define MyGame_Source_MyGame_MyGameGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define MyGame_Source_MyGame_MyGameGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyGameGameModeBase(); \
	friend struct Z_Construct_UClass_AMyGameGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AMyGameGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/MyGame"), NO_API) \
	DECLARE_SERIALIZER(AMyGameGameModeBase)


#define MyGame_Source_MyGame_MyGameGameModeBase_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAMyGameGameModeBase(); \
	friend struct Z_Construct_UClass_AMyGameGameModeBase_Statics; \
public: \
	DECLARE_CLASS(AMyGameGameModeBase, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/MyGame"), NO_API) \
	DECLARE_SERIALIZER(AMyGameGameModeBase)


#define MyGame_Source_MyGame_MyGameGameModeBase_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyGameGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyGameGameModeBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyGameGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyGameGameModeBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyGameGameModeBase(AMyGameGameModeBase&&); \
	NO_API AMyGameGameModeBase(const AMyGameGameModeBase&); \
public:


#define MyGame_Source_MyGame_MyGameGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyGameGameModeBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyGameGameModeBase(AMyGameGameModeBase&&); \
	NO_API AMyGameGameModeBase(const AMyGameGameModeBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyGameGameModeBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyGameGameModeBase); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyGameGameModeBase)


#define MyGame_Source_MyGame_MyGameGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET
#define MyGame_Source_MyGame_MyGameGameModeBase_h_12_PROLOG
#define MyGame_Source_MyGame_MyGameGameModeBase_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyGame_Source_MyGame_MyGameGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	MyGame_Source_MyGame_MyGameGameModeBase_h_15_RPC_WRAPPERS \
	MyGame_Source_MyGame_MyGameGameModeBase_h_15_INCLASS \
	MyGame_Source_MyGame_MyGameGameModeBase_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define MyGame_Source_MyGame_MyGameGameModeBase_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	MyGame_Source_MyGame_MyGameGameModeBase_h_15_PRIVATE_PROPERTY_OFFSET \
	MyGame_Source_MyGame_MyGameGameModeBase_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	MyGame_Source_MyGame_MyGameGameModeBase_h_15_INCLASS_NO_PURE_DECLS \
	MyGame_Source_MyGame_MyGameGameModeBase_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> MYGAME_API UClass* StaticClass<class AMyGameGameModeBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID MyGame_Source_MyGame_MyGameGameModeBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
