// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robbin/Characters/GenericCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGenericCharacter() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ROBBIN_API UClass* Z_Construct_UClass_AGenericCharacter();
	ROBBIN_API UClass* Z_Construct_UClass_AGenericCharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Robbin();
// End Cross Module References
	void AGenericCharacter::StaticRegisterNativesAGenericCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AGenericCharacter);
	UClass* Z_Construct_UClass_AGenericCharacter_NoRegister()
	{
		return AGenericCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AGenericCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGenericCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Robbin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AGenericCharacter_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGenericCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/GenericCharacter.h" },
		{ "ModuleRelativePath", "Characters/GenericCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGenericCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGenericCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AGenericCharacter_Statics::ClassParams = {
		&AGenericCharacter::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AGenericCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AGenericCharacter_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AGenericCharacter()
	{
		if (!Z_Registration_Info_UClass_AGenericCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGenericCharacter.OuterSingleton, Z_Construct_UClass_AGenericCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AGenericCharacter.OuterSingleton;
	}
	template<> ROBBIN_API UClass* StaticClass<AGenericCharacter>()
	{
		return AGenericCharacter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGenericCharacter);
	AGenericCharacter::~AGenericCharacter() {}
	struct Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_GenericCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_GenericCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AGenericCharacter, AGenericCharacter::StaticClass, TEXT("AGenericCharacter"), &Z_Registration_Info_UClass_AGenericCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGenericCharacter), 330333272U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_GenericCharacter_h_3375860232(TEXT("/Script/Robbin"),
		Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_GenericCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_GenericCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
