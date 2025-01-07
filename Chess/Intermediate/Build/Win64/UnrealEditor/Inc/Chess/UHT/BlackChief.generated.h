// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BlackChief.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHESS_BlackChief_generated_h
#error "BlackChief.generated.h already included, missing '#pragma once' in BlackChief.h"
#endif
#define CHESS_BlackChief_generated_h

#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_SPARSE_DATA
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execWillOpenChack);


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABlackChief(); \
	friend struct Z_Construct_UClass_ABlackChief_Statics; \
public: \
	DECLARE_CLASS(ABlackChief, ABlackChessFigure, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Chess"), NO_API) \
	DECLARE_SERIALIZER(ABlackChief)


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlackChief(ABlackChief&&); \
	NO_API ABlackChief(const ABlackChief&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlackChief); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlackChief); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABlackChief) \
	NO_API virtual ~ABlackChief();


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_14_PROLOG
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_SPARSE_DATA \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_INCLASS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHESS_API UClass* StaticClass<class ABlackChief>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_valho_MyProject_Chess_Source_Chess_BlackChief_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
