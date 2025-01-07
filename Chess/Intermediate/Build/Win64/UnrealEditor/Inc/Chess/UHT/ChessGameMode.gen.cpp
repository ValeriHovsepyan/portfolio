// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Chess/ChessGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChessGameMode() {}
// Cross Module References
	CHESS_API UClass* Z_Construct_UClass_AChessGameMode();
	CHESS_API UClass* Z_Construct_UClass_AChessGameMode_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Chess();
// End Cross Module References
	void AChessGameMode::StaticRegisterNativesAChessGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AChessGameMode);
	UClass* Z_Construct_UClass_AChessGameMode_NoRegister()
	{
		return AChessGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AChessGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AChessGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Chess,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AChessGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AChessGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "ChessGameMode.h" },
		{ "ModuleRelativePath", "ChessGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AChessGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AChessGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AChessGameMode_Statics::ClassParams = {
		&AChessGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AChessGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_AChessGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AChessGameMode()
	{
		if (!Z_Registration_Info_UClass_AChessGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AChessGameMode.OuterSingleton, Z_Construct_UClass_AChessGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AChessGameMode.OuterSingleton;
	}
	template<> CHESS_API UClass* StaticClass<AChessGameMode>()
	{
		return AChessGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AChessGameMode);
	AChessGameMode::~AChessGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_ChessGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_ChessGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AChessGameMode, AChessGameMode::StaticClass, TEXT("AChessGameMode"), &Z_Registration_Info_UClass_AChessGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AChessGameMode), 1571880860U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_ChessGameMode_h_2960428108(TEXT("/Script/Chess"),
		Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_ChessGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_valho_MyProject_Chess_Source_Chess_ChessGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
