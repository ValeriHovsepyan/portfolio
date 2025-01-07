// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Chess/WhiteElephant.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWhiteElephant() {}
// Cross Module References
	CHESS_API UClass* Z_Construct_UClass_AWhiteChessFigure();
	CHESS_API UClass* Z_Construct_UClass_AWhiteElephant();
	CHESS_API UClass* Z_Construct_UClass_AWhiteElephant_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_AWhiteKing_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Chess();
// End Cross Module References
	DEFINE_FUNCTION(AWhiteElephant::execWillOpenChack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->WillOpenChack();
		P_NATIVE_END;
	}
	void AWhiteElephant::StaticRegisterNativesAWhiteElephant()
	{
		UClass* Class = AWhiteElephant::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "WillOpenChack", &AWhiteElephant::execWillOpenChack },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics
	{
		struct WhiteElephant_eventWillOpenChack_Parms
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
	void Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WhiteElephant_eventWillOpenChack_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(WhiteElephant_eventWillOpenChack_Parms), &Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "WhiteElephant.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWhiteElephant, nullptr, "WillOpenChack", nullptr, nullptr, Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::PropPointers), sizeof(Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::WhiteElephant_eventWillOpenChack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::Function_MetaDataParams), Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::WhiteElephant_eventWillOpenChack_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AWhiteElephant_WillOpenChack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AWhiteElephant_WillOpenChack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWhiteElephant);
	UClass* Z_Construct_UClass_AWhiteElephant_NoRegister()
	{
		return AWhiteElephant::StaticClass();
	}
	struct Z_Construct_UClass_AWhiteElephant_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WhiteKing_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_WhiteKing;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWhiteElephant_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWhiteChessFigure,
		(UObject* (*)())Z_Construct_UPackage__Script_Chess,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteElephant_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AWhiteElephant_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AWhiteElephant_WillOpenChack, "WillOpenChack" }, // 2246537555
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteElephant_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteElephant_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "WhiteElephant.h" },
		{ "ModuleRelativePath", "WhiteElephant.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteElephant_Statics::NewProp_WhiteKing_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "WhiteElephant" },
		{ "ModuleRelativePath", "WhiteElephant.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AWhiteElephant_Statics::NewProp_WhiteKing = { "WhiteKing", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWhiteElephant, WhiteKing), Z_Construct_UClass_AWhiteKing_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteElephant_Statics::NewProp_WhiteKing_MetaData), Z_Construct_UClass_AWhiteElephant_Statics::NewProp_WhiteKing_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWhiteElephant_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteElephant_Statics::NewProp_WhiteKing,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWhiteElephant_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWhiteElephant>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWhiteElephant_Statics::ClassParams = {
		&AWhiteElephant::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AWhiteElephant_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteElephant_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteElephant_Statics::Class_MetaDataParams), Z_Construct_UClass_AWhiteElephant_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteElephant_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AWhiteElephant()
	{
		if (!Z_Registration_Info_UClass_AWhiteElephant.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWhiteElephant.OuterSingleton, Z_Construct_UClass_AWhiteElephant_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWhiteElephant.OuterSingleton;
	}
	template<> CHESS_API UClass* StaticClass<AWhiteElephant>()
	{
		return AWhiteElephant::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWhiteElephant);
	AWhiteElephant::~AWhiteElephant() {}
	struct Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteElephant_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteElephant_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWhiteElephant, AWhiteElephant::StaticClass, TEXT("AWhiteElephant"), &Z_Registration_Info_UClass_AWhiteElephant, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWhiteElephant), 1205637697U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteElephant_h_545905532(TEXT("/Script/Chess"),
		Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteElephant_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteElephant_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
