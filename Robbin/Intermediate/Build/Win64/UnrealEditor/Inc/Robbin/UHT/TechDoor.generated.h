// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "InteractiveActors/Doors/TechDoor.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef ROBBIN_TechDoor_generated_h
#error "TechDoor.generated.h already included, missing '#pragma once' in TechDoor.h"
#endif
#define ROBBIN_TechDoor_generated_h

#define FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_SPARSE_DATA
#define FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execClose); \
	DECLARE_FUNCTION(execOpen);


#define FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_ACCESSORS
#define FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesATechDoor(); \
	friend struct Z_Construct_UClass_ATechDoor_Statics; \
public: \
	DECLARE_CLASS(ATechDoor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Robbin"), NO_API) \
	DECLARE_SERIALIZER(ATechDoor)


#define FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ATechDoor(ATechDoor&&); \
	NO_API ATechDoor(const ATechDoor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ATechDoor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ATechDoor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ATechDoor) \
	NO_API virtual ~ATechDoor();


#define FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_9_PROLOG
#define FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_SPARSE_DATA \
	FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_ACCESSORS \
	FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_INCLASS_NO_PURE_DECLS \
	FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ROBBIN_API UClass* StaticClass<class ATechDoor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Robbin_Source_Robbin_InteractiveActors_Doors_TechDoor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
