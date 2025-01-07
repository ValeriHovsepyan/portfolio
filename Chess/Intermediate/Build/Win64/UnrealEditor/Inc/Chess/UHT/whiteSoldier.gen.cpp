// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Chess/whiteSoldier.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodewhiteSoldier() {}
// Cross Module References
	CHESS_API UClass* Z_Construct_UClass_AWhiteChessFigure();
	CHESS_API UClass* Z_Construct_UClass_AWhiteKing_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_AwhiteSoldier();
	CHESS_API UClass* Z_Construct_UClass_AwhiteSoldier_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_UChangeFidureWidget_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Chess();
// End Cross Module References
	DEFINE_FUNCTION(AwhiteSoldier::execWillOpenChack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->WillOpenChack();
		P_NATIVE_END;
	}
	void AwhiteSoldier::StaticRegisterNativesAwhiteSoldier()
	{
		UClass* Class = AwhiteSoldier::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "WillOpenChack", &AwhiteSoldier::execWillOpenChack },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics
	{
		struct whiteSoldier_eventWillOpenChack_Parms
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
	void Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((whiteSoldier_eventWillOpenChack_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(whiteSoldier_eventWillOpenChack_Parms), &Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "whiteSoldier.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AwhiteSoldier, nullptr, "WillOpenChack", nullptr, nullptr, Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::PropPointers), sizeof(Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::whiteSoldier_eventWillOpenChack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::whiteSoldier_eventWillOpenChack_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AwhiteSoldier_WillOpenChack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AwhiteSoldier_WillOpenChack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AwhiteSoldier);
	UClass* Z_Construct_UClass_AwhiteSoldier_NoRegister()
	{
		return AwhiteSoldier::StaticClass();
	}
	struct Z_Construct_UClass_AwhiteSoldier_Statics
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
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WhiteKing_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_WhiteKing;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ChangeSoldierRef_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_ChangeSoldierRef;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AwhiteSoldier_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWhiteChessFigure,
		(UObject* (*)())Z_Construct_UPackage__Script_Chess,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AwhiteSoldier_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AwhiteSoldier_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AwhiteSoldier_WillOpenChack, "WillOpenChack" }, // 98267172
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AwhiteSoldier_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AwhiteSoldier_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "whiteSoldier.h" },
		{ "ModuleRelativePath", "whiteSoldier.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_index_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "whiteSoldier" },
		{ "ModuleRelativePath", "whiteSoldier.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_index = { "index", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AwhiteSoldier, index), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_index_MetaData), Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_index_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_WhiteKing_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "whiteSoldier" },
		{ "ModuleRelativePath", "whiteSoldier.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_WhiteKing = { "WhiteKing", nullptr, (EPropertyFlags)0x0044000000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AwhiteSoldier, WhiteKing), Z_Construct_UClass_AWhiteKing_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_WhiteKing_MetaData), Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_WhiteKing_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_ChangeSoldierRef_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "whiteSoldier" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "whiteSoldier.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_ChangeSoldierRef = { "ChangeSoldierRef", nullptr, (EPropertyFlags)0x001400000008000c, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AwhiteSoldier, ChangeSoldierRef), Z_Construct_UClass_UChangeFidureWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_ChangeSoldierRef_MetaData), Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_ChangeSoldierRef_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AwhiteSoldier_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_index,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_WhiteKing,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AwhiteSoldier_Statics::NewProp_ChangeSoldierRef,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AwhiteSoldier_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AwhiteSoldier>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AwhiteSoldier_Statics::ClassParams = {
		&AwhiteSoldier::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AwhiteSoldier_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AwhiteSoldier_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AwhiteSoldier_Statics::Class_MetaDataParams), Z_Construct_UClass_AwhiteSoldier_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AwhiteSoldier_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AwhiteSoldier()
	{
		if (!Z_Registration_Info_UClass_AwhiteSoldier.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AwhiteSoldier.OuterSingleton, Z_Construct_UClass_AwhiteSoldier_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AwhiteSoldier.OuterSingleton;
	}
	template<> CHESS_API UClass* StaticClass<AwhiteSoldier>()
	{
		return AwhiteSoldier::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AwhiteSoldier);
	AwhiteSoldier::~AwhiteSoldier() {}
	struct Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_whiteSoldier_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_whiteSoldier_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AwhiteSoldier, AwhiteSoldier::StaticClass, TEXT("AwhiteSoldier"), &Z_Registration_Info_UClass_AwhiteSoldier, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AwhiteSoldier), 1623857450U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_whiteSoldier_h_1272177584(TEXT("/Script/Chess"),
		Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_whiteSoldier_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_whiteSoldier_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
