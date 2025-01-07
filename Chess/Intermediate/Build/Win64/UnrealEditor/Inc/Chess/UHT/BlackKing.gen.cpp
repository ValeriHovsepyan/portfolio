// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Chess/BlackKing.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBlackKing() {}
// Cross Module References
	CHESS_API UClass* Z_Construct_UClass_ABlackChessFigure();
	CHESS_API UClass* Z_Construct_UClass_ABlackElephant_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_ABlackKing();
	CHESS_API UClass* Z_Construct_UClass_ABlackKing_NoRegister();
	CHESS_API UClass* Z_Construct_UClass_AWhiteChessFigure_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	UPackage* Z_Construct_UPackage__Script_Chess();
// End Cross Module References
	void ABlackKing::StaticRegisterNativesABlackKing()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ABlackKing);
	UClass* Z_Construct_UClass_ABlackKing_NoRegister()
	{
		return ABlackKing::StaticClass();
	}
	struct Z_Construct_UClass_ABlackKing_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WhiteFigures_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WhiteFigures_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_WhiteFigures;
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
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NumberOfMovesUnderAttack_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_NumberOfMovesUnderAttack;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABlackKing_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABlackChessFigure,
		(UObject* (*)())Z_Construct_UPackage__Script_Chess,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackKing_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackKing_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "BlackKing.h" },
		{ "ModuleRelativePath", "BlackKing.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABlackKing_Statics::NewProp_WhiteFigures_Inner = { "WhiteFigures", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AWhiteChessFigure_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackKing_Statics::NewProp_WhiteFigures_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackKing" },
		{ "ModuleRelativePath", "BlackKing.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABlackKing_Statics::NewProp_WhiteFigures = { "WhiteFigures", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackKing, WhiteFigures), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackKing_Statics::NewProp_WhiteFigures_MetaData), Z_Construct_UClass_ABlackKing_Statics::NewProp_WhiteFigures_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackKing_Statics::NewProp_RightElephant_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackKing" },
		{ "ModuleRelativePath", "BlackKing.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ABlackKing_Statics::NewProp_RightElephant = { "RightElephant", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackKing, RightElephant), Z_Construct_UClass_ABlackElephant_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackKing_Statics::NewProp_RightElephant_MetaData), Z_Construct_UClass_ABlackKing_Statics::NewProp_RightElephant_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackKing_Statics::NewProp_LeftElephant_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackKing" },
		{ "ModuleRelativePath", "BlackKing.h" },
	};
#endif
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UClass_ABlackKing_Statics::NewProp_LeftElephant = { "LeftElephant", nullptr, (EPropertyFlags)0x0024080000000005, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackKing, LeftElephant), Z_Construct_UClass_ABlackElephant_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackKing_Statics::NewProp_LeftElephant_MetaData), Z_Construct_UClass_ABlackKing_Statics::NewProp_LeftElephant_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABlackKing_Statics::NewProp_PossibleAttackDirections_Inner = { "PossibleAttackDirections", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackKing_Statics::NewProp_PossibleAttackDirections_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackKing" },
		{ "ModuleRelativePath", "BlackKing.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ABlackKing_Statics::NewProp_PossibleAttackDirections = { "PossibleAttackDirections", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackKing, PossibleAttackDirections), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackKing_Statics::NewProp_PossibleAttackDirections_MetaData), Z_Construct_UClass_ABlackKing_Statics::NewProp_PossibleAttackDirections_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackKing_Statics::NewProp_IsUnderAttack_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackKing" },
		{ "ModuleRelativePath", "BlackKing.h" },
	};
#endif
	void Z_Construct_UClass_ABlackKing_Statics::NewProp_IsUnderAttack_SetBit(void* Obj)
	{
		((ABlackKing*)Obj)->IsUnderAttack = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABlackKing_Statics::NewProp_IsUnderAttack = { "IsUnderAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ABlackKing), &Z_Construct_UClass_ABlackKing_Statics::NewProp_IsUnderAttack_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackKing_Statics::NewProp_IsUnderAttack_MetaData), Z_Construct_UClass_ABlackKing_Statics::NewProp_IsUnderAttack_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABlackKing_Statics::NewProp_NumberOfMovesUnderAttack_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "BlackKing" },
		{ "ModuleRelativePath", "BlackKing.h" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ABlackKing_Statics::NewProp_NumberOfMovesUnderAttack = { "NumberOfMovesUnderAttack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ABlackKing, NumberOfMovesUnderAttack), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackKing_Statics::NewProp_NumberOfMovesUnderAttack_MetaData), Z_Construct_UClass_ABlackKing_Statics::NewProp_NumberOfMovesUnderAttack_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABlackKing_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackKing_Statics::NewProp_WhiteFigures_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackKing_Statics::NewProp_WhiteFigures,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackKing_Statics::NewProp_RightElephant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackKing_Statics::NewProp_LeftElephant,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackKing_Statics::NewProp_PossibleAttackDirections_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackKing_Statics::NewProp_PossibleAttackDirections,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackKing_Statics::NewProp_IsUnderAttack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABlackKing_Statics::NewProp_NumberOfMovesUnderAttack,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABlackKing_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABlackKing>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ABlackKing_Statics::ClassParams = {
		&ABlackKing::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABlackKing_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABlackKing_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackKing_Statics::Class_MetaDataParams), Z_Construct_UClass_ABlackKing_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ABlackKing_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ABlackKing()
	{
		if (!Z_Registration_Info_UClass_ABlackKing.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ABlackKing.OuterSingleton, Z_Construct_UClass_ABlackKing_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ABlackKing.OuterSingleton;
	}
	template<> CHESS_API UClass* StaticClass<ABlackKing>()
	{
		return ABlackKing::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABlackKing);
	ABlackKing::~ABlackKing() {}
	struct Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ABlackKing, ABlackKing::StaticClass, TEXT("ABlackKing"), &Z_Registration_Info_UClass_ABlackKing, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ABlackKing), 1176416831U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_496052193(TEXT("/Script/Chess"),
		Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_BlackKing_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
