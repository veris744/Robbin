// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robbin/RobbinGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeRobbinGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	ROBBIN_API UClass* Z_Construct_UClass_ARobbinGameMode();
	ROBBIN_API UClass* Z_Construct_UClass_ARobbinGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Robbin();
// End Cross Module References
	void ARobbinGameMode::StaticRegisterNativesARobbinGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ARobbinGameMode);
	UClass* Z_Construct_UClass_ARobbinGameMode_NoRegister()
	{
		return ARobbinGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ARobbinGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ARobbinGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Robbin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ARobbinGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ARobbinGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "RobbinGameMode.h" },
		{ "ModuleRelativePath", "RobbinGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ARobbinGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARobbinGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ARobbinGameMode_Statics::ClassParams = {
		&ARobbinGameMode::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ARobbinGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ARobbinGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ARobbinGameMode()
	{
		if (!Z_Registration_Info_UClass_ARobbinGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARobbinGameMode.OuterSingleton, Z_Construct_UClass_ARobbinGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ARobbinGameMode.OuterSingleton;
	}
	template<> ROBBIN_API UClass* StaticClass<ARobbinGameMode>()
	{
		return ARobbinGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ARobbinGameMode);
	ARobbinGameMode::~ARobbinGameMode() {}
	struct Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_RobbinGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_RobbinGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ARobbinGameMode, ARobbinGameMode::StaticClass, TEXT("ARobbinGameMode"), &Z_Registration_Info_UClass_ARobbinGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARobbinGameMode), 3074734205U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_RobbinGameMode_h_3405934680(TEXT("/Script/Robbin"),
		Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_RobbinGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_RobbinGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
