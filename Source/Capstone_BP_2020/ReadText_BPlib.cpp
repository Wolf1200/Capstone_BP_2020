// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadText_BPlib.h"

// maybe?

bool UReadText_BPlib::LoadTxt(FString filename, FString & loadText)
{
    return FFileHelper::LoadFileToString(loadText, *(FPaths::GameDir() + filename));
}

bool UReadText_BPlib::SaveTxt(FString saveText, FString filename)
{
    return FFileHelper::SaveStringToFile(saveText, *(FPaths::GameDir() + filename));
}