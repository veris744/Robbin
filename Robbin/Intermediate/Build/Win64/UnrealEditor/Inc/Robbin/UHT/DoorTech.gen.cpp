// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robbin/InteractiveActors/Doors/DoorTech.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDoorTech() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ROBBIN_API UClass* Z_Construct_UClass_ADoorTech();
	ROBBIN_API UClass* Z_Construct_UClass_ADoorTech_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Robbin();
// End Cross Module References
	void ADoorTech::StaticRegisterNativesADoorTech()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADoorTech);
	UClass* Z_Construct_UClass_ADoorTech_NoRegister()
	{
		return ADoorTech::StaticClass();
	}
	struct Z_Construct_UClass_ADoorTech_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADoorTech_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Robbin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADoorTech_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADoorTech_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InteractiveActors/Doors/DoorTech.h" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/DoorTech.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADoorTech_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADoorTech>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADoorTech_Statics::ClassParams = {
		&ADoorTech::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADoorTech_Statics::Class_MetaDataParams), Z_Construct_UClass_ADoorTech_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ADoorTech()
	{
		if (!Z_Registration_Info_UClass_ADoorTech.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADoorTech.OuterSingleton, Z_Construct_UClass_ADoorTech_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADoorTech.OuterSingleton;
	}
	template<> ROBBIN_API UClass* StaticClass<ADoorTech>()
	{
		return ADoorTech::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADoorTech);
	ADoorTech::~ADoorTech() {}
	struct Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_DoorTech_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_DoorTech_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADoorTech, ADoorTech::StaticClass, TEXT("ADoorTech"), &Z_Registration_Info_UClass_ADoorTech, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADoorTech), 1090046205U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_DoorTech_h_923444414(TEXT("/Script/Robbin"),
		Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_DoorTech_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_DoorTech_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
