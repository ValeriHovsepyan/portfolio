// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Chess/BlackSoldierChangeFigure.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBlackSoldierChangeFigure() {}
// Cross Module References
	CHESS_API UClass* Z_Construct_UClass_ABlackSoldier_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_UBlackSoldierChangeFigure();
	CHESS_API UClass* Z_Construct_UClass_UBlackSoldierChangeFigure_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_Chess();
// End Cross Module References
	void UBlackSoldierChangeFigure::StaticRegisterNativesUBlackSoldierChangeFigure()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UBlackSoldierChangeFigure);
	UClass* Z_Construct_UClass_UBlackSoldierChangeFigure_NoRegister()
	{
		return UBlackSoldierChangeFigure::StaticClass();
	}
	struct Z_Construct_UClass_UBlackSoldierChangeFigure_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Soldier_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Soldier;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_Chess,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BlackSoldierChangeFigure.h" },
		{ "ModuleRelativePath", "BlackSoldierChangeFigure.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::NewProp_Soldier_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackSoldierChangeFigure" },
		{ "ModuleRelativePath", "BlackSoldierChangeFigure.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::NewProp_Soldier = { "Soldier", nullptr, (EPropertyFlags)0x0040000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UBlackSoldierChangeFigure, Soldier), Z_Construct_UClass_ABlackSoldier_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::NewProp_Soldier_MetaData), Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::NewProp_Soldier_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::NewProp_Soldier,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UBlackSoldierChangeFigure>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::ClassParams = {
		&UBlackSoldierChangeFigure::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::Class_MetaDataParams), Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UBlackSoldierChangeFigure()
	{
		if (!Z_Registration_Info_UClass_UBlackSoldierChangeFigure.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UBlackSoldierChangeFigure.OuterSingleton, Z_Construct_UClass_UBlackSoldierChangeFigure_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UBlackSoldierChangeFigure.OuterSingleton;
	}
	template<> CHESS_API UClass* StaticClass<UBlackSoldierChangeFigure>()
	{
		return UBlackSoldierChangeFigure::StaticClass();
	}
	UBlackSoldierChangeFigure::UBlackSoldierChangeFigure(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UBlackSoldierChangeFigure);
	UBlackSoldierChangeFigure::~UBlackSoldierChangeFigure() {}
	struct Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackSoldierChangeFigure_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackSoldierChangeFigure_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UBlackSoldierChangeFigure, UBlackSoldierChangeFigure::StaticClass, TEXT("UBlackSoldierChangeFigure"), &Z_Registration_Info_UClass_UBlackSoldierChangeFigure, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UBlackSoldierChangeFigure), 3647494635U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackSoldierChangeFigure_h_708279050(TEXT("/Script/Chess"),
		Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackSoldierChangeFigure_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackSoldierChangeFigure_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
