// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AstraPlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class ASTRAPROJECT03_API AAstraPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	AAstraPlayerController();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> AstraContext;

};
