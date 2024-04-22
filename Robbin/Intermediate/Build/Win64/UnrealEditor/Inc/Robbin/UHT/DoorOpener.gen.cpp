// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robbin/InteractiveActors/Doors/DoorOpener.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeDoorOpener() {}
// Cross Module References
	ROBBIN_API UClass* Z_Construct_UClass_ADoorOpener();
	ROBBIN_API UClass* Z_Construct_UClass_ADoorOpener_NoRegister();
	ROBBIN_API UClass* Z_Construct_UClass_AInteractiveActor();
	ROBBIN_API UClass* Z_Construct_UClass_ATechDoor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Robbin();
// End Cross Module References
	void ADoorOpener::StaticRegisterNativesADoorOpener()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ADoorOpener);
	UClass* Z_Construct_UClass_ADoorOpener_NoRegister()
	{
		return ADoorOpener::StaticClass();
	}
	struct Z_Construct_UClass_ADoorOpener_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DoorsToOpen_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DoorsToOpen_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_DoorsToOpen;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ADoorOpener_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AInteractiveActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Robbin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADoorOpener_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADoorOpener_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "InteractiveActors/Doors/DoorOpener.h" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/DoorOpener.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ADoorOpener_Statics::NewProp_DoorsToOpen_Inner = { "DoorsToOpen", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ATechDoor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ADoorOpener_Statics::NewProp_DoorsToOpen_MetaData[] = {
		{ "Category", "Robbing" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/DoorOpener.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ADoorOpener_Statics::NewProp_DoorsToOpen = { "DoorsToOpen", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ADoorOpener, DoorsToOpen), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADoorOpener_Statics::NewProp_DoorsToOpen_MetaData), Z_Construct_UClass_ADoorOpener_Statics::NewProp_DoorsToOpen_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ADoorOpener_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADoorOpener_Statics::NewProp_DoorsToOpen_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ADoorOpener_Statics::NewProp_DoorsToOpen,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ADoorOpener_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ADoorOpener>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ADoorOpener_Statics::ClassParams = {
		&ADoorOpener::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ADoorOpener_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ADoorOpener_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ADoorOpener_Statics::Class_MetaDataParams), Z_Construct_UClass_ADoorOpener_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ADoorOpener_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ADoorOpener()
	{
		if (!Z_Registration_Info_UClass_ADoorOpener.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ADoorOpener.OuterSingleton, Z_Construct_UClass_ADoorOpener_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ADoorOpener.OuterSingleton;
	}
	template<> ROBBIN_API UClass* StaticClass<ADoorOpener>()
	{
		return ADoorOpener::StaticClass();
	}
	ADoorOpener::ADoorOpener() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ADoorOpener);
	ADoorOpener::~ADoorOpener() {}
	struct Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_DoorOpener_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_DoorOpener_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ADoorOpener, ADoorOpener::StaticClass, TEXT("ADoorOpener"), &Z_Registration_Info_UClass_ADoorOpener, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ADoorOpener), 469484482U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_DoorOpener_h_284246075(TEXT("/Script/Robbin"),
		Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_DoorOpener_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_DoorOpener_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
