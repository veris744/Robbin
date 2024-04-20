// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robbin/Characters/Player/ScammerCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeScammerCharacter() {}
// Cross Module References
	ROBBIN_API UClass* Z_Construct_UClass_APlayableCharacter();
	ROBBIN_API UClass* Z_Construct_UClass_AScammerCharacter();
	ROBBIN_API UClass* Z_Construct_UClass_AScammerCharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Robbin();
// End Cross Module References
	void AScammerCharacter::StaticRegisterNativesAScammerCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AScammerCharacter);
	UClass* Z_Construct_UClass_AScammerCharacter_NoRegister()
	{
		return AScammerCharacter::StaticClass();
	}
	struct Z_Construct_UClass_AScammerCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AScammerCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayableCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Robbin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AScammerCharacter_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AScammerCharacter_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/Player/ScammerCharacter.h" },
		{ "ModuleRelativePath", "Characters/Player/ScammerCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AScammerCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AScammerCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AScammerCharacter_Statics::ClassParams = {
		&AScammerCharacter::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AScammerCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_AScammerCharacter_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AScammerCharacter()
	{
		if (!Z_Registration_Info_UClass_AScammerCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AScammerCharacter.OuterSingleton, Z_Construct_UClass_AScammerCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AScammerCharacter.OuterSingleton;
	}
	template<> ROBBIN_API UClass* StaticClass<AScammerCharacter>()
	{
		return AScammerCharacter::StaticClass();
	}
	AScammerCharacter::AScammerCharacter() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AScammerCharacter);
	AScammerCharacter::~AScammerCharacter() {}
	struct Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_Player_ScammerCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_Player_ScammerCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AScammerCharacter, AScammerCharacter::StaticClass, TEXT("AScammerCharacter"), &Z_Registration_Info_UClass_AScammerCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AScammerCharacter), 1514223432U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_Player_ScammerCharacter_h_2833020920(TEXT("/Script/Robbin"),
		Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_Player_ScammerCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_Player_ScammerCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
