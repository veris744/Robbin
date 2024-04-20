// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRobbin_init() {}
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_Robbin;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_Robbin()
	{
		if (!Z_Registration_Info_UPackage__Script_Robbin.OuterSingleton)
		{
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/Robbin",
				nullptr,
				0,
				PKG_CompiledIn | 0x00000000,
				0xBE4F0921,
				0x47DA340B,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_Robbin.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_Robbin.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_Robbin(Z_Construct_UPackage__Script_Robbin, TEXT("/Script/Robbin"), Z_Registration_Info_UPackage__Script_Robbin, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xBE4F0921, 0x47DA340B));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
