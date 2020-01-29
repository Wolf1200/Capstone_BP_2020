// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Paths.h"
#include "PlatformFilemanager.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "Misc/FileHelper.h"
#include "ReadText_BPlib.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_BP_2020_API UReadText_BPlib : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    // maybe?
    UFUNCTION(BlueprintPure, Category = "Magic Functions")
        static bool LoadTxt(FString filename, FString& loadText);

    UFUNCTION(BlueprintCallable, Category = "Magic Functions")
        static bool SaveTxt(FString saveText, FString filename);
};
