// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BlackKing.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHESS_BlackKing_generated_h
#error "BlackKing.generated.h already included, missing '#pragma once' in BlackKing.h"
#endif
#define CHESS_BlackKing_generated_h

#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_SPARSE_DATA
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABlackKing(); \
	friend struct Z_Construct_UClass_ABlackKing_Statics; \
public: \
	DECLARE_CLASS(ABlackKing, ABlackChessFigure, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Chess"), NO_API) \
	DECLARE_SERIALIZER(ABlackKing)


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlackKing(ABlackKing&&); \
	NO_API ABlackKing(const ABlackKing&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlackKing); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlackKing); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABlackKing) \
	NO_API virtual ~ABlackKing();


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_13_PROLOG
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_SPARSE_DATA \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_INCLASS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHESS_API UClass* StaticClass<class ABlackKing>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
