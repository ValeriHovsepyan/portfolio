// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BlackQuin.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHESS_BlackQuin_generated_h
#error "BlackQuin.generated.h already included, missing '#pragma once' in BlackQuin.h"
#endif
#define CHESS_BlackQuin_generated_h

#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_SPARSE_DATA
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execWillOpenChack);


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABlackQuin(); \
	friend struct Z_Construct_UClass_ABlackQuin_Statics; \
public: \
	DECLARE_CLASS(ABlackQuin, ABlackChessFigure, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Chess"), NO_API) \
	DECLARE_SERIALIZER(ABlackQuin)


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlackQuin(ABlackQuin&&); \
	NO_API ABlackQuin(const ABlackQuin&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlackQuin); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlackQuin); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABlackQuin) \
	NO_API virtual ~ABlackQuin();


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_14_PROLOG
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_SPARSE_DATA \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_INCLASS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHESS_API UClass* StaticClass<class ABlackQuin>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_valho_MyProject_Chess_Source_Chess_BlackQuin_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
