// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Chess/OnePeaceOfBoard.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOnePeaceOfBoard() {}
// Cross Module References
	CHESS_API UClass* Z_Construct_UClass_AOnePeaceOfBoard();
	CHESS_API UClass* Z_Construct_UClass_AOnePeaceOfBoard_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UPointLightComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Chess();
// End Cross Module References
	void AOnePeaceOfBoard::StaticRegisterNativesAOnePeaceOfBoard()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AOnePeaceOfBoard);
	UClass* Z_Construct_UClass_AOnePeaceOfBoard_NoRegister()
	{
		return AOnePeaceOfBoard::StaticClass();
	}
	struct Z_Construct_UClass_AOnePeaceOfBoard_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Light_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Light;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOnePeaceOfBoard_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Chess,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOnePeaceOfBoard_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOnePeaceOfBoard_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "OnePeaceOfBoard.h" },
		{ "ModuleRelativePath", "OnePeaceOfBoard.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOnePeaceOfBoard_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "OnePeaceOfBoard" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "OnePeaceOfBoard.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOnePeaceOfBoard_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x002008000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOnePeaceOfBoard, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOnePeaceOfBoard_Statics::NewProp_Mesh_MetaData), Z_Construct_UClass_AOnePeaceOfBoard_Statics::NewProp_Mesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOnePeaceOfBoard_Statics::NewProp_Light_MetaData[] = {
		{ "Category", "OnePeaceOfBoard" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "OnePeaceOfBoard.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AOnePeaceOfBoard_Statics::NewProp_Light = { "Light", nullptr, (EPropertyFlags)0x001000000008000d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AOnePeaceOfBoard, Light), Z_Construct_UClass_UPointLightComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOnePeaceOfBoard_Statics::NewProp_Light_MetaData), Z_Construct_UClass_AOnePeaceOfBoard_Statics::NewProp_Light_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AOnePeaceOfBoard_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOnePeaceOfBoard_Statics::NewProp_Mesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AOnePeaceOfBoard_Statics::NewProp_Light,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOnePeaceOfBoard_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOnePeaceOfBoard>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AOnePeaceOfBoard_Statics::ClassParams = {
		&AOnePeaceOfBoard::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AOnePeaceOfBoard_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AOnePeaceOfBoard_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AOnePeaceOfBoard_Statics::Class_MetaDataParams), Z_Construct_UClass_AOnePeaceOfBoard_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AOnePeaceOfBoard_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AOnePeaceOfBoard()
	{
		if (!Z_Registration_Info_UClass_AOnePeaceOfBoard.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AOnePeaceOfBoard.OuterSingleton, Z_Construct_UClass_AOnePeaceOfBoard_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AOnePeaceOfBoard.OuterSingleton;
	}
	template<> CHESS_API UClass* StaticClass<AOnePeaceOfBoard>()
	{
		return AOnePeaceOfBoard::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOnePeaceOfBoard);
	AOnePeaceOfBoard::~AOnePeaceOfBoard() {}
	struct Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_OnePeaceOfBoard_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_OnePeaceOfBoard_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AOnePeaceOfBoard, AOnePeaceOfBoard::StaticClass, TEXT("AOnePeaceOfBoard"), &Z_Registration_Info_UClass_AOnePeaceOfBoard, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AOnePeaceOfBoard), 318767176U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_OnePeaceOfBoard_h_661869513(TEXT("/Script/Chess"),
		Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_OnePeaceOfBoard_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_OnePeaceOfBoard_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
