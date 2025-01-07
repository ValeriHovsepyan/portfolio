// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "WhiteChessFigure.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class ABlackChessFigure;
class UStaticMeshComponent;
#ifdef CHESS_WhiteChessFigure_generated_h
#error "WhiteChessFigure.generated.h already included, missing '#pragma once' in WhiteChessFigure.h"
#endif
#define CHESS_WhiteChessFigure_generated_h

#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_SPARSE_DATA
#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAttack); \
	DECLARE_FUNCTION(execCanAttack); \
	DECLARE_FUNCTION(execGetMesh); \
	DECLARE_FUNCTION(execmove); \
	DECLARE_FUNCTION(execTurnOffLocations); \
	DECLARE_FUNCTION(execShowLocations);


#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAWhiteChessFigure(); \
	friend struct Z_Construct_UClass_AWhiteChessFigure_Statics; \
public: \
	DECLARE_CLASS(AWhiteChessFigure, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Chess"), NO_API) \
	DECLARE_SERIALIZER(AWhiteChessFigure)


#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AWhiteChessFigure(AWhiteChessFigure&&); \
	NO_API AWhiteChessFigure(const AWhiteChessFigure&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AWhiteChessFigure); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AWhiteChessFigure); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AWhiteChessFigure) \
	NO_API virtual ~AWhiteChessFigure();


#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_11_PROLOG
#define FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_SPARSE_DATA \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHESS_API UClass* StaticClass<class AWhiteChessFigure>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
