// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Chess/BlackSoldier.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBlackSoldier() {}
// Cross Module References
	CHESS_API UClass* Z_Construct_UClass_ABlackChessFigure();
	CHESS_API UClass* Z_Construct_UClass_ABlackKing_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_ABlackSoldier();
	CHESS_API UClass* Z_Construct_UClass_ABlackSoldier_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_UBlackSoldierChangeFigure_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Chess();
// End Cross Module References
	DEFINE_FUNCTION(ABlackSoldier::execWillOpenChack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->WillOpenChack();
		P_NATIVE_END;
	}
	void ABlackSoldier::StaticRegisterNativesABlackSoldier()
	{
		UClass* Class = ABlackSoldier::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "WillOpenChack", &ABlackSoldier::execWillOpenChack },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics
	{
		struct BlackSoldier_eventWillOpenChack_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((BlackSoldier_eventWillOpenChack_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(BlackSoldier_eventWillOpenChack_Parms), &Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "BlackSoldier.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABlackSoldier, nullptr, "WillOpenChack", nullptr, nullptr, Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::PropPointers), sizeof(Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::BlackSoldier_eventWillOpenChack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::Function_MetaDataParams), Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::BlackSoldier_eventWillOpenChack_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ABlackSoldier_WillOpenChack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ABlackSoldier_WillOpenChack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABlackSoldier);
	UClass* Z_Construct_UClass_ABlackSoldier_NoRegister()
	{
		return ABlackSoldier::StaticClass();
	}
	struct Z_Construct_UClass_ABlackSoldier_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_index_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_index;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BlackKing_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_BlackKing;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChangeSoldierRef_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_ChangeSoldierRef;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABlackSoldier_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABlackChessFigure,
		(UObject* (*)())Z_Construct_UPackage__Script_Chess,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackSoldier_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ABlackSoldier_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABlackSoldier_WillOpenChack, "WillOpenChack" }, // 3922961438
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackSoldier_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackSoldier_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BlackSoldier.h" },
		{ "ModuleRelativePath", "BlackSoldier.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackSoldier_Statics::NewProp_index_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackSoldier" },
		{ "ModuleRelativePath", "BlackSoldier.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ABlackSoldier_Statics::NewProp_index = { "index", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackSoldier, index), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackSoldier_Statics::NewProp_index_MetaData), Z_Construct_UClass_ABlackSoldier_Statics::NewProp_index_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackSoldier_Statics::NewProp_BlackKing_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackSoldier" },
		{ "ModuleRelativePath", "BlackSoldier.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ABlackSoldier_Statics::NewProp_BlackKing = { "BlackKing", nullptr, (EPropertyFlags)0x0044000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackSoldier, BlackKing), Z_Construct_UClass_ABlackKing_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackSoldier_Statics::NewProp_BlackKing_MetaData), Z_Construct_UClass_ABlackSoldier_Statics::NewProp_BlackKing_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackSoldier_Statics::NewProp_ChangeSoldierRef_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "BlackSoldier" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BlackSoldier.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ABlackSoldier_Statics::NewProp_ChangeSoldierRef = { "ChangeSoldierRef", nullptr, (EPropertyFlags)0x001400000008000c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackSoldier, ChangeSoldierRef), Z_Construct_UClass_UBlackSoldierChangeFigure_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackSoldier_Statics::NewProp_ChangeSoldierRef_MetaData), Z_Construct_UClass_ABlackSoldier_Statics::NewProp_ChangeSoldierRef_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABlackSoldier_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackSoldier_Statics::NewProp_index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackSoldier_Statics::NewProp_BlackKing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackSoldier_Statics::NewProp_ChangeSoldierRef,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABlackSoldier_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABlackSoldier>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABlackSoldier_Statics::ClassParams = {
		&ABlackSoldier::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABlackSoldier_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABlackSoldier_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackSoldier_Statics::Class_MetaDataParams), Z_Construct_UClass_ABlackSoldier_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackSoldier_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ABlackSoldier()
	{
		if (!Z_Registration_Info_UClass_ABlackSoldier.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABlackSoldier.OuterSingleton, Z_Construct_UClass_ABlackSoldier_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABlackSoldier.OuterSingleton;
	}
	template<> CHESS_API UClass* StaticClass<ABlackSoldier>()
	{
		return ABlackSoldier::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABlackSoldier);
	ABlackSoldier::~ABlackSoldier() {}
	struct Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackSoldier_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackSoldier_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABlackSoldier, ABlackSoldier::StaticClass, TEXT("ABlackSoldier"), &Z_Registration_Info_UClass_ABlackSoldier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABlackSoldier), 805027278U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackSoldier_h_1280085672(TEXT("/Script/Chess"),
		Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackSoldier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackSoldier_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
