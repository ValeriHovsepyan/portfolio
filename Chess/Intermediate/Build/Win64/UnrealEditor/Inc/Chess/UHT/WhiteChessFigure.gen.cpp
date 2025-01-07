// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Chess/WhiteChessFigure.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWhiteChessFigure() {}
// Cross Module References
	CHESS_API UClass* Z_Construct_UClass_ABlackChessFigure_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_AWhiteChessFigure();
	CHESS_API UClass* Z_Construct_UClass_AWhiteChessFigure_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Chess();
// End Cross Module References
	DEFINE_FUNCTION(AWhiteChessFigure::execAttack)
	{
		P_GET_OBJECT(ABlackChessFigure,Z_Param_BlackFigure);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Attack(Z_Param_BlackFigure);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWhiteChessFigure::execCanAttack)
	{
		P_GET_STRUCT(FVector,Z_Param_Direction);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanAttack(Z_Param_Direction);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWhiteChessFigure::execGetMesh)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UStaticMeshComponent**)Z_Param__Result=P_THIS->GetMesh();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWhiteChessFigure::execmove)
	{
		P_GET_STRUCT(FVector,Z_Param_Direction);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->move(Z_Param_Direction);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWhiteChessFigure::execTurnOffLocations)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TurnOffLocations();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWhiteChessFigure::execShowLocations)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ShowLocations();
		P_NATIVE_END;
	}
	void AWhiteChessFigure::StaticRegisterNativesAWhiteChessFigure()
	{
		UClass* Class = AWhiteChessFigure::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Attack", &AWhiteChessFigure::execAttack },
			{ "CanAttack", &AWhiteChessFigure::execCanAttack },
			{ "GetMesh", &AWhiteChessFigure::execGetMesh },
			{ "move", &AWhiteChessFigure::execmove },
			{ "ShowLocations", &AWhiteChessFigure::execShowLocations },
			{ "TurnOffLocations", &AWhiteChessFigure::execTurnOffLocations },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics
	{
		struct WhiteChessFigure_eventAttack_Parms
		{
			ABlackChessFigure* BlackFigure;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BlackFigure;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::NewProp_BlackFigure = { "BlackFigure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WhiteChessFigure_eventAttack_Parms, BlackFigure), Z_Construct_UClass_ABlackChessFigure_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::NewProp_BlackFigure,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWhiteChessFigure, nullptr, "Attack", nullptr, nullptr, Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::WhiteChessFigure_eventAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::WhiteChessFigure_eventAttack_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AWhiteChessFigure_Attack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWhiteChessFigure_Attack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics
	{
		struct WhiteChessFigure_eventCanAttack_Parms
		{
			FVector Direction;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WhiteChessFigure_eventCanAttack_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WhiteChessFigure_eventCanAttack_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WhiteChessFigure_eventCanAttack_Parms), &Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::NewProp_Direction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWhiteChessFigure, nullptr, "CanAttack", nullptr, nullptr, Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::WhiteChessFigure_eventCanAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::WhiteChessFigure_eventCanAttack_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AWhiteChessFigure_CanAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWhiteChessFigure_CanAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics
	{
		struct WhiteChessFigure_eventGetMesh_Parms
		{
			UStaticMeshComponent* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WhiteChessFigure_eventGetMesh_Parms, ReturnValue), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWhiteChessFigure, nullptr, "GetMesh", nullptr, nullptr, Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::WhiteChessFigure_eventGetMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::WhiteChessFigure_eventGetMesh_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AWhiteChessFigure_GetMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWhiteChessFigure_GetMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWhiteChessFigure_move_Statics
	{
		struct WhiteChessFigure_eventmove_Parms
		{
			FVector Direction;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_Direction;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AWhiteChessFigure_move_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(WhiteChessFigure_eventmove_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWhiteChessFigure_move_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWhiteChessFigure_move_Statics::NewProp_Direction,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWhiteChessFigure_move_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWhiteChessFigure_move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWhiteChessFigure, nullptr, "move", nullptr, nullptr, Z_Construct_UFunction_AWhiteChessFigure_move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_move_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWhiteChessFigure_move_Statics::WhiteChessFigure_eventmove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_move_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWhiteChessFigure_move_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_move_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AWhiteChessFigure_move_Statics::WhiteChessFigure_eventmove_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AWhiteChessFigure_move()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWhiteChessFigure_move_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWhiteChessFigure_ShowLocations_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWhiteChessFigure_ShowLocations_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWhiteChessFigure_ShowLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWhiteChessFigure, nullptr, "ShowLocations", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_ShowLocations_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWhiteChessFigure_ShowLocations_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AWhiteChessFigure_ShowLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWhiteChessFigure_ShowLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWhiteChessFigure_TurnOffLocations_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWhiteChessFigure_TurnOffLocations_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWhiteChessFigure_TurnOffLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWhiteChessFigure, nullptr, "TurnOffLocations", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteChessFigure_TurnOffLocations_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWhiteChessFigure_TurnOffLocations_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AWhiteChessFigure_TurnOffLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWhiteChessFigure_TurnOffLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWhiteChessFigure);
	UClass* Z_Construct_UClass_AWhiteChessFigure_NoRegister()
	{
		return AWhiteChessFigure::StaticClass();
	}
	struct Z_Construct_UClass_AWhiteChessFigure_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Material_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Material;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AttackColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_AttackColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_UsualColor_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_UsualColor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_moved_MetaData[];
#endif
		static void NewProp_moved_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_moved;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWhiteChessFigure_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Chess,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteChessFigure_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AWhiteChessFigure_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AWhiteChessFigure_Attack, "Attack" }, // 2099199904
		{ &Z_Construct_UFunction_AWhiteChessFigure_CanAttack, "CanAttack" }, // 1164937781
		{ &Z_Construct_UFunction_AWhiteChessFigure_GetMesh, "GetMesh" }, // 1249979104
		{ &Z_Construct_UFunction_AWhiteChessFigure_move, "move" }, // 1166120007
		{ &Z_Construct_UFunction_AWhiteChessFigure_ShowLocations, "ShowLocations" }, // 2610922874
		{ &Z_Construct_UFunction_AWhiteChessFigure_TurnOffLocations, "TurnOffLocations" }, // 1730683453
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteChessFigure_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteChessFigure_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "WhiteChessFigure.h" },
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_Mesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "WhiteChessFigure" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWhiteChessFigure, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_Mesh_MetaData), Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_Mesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_Material_MetaData[] = {
		{ "Category", "Materials" },
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWhiteChessFigure, Material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_Material_MetaData), Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_Material_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_AttackColor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "WhiteChessFigure" },
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_AttackColor = { "AttackColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWhiteChessFigure, AttackColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_AttackColor_MetaData), Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_AttackColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_UsualColor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "WhiteChessFigure" },
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_UsualColor = { "UsualColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWhiteChessFigure, UsualColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_UsualColor_MetaData), Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_UsualColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_moved_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "WhiteChessFigure" },
		{ "ModuleRelativePath", "WhiteChessFigure.h" },
	};
#endif
	void Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_moved_SetBit(void* Obj)
	{
		((AWhiteChessFigure*)Obj)->moved = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_moved = { "moved", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AWhiteChessFigure), &Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_moved_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_moved_MetaData), Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_moved_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWhiteChessFigure_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_Mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_Material,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_AttackColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_UsualColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteChessFigure_Statics::NewProp_moved,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWhiteChessFigure_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWhiteChessFigure>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWhiteChessFigure_Statics::ClassParams = {
		&AWhiteChessFigure::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AWhiteChessFigure_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteChessFigure_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteChessFigure_Statics::Class_MetaDataParams), Z_Construct_UClass_AWhiteChessFigure_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteChessFigure_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AWhiteChessFigure()
	{
		if (!Z_Registration_Info_UClass_AWhiteChessFigure.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWhiteChessFigure.OuterSingleton, Z_Construct_UClass_AWhiteChessFigure_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWhiteChessFigure.OuterSingleton;
	}
	template<> CHESS_API UClass* StaticClass<AWhiteChessFigure>()
	{
		return AWhiteChessFigure::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWhiteChessFigure);
	AWhiteChessFigure::~AWhiteChessFigure() {}
	struct Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWhiteChessFigure, AWhiteChessFigure::StaticClass, TEXT("AWhiteChessFigure"), &Z_Registration_Info_UClass_AWhiteChessFigure, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWhiteChessFigure), 2910734332U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_2277276264(TEXT("/Script/Chess"),
		Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteChessFigure_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
