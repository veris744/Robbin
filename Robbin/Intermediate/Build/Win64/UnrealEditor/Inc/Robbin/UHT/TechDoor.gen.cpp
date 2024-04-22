// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robbin/InteractiveActors/Doors/TechDoor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTechDoor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ROBBIN_API UClass* Z_Construct_UClass_ATechDoor();
	ROBBIN_API UClass* Z_Construct_UClass_ATechDoor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Robbin();
// End Cross Module References
	DEFINE_FUNCTION(ATechDoor::execClose)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Close();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ATechDoor::execOpen)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Open();
		P_NATIVE_END;
	}
	void ATechDoor::StaticRegisterNativesATechDoor()
	{
		UClass* Class = ATechDoor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Close", &ATechDoor::execClose },
			{ "Open", &ATechDoor::execOpen },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATechDoor_Close_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATechDoor_Close_Statics::Function_MetaDataParams[] = {
		{ "Category", "Robbing" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/TechDoor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATechDoor_Close_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATechDoor, nullptr, "Close", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATechDoor_Close_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATechDoor_Close_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ATechDoor_Close()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATechDoor_Close_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATechDoor_Open_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATechDoor_Open_Statics::Function_MetaDataParams[] = {
		{ "Category", "Robbing" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/TechDoor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ATechDoor_Open_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATechDoor, nullptr, "Open", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ATechDoor_Open_Statics::Function_MetaDataParams), Z_Construct_UFunction_ATechDoor_Open_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ATechDoor_Open()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ATechDoor_Open_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATechDoor);
	UClass* Z_Construct_UClass_ATechDoor_NoRegister()
	{
		return ATechDoor::StaticClass();
	}
	struct Z_Construct_UClass_ATechDoor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OutMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OutMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DoorMeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DoorMeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SceneComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SceneComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsOpen_MetaData[];
#endif
		static void NewProp_bIsOpen_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOpen;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OpenDistance_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_OpenDistance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATechDoor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Robbin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATechDoor_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ATechDoor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATechDoor_Close, "Close" }, // 3134196009
		{ &Z_Construct_UFunction_ATechDoor_Open, "Open" }, // 1425486643
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATechDoor_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATechDoor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InteractiveActors/Doors/TechDoor.h" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/TechDoor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATechDoor_Statics::NewProp_OutMeshComponent_MetaData[] = {
		{ "Category", "TechDoor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/TechDoor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATechDoor_Statics::NewProp_OutMeshComponent = { "OutMeshComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATechDoor, OutMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATechDoor_Statics::NewProp_OutMeshComponent_MetaData), Z_Construct_UClass_ATechDoor_Statics::NewProp_OutMeshComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATechDoor_Statics::NewProp_DoorMeshComponent_MetaData[] = {
		{ "Category", "TechDoor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/TechDoor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATechDoor_Statics::NewProp_DoorMeshComponent = { "DoorMeshComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATechDoor, DoorMeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATechDoor_Statics::NewProp_DoorMeshComponent_MetaData), Z_Construct_UClass_ATechDoor_Statics::NewProp_DoorMeshComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATechDoor_Statics::NewProp_SceneComponent_MetaData[] = {
		{ "Category", "TechDoor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/TechDoor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATechDoor_Statics::NewProp_SceneComponent = { "SceneComponent", nullptr, (EPropertyFlags)0x00400000000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATechDoor, SceneComponent), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATechDoor_Statics::NewProp_SceneComponent_MetaData), Z_Construct_UClass_ATechDoor_Statics::NewProp_SceneComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATechDoor_Statics::NewProp_bIsOpen_MetaData[] = {
		{ "Category", "Robbing" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/TechDoor.h" },
	};
#endif
	void Z_Construct_UClass_ATechDoor_Statics::NewProp_bIsOpen_SetBit(void* Obj)
	{
		((ATechDoor*)Obj)->bIsOpen = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATechDoor_Statics::NewProp_bIsOpen = { "bIsOpen", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ATechDoor), &Z_Construct_UClass_ATechDoor_Statics::NewProp_bIsOpen_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATechDoor_Statics::NewProp_bIsOpen_MetaData), Z_Construct_UClass_ATechDoor_Statics::NewProp_bIsOpen_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATechDoor_Statics::NewProp_OpenDistance_MetaData[] = {
		{ "Category", "Robbing" },
		{ "ModuleRelativePath", "InteractiveActors/Doors/TechDoor.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ATechDoor_Statics::NewProp_OpenDistance = { "OpenDistance", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATechDoor, OpenDistance), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATechDoor_Statics::NewProp_OpenDistance_MetaData), Z_Construct_UClass_ATechDoor_Statics::NewProp_OpenDistance_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATechDoor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATechDoor_Statics::NewProp_OutMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATechDoor_Statics::NewProp_DoorMeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATechDoor_Statics::NewProp_SceneComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATechDoor_Statics::NewProp_bIsOpen,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATechDoor_Statics::NewProp_OpenDistance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATechDoor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATechDoor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATechDoor_Statics::ClassParams = {
		&ATechDoor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ATechDoor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ATechDoor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATechDoor_Statics::Class_MetaDataParams), Z_Construct_UClass_ATechDoor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATechDoor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATechDoor()
	{
		if (!Z_Registration_Info_UClass_ATechDoor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATechDoor.OuterSingleton, Z_Construct_UClass_ATechDoor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATechDoor.OuterSingleton;
	}
	template<> ROBBIN_API UClass* StaticClass<ATechDoor>()
	{
		return ATechDoor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATechDoor);
	ATechDoor::~ATechDoor() {}
	struct Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATechDoor, ATechDoor::StaticClass, TEXT("ATechDoor"), &Z_Registration_Info_UClass_ATechDoor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATechDoor), 3537427037U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_966938897(TEXT("/Script/Robbin"),
		Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
