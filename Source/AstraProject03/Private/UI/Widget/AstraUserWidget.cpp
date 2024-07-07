// Copyright SkyHigh Gaming.


#include "UI/Widget/AstraUserWidget.h"

void UAstraUserWidget::SetWidgetContoller(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
