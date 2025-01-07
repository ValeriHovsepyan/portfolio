// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Chess/WhiteKing.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWhiteKing() {}
// Cross Module References
	CHESS_API UClass* Z_Construct_UClass_ABlackChessFigure_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_AWhiteChessFigure();
	CHESS_API UClass* Z_Construct_UClass_AWhiteElephant_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_AWhiteKing();
	CHESS_API UClass* Z_Construct_UClass_AWhiteKing_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	UPackage* Z_Construct_UPackage__Script_Chess();
// End Cross Module References
	void AWhiteKing::StaticRegisterNativesAWhiteKing()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AWhiteKing);
	UClass* Z_Construct_UClass_AWhiteKing_NoRegister()
	{
		return AWhiteKing::StaticClass();
	}
	struct Z_Construct_UClass_AWhiteKing_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_BlackFigures_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BlackFigures_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_BlackFigures;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RightElephant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_RightElephant;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LeftElephant_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_LeftElephant;
		static const UECodeGen_Private::FStructPropertyParams NewProp_PossibleAttackDirections_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PossibleAttackDirections_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_PossibleAttackDirections;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsUnderAttack_MetaData[];
#endif
		static void NewProp_IsUnderAttack_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsUnderAttack;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWhiteKing_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AWhiteChessFigure,
		(UObject* (*)())Z_Construct_UPackage__Script_Chess,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteKing_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteKing_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "WhiteKing.h" },
		{ "ModuleRelativePath", "WhiteKing.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWhiteKing_Statics::NewProp_BlackFigures_Inner = { "BlackFigures", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ABlackChessFigure_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteKing_Statics::NewProp_BlackFigures_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "WhiteKing" },
		{ "ModuleRelativePath", "WhiteKing.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AWhiteKing_Statics::NewProp_BlackFigures = { "BlackFigures", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWhiteKing, BlackFigures), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteKing_Statics::NewProp_BlackFigures_MetaData), Z_Construct_UClass_AWhiteKing_Statics::NewProp_BlackFigures_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteKing_Statics::NewProp_RightElephant_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "WhiteKing" },
		{ "ModuleRelativePath", "WhiteKing.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AWhiteKing_Statics::NewProp_RightElephant = { "RightElephant", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWhiteKing, RightElephant), Z_Construct_UClass_AWhiteElephant_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteKing_Statics::NewProp_RightElephant_MetaData), Z_Construct_UClass_AWhiteKing_Statics::NewProp_RightElephant_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteKing_Statics::NewProp_LeftElephant_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "WhiteKing" },
		{ "ModuleRelativePath", "WhiteKing.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_AWhiteKing_Statics::NewProp_LeftElephant = { "LeftElephant", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWhiteKing, LeftElephant), Z_Construct_UClass_AWhiteElephant_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteKing_Statics::NewProp_LeftElephant_MetaData), Z_Construct_UClass_AWhiteKing_Statics::NewProp_LeftElephant_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_AWhiteKing_Statics::NewProp_PossibleAttackDirections_Inner = { "PossibleAttackDirections", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteKing_Statics::NewProp_PossibleAttackDirections_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "WhiteKing" },
		{ "ModuleRelativePath", "WhiteKing.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AWhiteKing_Statics::NewProp_PossibleAttackDirections = { "PossibleAttackDirections", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AWhiteKing, PossibleAttackDirections), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteKing_Statics::NewProp_PossibleAttackDirections_MetaData), Z_Construct_UClass_AWhiteKing_Statics::NewProp_PossibleAttackDirections_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWhiteKing_Statics::NewProp_IsUnderAttack_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "WhiteKing" },
		{ "ModuleRelativePath", "WhiteKing.h" },
	};
#endif
	void Z_Construct_UClass_AWhiteKing_Statics::NewProp_IsUnderAttack_SetBit(void* Obj)
	{
		((AWhiteKing*)Obj)->IsUnderAttack = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AWhiteKing_Statics::NewProp_IsUnderAttack = { "IsUnderAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AWhiteKing), &Z_Construct_UClass_AWhiteKing_Statics::NewProp_IsUnderAttack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteKing_Statics::NewProp_IsUnderAttack_MetaData), Z_Construct_UClass_AWhiteKing_Statics::NewProp_IsUnderAttack_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWhiteKing_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteKing_Statics::NewProp_BlackFigures_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteKing_Statics::NewProp_BlackFigures,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteKing_Statics::NewProp_RightElephant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteKing_Statics::NewProp_LeftElephant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteKing_Statics::NewProp_PossibleAttackDirections_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteKing_Statics::NewProp_PossibleAttackDirections,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWhiteKing_Statics::NewProp_IsUnderAttack,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWhiteKing_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWhiteKing>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AWhiteKing_Statics::ClassParams = {
		&AWhiteKing::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AWhiteKing_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteKing_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteKing_Statics::Class_MetaDataParams), Z_Construct_UClass_AWhiteKing_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AWhiteKing_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AWhiteKing()
	{
		if (!Z_Registration_Info_UClass_AWhiteKing.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AWhiteKing.OuterSingleton, Z_Construct_UClass_AWhiteKing_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AWhiteKing.OuterSingleton;
	}
	template<> CHESS_API UClass* StaticClass<AWhiteKing>()
	{
		return AWhiteKing::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWhiteKing);
	AWhiteKing::~AWhiteKing() {}
	struct Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKing_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKing_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AWhiteKing, AWhiteKing::StaticClass, TEXT("AWhiteKing"), &Z_Registration_Info_UClass_AWhiteKing, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AWhiteKing), 681371932U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKing_h_3344292749(TEXT("/Script/Chess"),
		Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKing_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_WhiteKing_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
