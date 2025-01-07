// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "BlackChessFigure.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AWhiteChessFigure;
class UStaticMeshComponent;
#ifdef CHESS_BlackChessFigure_generated_h
#error "BlackChessFigure.generated.h already included, missing '#pragma once' in BlackChessFigure.h"
#endif
#define CHESS_BlackChessFigure_generated_h

#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_SPARSE_DATA
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execAttack); \
	DECLARE_FUNCTION(execCanAttack); \
	DECLARE_FUNCTION(execGetMesh); \
	DECLARE_FUNCTION(execmove); \
	DECLARE_FUNCTION(execTurnOffLocations); \
	DECLARE_FUNCTION(execShowLocations);


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_ACCESSORS
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABlackChessFigure(); \
	friend struct Z_Construct_UClass_ABlackChessFigure_Statics; \
public: \
	DECLARE_CLASS(ABlackChessFigure, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Chess"), NO_API) \
	DECLARE_SERIALIZER(ABlackChessFigure)


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABlackChessFigure(ABlackChessFigure&&); \
	NO_API ABlackChessFigure(const ABlackChessFigure&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABlackChessFigure); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABlackChessFigure); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABlackChessFigure) \
	NO_API virtual ~ABlackChessFigure();


#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_11_PROLOG
#define FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_SPARSE_DATA \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_ACCESSORS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> CHESS_API UClass* StaticClass<class ABlackChessFigure>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
