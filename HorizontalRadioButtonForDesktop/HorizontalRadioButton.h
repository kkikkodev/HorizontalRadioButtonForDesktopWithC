#ifndef _HORIZONTAL_RADIO_BUTTON_H
#define _HORIZONTAL_RADIO_BUTTON_H
#include "Point.h"

#define ITEMS_COUNT 10
#define ITEMS_CONTENT_SIZE 128

typedef struct _horizontalRadioButton{
	char items[ITEMS_COUNT][ITEMS_CONTENT_SIZE];
	int count;
	int selectedIndex;
	Point startPositionToPrint;
}HorizontalRadioButton;

void HorizontalRadioButton_Create(HorizontalRadioButton* horizontalRadioButton, char(*items)[ITEMS_CONTENT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint);
void HorizontalRadioButton_Print(HorizontalRadioButton* horizontalRadioButton);
int HorizontalRadioButton_ProcessKey(HorizontalRadioButton* horizontalRadioButton);
const char* HorizontalRadioButton_GetSelectedContent(HorizontalRadioButton* horizontalRadioButton);

#endif