// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robbin/Characters/Player/SpyCharacter.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSpyCharacter() {}
// Cross Module References
	ROBBIN_API UClass* Z_Construct_UClass_APlayableCharacter();
	ROBBIN_API UClass* Z_Construct_UClass_ASpyCharacter();
	ROBBIN_API UClass* Z_Construct_UClass_ASpyCharacter_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Robbin();
// End Cross Module References
	void ASpyCharacter::StaticRegisterNativesASpyCharacter()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASpyCharacter);
	UClass* Z_Construct_UClass_ASpyCharacter_NoRegister()
	{
		return ASpyCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ASpyCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASpyCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayableCharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_Robbin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASpyCharacter_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASpyCharacter_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Characters/Player/SpyCharacter.h" },
		{ "ModuleRelativePath", "Characters/Player/SpyCharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASpyCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASpyCharacter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASpyCharacter_Statics::ClassParams = {
		&ASpyCharacter::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASpyCharacter_Statics::Class_MetaDataParams), Z_Construct_UClass_ASpyCharacter_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ASpyCharacter()
	{
		if (!Z_Registration_Info_UClass_ASpyCharacter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASpyCharacter.OuterSingleton, Z_Construct_UClass_ASpyCharacter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASpyCharacter.OuterSingleton;
	}
	template<> ROBBIN_API UClass* StaticClass<ASpyCharacter>()
	{
		return ASpyCharacter::StaticClass();
	}
	ASpyCharacter::ASpyCharacter() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASpyCharacter);
	ASpyCharacter::~ASpyCharacter() {}
	struct Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_Player_SpyCharacter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_Player_SpyCharacter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASpyCharacter, ASpyCharacter::StaticClass, TEXT("ASpyCharacter"), &Z_Registration_Info_UClass_ASpyCharacter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASpyCharacter), 4012342219U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_Player_SpyCharacter_h_1318514710(TEXT("/Script/Robbin"),
		Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_Player_SpyCharacter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_Characters_Player_SpyCharacter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
