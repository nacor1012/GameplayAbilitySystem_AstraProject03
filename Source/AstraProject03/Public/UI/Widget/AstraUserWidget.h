// Copyright SkyHigh Gaming.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AstraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class ASTRAPROJECT03_API UAstraUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetContoller(UObject* InWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject> WidgetController;

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void WidgetControllerSet();
};
