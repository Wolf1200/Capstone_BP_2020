// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Capstone_2020/Capstone_2020GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCapstone_2020GameMode() {}
// Cross Module References
	CAPSTONE_2020_API UClass* Z_Construct_UClass_ACapstone_2020GameMode_NoRegister();
	CAPSTONE_2020_API UClass* Z_Construct_UClass_ACapstone_2020GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Capstone_2020();
// End Cross Module References
	void ACapstone_2020GameMode::StaticRegisterNativesACapstone_2020GameMode()
	{
	}
	UClass* Z_Construct_UClass_ACapstone_2020GameMode_NoRegister()
	{
		return ACapstone_2020GameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACapstone_2020GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACapstone_2020GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Capstone_2020,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACapstone_2020GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Capstone_2020GameMode.h" },
		{ "ModuleRelativePath", "Capstone_2020GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACapstone_2020GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACapstone_2020GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACapstone_2020GameMode_Statics::ClassParams = {
		&ACapstone_2020GameMode::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ACapstone_2020GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACapstone_2020GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACapstone_2020GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACapstone_2020GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACapstone_2020GameMode, 3724302692);
	template<> CAPSTONE_2020_API UClass* StaticClass<ACapstone_2020GameMode>()
	{
		return ACapstone_2020GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACapstone_2020GameMode(Z_Construct_UClass_ACapstone_2020GameMode, &ACapstone_2020GameMode::StaticClass, TEXT("/Script/Capstone_2020"), TEXT("ACapstone_2020GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACapstone_2020GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
