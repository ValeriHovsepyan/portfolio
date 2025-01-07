// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BlackKnight.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHESS_BlackKnight_generated_h
#error "BlackKnight.generated.h already included, missing '#pragma once' in BlackKnight.h"
#endif
#define CHESS_BlackKnight_generated_h

#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_SPARSE_DATA
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execWillOpenChack);


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABlackKnight(); \
	friend struct Z_Construct_UClass_ABlackKnight_Statics; \
public: \
	DECLARE_CLASS(ABlackKnight, ABlackChessFigure, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Chess"), NO_API) \
	DECLARE_SERIALIZER(ABlackKnight)


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlackKnight(ABlackKnight&&); \
	NO_API ABlackKnight(const ABlackKnight&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlackKnight); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlackKnight); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABlackKnight) \
	NO_API virtual ~ABlackKnight();


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_15_PROLOG
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_SPARSE_DATA \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_INCLASS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHESS_API UClass* StaticClass<class ABlackKnight>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_valho_MyProject_Chess_Source_Chess_BlackKnight_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
