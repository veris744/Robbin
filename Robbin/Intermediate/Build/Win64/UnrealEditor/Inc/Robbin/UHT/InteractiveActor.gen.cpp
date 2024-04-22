// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Robbin/InteractiveActors/InteractiveActor.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInteractiveActor() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ROBBIN_API UClass* Z_Construct_UClass_AInteractiveActor();
	ROBBIN_API UClass* Z_Construct_UClass_AInteractiveActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_Robbin();
// End Cross Module References
	DEFINE_FUNCTION(AInteractiveActor::execActivate)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Activate();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AInteractiveActor::execHovering)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Hovering();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AInteractiveActor::execOnEndMouseOver)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_TouchedComponent);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnEndMouseOver(Z_Param_TouchedComponent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AInteractiveActor::execOnBeginMouseOver)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_TouchedComponent);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnBeginMouseOver(Z_Param_TouchedComponent);
		P_NATIVE_END;
	}
	void AInteractiveActor::StaticRegisterNativesAInteractiveActor()
	{
		UClass* Class = AInteractiveActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Activate", &AInteractiveActor::execActivate },
			{ "Hovering", &AInteractiveActor::execHovering },
			{ "OnBeginMouseOver", &AInteractiveActor::execOnBeginMouseOver },
			{ "OnEndMouseOver", &AInteractiveActor::execOnEndMouseOver },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AInteractiveActor_Activate_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractiveActor_Activate_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "InteractiveActors/InteractiveActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractiveActor_Activate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractiveActor, nullptr, "Activate", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractiveActor_Activate_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInteractiveActor_Activate_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AInteractiveActor_Activate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInteractiveActor_Activate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AInteractiveActor_Hovering_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractiveActor_Hovering_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "InteractiveActors/InteractiveActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractiveActor_Hovering_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractiveActor, nullptr, "Hovering", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractiveActor_Hovering_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInteractiveActor_Hovering_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AInteractiveActor_Hovering()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInteractiveActor_Hovering_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics
	{
		struct InteractiveActor_eventOnBeginMouseOver_Parms
		{
			UPrimitiveComponent* TouchedComponent;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TouchedComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TouchedComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::NewProp_TouchedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::NewProp_TouchedComponent = { "TouchedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractiveActor_eventOnBeginMouseOver_Parms, TouchedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::NewProp_TouchedComponent_MetaData), Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::NewProp_TouchedComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::NewProp_TouchedComponent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "InteractiveActors/InteractiveActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractiveActor, nullptr, "OnBeginMouseOver", nullptr, nullptr, Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::PropPointers), sizeof(Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::InteractiveActor_eventOnBeginMouseOver_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::InteractiveActor_eventOnBeginMouseOver_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics
	{
		struct InteractiveActor_eventOnEndMouseOver_Parms
		{
			UPrimitiveComponent* TouchedComponent;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TouchedComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TouchedComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::NewProp_TouchedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::NewProp_TouchedComponent = { "TouchedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(InteractiveActor_eventOnEndMouseOver_Parms, TouchedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::NewProp_TouchedComponent_MetaData), Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::NewProp_TouchedComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::NewProp_TouchedComponent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "InteractiveActors/InteractiveActor.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AInteractiveActor, nullptr, "OnEndMouseOver", nullptr, nullptr, Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::PropPointers), sizeof(Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::InteractiveActor_eventOnEndMouseOver_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::Function_MetaDataParams), Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::InteractiveActor_eventOnEndMouseOver_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AInteractiveActor);
	UClass* Z_Construct_UClass_AInteractiveActor_NoRegister()
	{
		return AInteractiveActor::StaticClass();
	}
	struct Z_Construct_UClass_AInteractiveActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AInteractiveActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Robbin,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractiveActor_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AInteractiveActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AInteractiveActor_Activate, "Activate" }, // 4270214473
		{ &Z_Construct_UFunction_AInteractiveActor_Hovering, "Hovering" }, // 2175118640
		{ &Z_Construct_UFunction_AInteractiveActor_OnBeginMouseOver, "OnBeginMouseOver" }, // 2283311600
		{ &Z_Construct_UFunction_AInteractiveActor_OnEndMouseOver, "OnEndMouseOver" }, // 664502812
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractiveActor_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractiveActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "InteractiveActors/InteractiveActor.h" },
		{ "ModuleRelativePath", "InteractiveActors/InteractiveActor.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AInteractiveActor_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "Category", "InteractiveActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "InteractiveActors/InteractiveActor.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AInteractiveActor_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x00200800000a0009, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AInteractiveActor, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractiveActor_Statics::NewProp_MeshComponent_MetaData), Z_Construct_UClass_AInteractiveActor_Statics::NewProp_MeshComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AInteractiveActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AInteractiveActor_Statics::NewProp_MeshComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AInteractiveActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AInteractiveActor>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AInteractiveActor_Statics::ClassParams = {
		&AInteractiveActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AInteractiveActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AInteractiveActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractiveActor_Statics::Class_MetaDataParams), Z_Construct_UClass_AInteractiveActor_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AInteractiveActor_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AInteractiveActor()
	{
		if (!Z_Registration_Info_UClass_AInteractiveActor.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AInteractiveActor.OuterSingleton, Z_Construct_UClass_AInteractiveActor_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AInteractiveActor.OuterSingleton;
	}
	template<> ROBBIN_API UClass* StaticClass<AInteractiveActor>()
	{
		return AInteractiveActor::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AInteractiveActor);
	AInteractiveActor::~AInteractiveActor() {}
	struct Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_InteractiveActor_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_InteractiveActor_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AInteractiveActor, AInteractiveActor::StaticClass, TEXT("AInteractiveActor"), &Z_Registration_Info_UClass_AInteractiveActor, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AInteractiveActor), 2209376536U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_InteractiveActor_h_1773617741(TEXT("/Script/Robbin"),
		Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_InteractiveActor_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Robbin_Source_Robbin_InteractiveActors_InteractiveActor_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
