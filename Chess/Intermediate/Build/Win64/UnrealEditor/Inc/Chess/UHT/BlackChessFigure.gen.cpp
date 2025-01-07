// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Chess/BlackChessFigure.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBlackChessFigure() {}
// Cross Module References
	CHESS_API UClass* Z_Construct_UClass_ABlackChessFigure();
	CHESS_API UClass* Z_Construct_UClass_ABlackChessFigure_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_AWhiteChessFigure_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UMaterialInterface_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Chess();
// End Cross Module References
	DEFINE_FUNCTION(ABlackChessFigure::execAttack)
	{
		P_GET_OBJECT(AWhiteChessFigure,Z_Param_BlackFigure);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Attack(Z_Param_BlackFigure);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABlackChessFigure::execCanAttack)
	{
		P_GET_STRUCT(FVector,Z_Param_Direction);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanAttack(Z_Param_Direction);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABlackChessFigure::execGetMesh)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UStaticMeshComponent**)Z_Param__Result=P_THIS->GetMesh();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABlackChessFigure::execmove)
	{
		P_GET_STRUCT(FVector,Z_Param_Direction);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->move(Z_Param_Direction);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABlackChessFigure::execTurnOffLocations)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TurnOffLocations();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABlackChessFigure::execShowLocations)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ShowLocations();
		P_NATIVE_END;
	}
	void ABlackChessFigure::StaticRegisterNativesABlackChessFigure()
	{
		UClass* Class = ABlackChessFigure::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Attack", &ABlackChessFigure::execAttack },
			{ "CanAttack", &ABlackChessFigure::execCanAttack },
			{ "GetMesh", &ABlackChessFigure::execGetMesh },
			{ "move", &ABlackChessFigure::execmove },
			{ "ShowLocations", &ABlackChessFigure::execShowLocations },
			{ "TurnOffLocations", &ABlackChessFigure::execTurnOffLocations },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABlackChessFigure_Attack_Statics
	{
		struct BlackChessFigure_eventAttack_Parms
		{
			AWhiteChessFigure* BlackFigure;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BlackFigure;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::NewProp_BlackFigure = { "BlackFigure", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlackChessFigure_eventAttack_Parms, BlackFigure), Z_Construct_UClass_AWhiteChessFigure_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::NewProp_BlackFigure,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABlackChessFigure, nullptr, "Attack", nullptr, nullptr, Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::BlackChessFigure_eventAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::BlackChessFigure_eventAttack_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ABlackChessFigure_Attack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABlackChessFigure_Attack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics
	{
		struct BlackChessFigure_eventCanAttack_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlackChessFigure_eventCanAttack_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((BlackChessFigure_eventCanAttack_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BlackChessFigure_eventCanAttack_Parms), &Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::NewProp_Direction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABlackChessFigure, nullptr, "CanAttack", nullptr, nullptr, Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::BlackChessFigure_eventCanAttack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::BlackChessFigure_eventCanAttack_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ABlackChessFigure_CanAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABlackChessFigure_CanAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics
	{
		struct BlackChessFigure_eventGetMesh_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlackChessFigure_eventGetMesh_Parms, ReturnValue), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABlackChessFigure, nullptr, "GetMesh", nullptr, nullptr, Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::BlackChessFigure_eventGetMesh_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::BlackChessFigure_eventGetMesh_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ABlackChessFigure_GetMesh()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABlackChessFigure_GetMesh_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABlackChessFigure_move_Statics
	{
		struct BlackChessFigure_eventmove_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABlackChessFigure_move_Statics::NewProp_Direction = { "Direction", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(BlackChessFigure_eventmove_Parms, Direction), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABlackChessFigure_move_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABlackChessFigure_move_Statics::NewProp_Direction,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABlackChessFigure_move_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABlackChessFigure_move_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABlackChessFigure, nullptr, "move", nullptr, nullptr, Z_Construct_UFunction_ABlackChessFigure_move_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_move_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABlackChessFigure_move_Statics::BlackChessFigure_eventmove_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_move_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABlackChessFigure_move_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_move_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ABlackChessFigure_move_Statics::BlackChessFigure_eventmove_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ABlackChessFigure_move()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABlackChessFigure_move_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABlackChessFigure_ShowLocations_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABlackChessFigure_ShowLocations_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABlackChessFigure_ShowLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABlackChessFigure, nullptr, "ShowLocations", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_ShowLocations_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABlackChessFigure_ShowLocations_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ABlackChessFigure_ShowLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABlackChessFigure_ShowLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABlackChessFigure_TurnOffLocations_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABlackChessFigure_TurnOffLocations_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABlackChessFigure_TurnOffLocations_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABlackChessFigure, nullptr, "TurnOffLocations", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackChessFigure_TurnOffLocations_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABlackChessFigure_TurnOffLocations_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ABlackChessFigure_TurnOffLocations()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABlackChessFigure_TurnOffLocations_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABlackChessFigure);
	UClass* Z_Construct_UClass_ABlackChessFigure_NoRegister()
	{
		return ABlackChessFigure::StaticClass();
	}
	struct Z_Construct_UClass_ABlackChessFigure_Statics
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
	UObject* (*const Z_Construct_UClass_ABlackChessFigure_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Chess,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackChessFigure_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ABlackChessFigure_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABlackChessFigure_Attack, "Attack" }, // 3926790739
		{ &Z_Construct_UFunction_ABlackChessFigure_CanAttack, "CanAttack" }, // 1407778058
		{ &Z_Construct_UFunction_ABlackChessFigure_GetMesh, "GetMesh" }, // 2752613374
		{ &Z_Construct_UFunction_ABlackChessFigure_move, "move" }, // 3465204372
		{ &Z_Construct_UFunction_ABlackChessFigure_ShowLocations, "ShowLocations" }, // 4139514654
		{ &Z_Construct_UFunction_ABlackChessFigure_TurnOffLocations, "TurnOffLocations" }, // 2767440375
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackChessFigure_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackChessFigure_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BlackChessFigure.h" },
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_Mesh_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackChessFigure" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x00240800000a001d, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackChessFigure, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_Mesh_MetaData), Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_Mesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_Material_MetaData[] = {
		{ "Category", "Materials" },
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_Material = { "Material", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackChessFigure, Material), Z_Construct_UClass_UMaterialInterface_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_Material_MetaData), Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_Material_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_AttackColor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackChessFigure" },
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_AttackColor = { "AttackColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackChessFigure, AttackColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_AttackColor_MetaData), Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_AttackColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_UsualColor_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackChessFigure" },
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_UsualColor = { "UsualColor", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackChessFigure, UsualColor), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_UsualColor_MetaData), Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_UsualColor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_moved_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackChessFigure" },
		{ "ModuleRelativePath", "BlackChessFigure.h" },
	};
#endif
	void Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_moved_SetBit(void* Obj)
	{
		((ABlackChessFigure*)Obj)->moved = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_moved = { "moved", nullptr, (EPropertyFlags)0x0010000000020005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABlackChessFigure), &Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_moved_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_moved_MetaData), Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_moved_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABlackChessFigure_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_Mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_Material,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_AttackColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_UsualColor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackChessFigure_Statics::NewProp_moved,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABlackChessFigure_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABlackChessFigure>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABlackChessFigure_Statics::ClassParams = {
		&ABlackChessFigure::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABlackChessFigure_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABlackChessFigure_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackChessFigure_Statics::Class_MetaDataParams), Z_Construct_UClass_ABlackChessFigure_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackChessFigure_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ABlackChessFigure()
	{
		if (!Z_Registration_Info_UClass_ABlackChessFigure.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABlackChessFigure.OuterSingleton, Z_Construct_UClass_ABlackChessFigure_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABlackChessFigure.OuterSingleton;
	}
	template<> CHESS_API UClass* StaticClass<ABlackChessFigure>()
	{
		return ABlackChessFigure::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABlackChessFigure);
	ABlackChessFigure::~ABlackChessFigure() {}
	struct Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABlackChessFigure, ABlackChessFigure::StaticClass, TEXT("ABlackChessFigure"), &Z_Registration_Info_UClass_ABlackChessFigure, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABlackChessFigure), 3483042131U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_1242578582(TEXT("/Script/Chess"),
		Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackChessFigure_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
