// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ChessCharacter.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef CHESS_ChessCharacter_generated_h
#error "ChessCharacter.generated.h already included, missing '#pragma once' in ChessCharacter.h"
#endif
#define CHESS_ChessCharacter_generated_h

#define FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_SPARSE_DATA
#define FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIncrementRounds); \
	DECLARE_FUNCTION(execGetRounds);


#define FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAChessCharacter(); \
	friend struct Z_Construct_UClass_AChessCharacter_Statics; \
public: \
	DECLARE_CLASS(AChessCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Chess"), NO_API) \
	DECLARE_SERIALIZER(AChessCharacter)


#define FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AChessCharacter(AChessCharacter&&); \
	NO_API AChessCharacter(const AChessCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AChessCharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AChessCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AChessCharacter) \
	NO_API virtual ~AChessCharacter();


#define FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_18_PROLOG
#define FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_SPARSE_DATA \
	FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_INCLASS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHESS_API UClass* StaticClass<class AChessCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_valho_MyProject_Chess_Source_Chess_ChessCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
