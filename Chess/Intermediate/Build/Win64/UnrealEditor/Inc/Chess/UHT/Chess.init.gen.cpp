// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChess_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Chess;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Chess()
	{
		if (!Z_Registration_Info_UPackage__Script_Chess.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Chess",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0x922CFACC,
				0x594CF5FA,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Chess.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Chess.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Chess(Z_Construct_UPackage__Script_Chess, TEXT("/Script/Chess"), Z_Registration_Info_UPackage__Script_Chess, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x922CFACC, 0x594CF5FA));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
