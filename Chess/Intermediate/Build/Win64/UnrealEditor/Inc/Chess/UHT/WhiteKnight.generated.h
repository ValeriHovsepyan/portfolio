// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WhiteKnight.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHESS_WhiteKnight_generated_h
#error "WhiteKnight.generated.h already included, missing '#pragma once' in WhiteKnight.h"
#endif
#define CHESS_WhiteKnight_generated_h

#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_SPARSE_DATA
#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execWillOpenChack);


#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWhiteKnight(); \
	friend struct Z_Construct_UClass_AWhiteKnight_Statics; \
public: \
	DECLARE_CLASS(AWhiteKnight, AWhiteChessFigure, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Chess"), NO_API) \
	DECLARE_SERIALIZER(AWhiteKnight)


#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWhiteKnight(AWhiteKnight&&); \
	NO_API AWhiteKnight(const AWhiteKnight&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWhiteKnight); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWhiteKnight); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWhiteKnight) \
	NO_API virtual ~AWhiteKnight();


#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_15_PROLOG
#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_SPARSE_DATA \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHESS_API UClass* StaticClass<class AWhiteKnight>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKnight_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
