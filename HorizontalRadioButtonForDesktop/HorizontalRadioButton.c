#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "HorizontalRadioButton.h"
#include "Util.h"

enum KeyCode{
	ENTER = 13, LEFT = 75, RIGHT = 77
};

enum Boolean{
	False, True
};

void HorizontalRadioButton_Create(HorizontalRadioButton* horizontalRadioButton, char(*items)[ITEMS_CONTENT_SIZE], int count, int startPositionXToPrint, int startPositionYToPrint){
	int i;
	for (i = 0; i < count; i++){
		strcpy(horizontalRadioButton->items[i], items[i]);
	}
	horizontalRadioButton->count = count;
	horizontalRadioButton->selectedIndex = 0;
	horizontalRadioButton->startPositionToPrint.x = startPositionXToPrint;
	horizontalRadioButton->startPositionToPrint.y = startPositionYToPrint;
}

void HorizontalRadioButton_Print(HorizontalRadioButton* horizontalRadioButton){
	int i;
	Point startPositionToPrint = horizontalRadioButton->startPositionToPrint;
	CursorUtil_Hide();
	for (i = 0; i < horizontalRadioButton->count; i++){
		CursorUtil_GotoXY(startPositionToPrint.x, startPositionToPrint.y);
		startPositionToPrint.x += strlen(horizontalRadioButton->items[i]) + 4;
		if (i == horizontalRadioButton->selectedIndex){
			FontUtil_ChangeFontColor(WHITE_INVERSION);
			printf("¡Ý %s", horizontalRadioButton->items[i]);
		}
		else{
			FontUtil_ChangeFontColor(WHITE);
			printf("¡Û %s", horizontalRadioButton->items[i]);
		}
	}
	FontUtil_ChangeFontColor(WHITE);
}

int HorizontalRadioButton_ProcessKey(HorizontalRadioButton* horizontalRadioButton){
	while (True){
		if (_kbhit()){
			int key = _getch();
			if (key == ENTER){
				break;
			}
			switch (key){
			case 0xE0:
				if (_kbhit()){
					switch (_getch()){
					case LEFT:
						horizontalRadioButton->selectedIndex = (horizontalRadioButton->selectedIndex - 1 + horizontalRadioButton->count) % horizontalRadioButton->count;
						HorizontalRadioButton_Print(horizontalRadioButton);
						break;
					case RIGHT:
						horizontalRadioButton->selectedIndex = (horizontalRadioButton->selectedIndex + 1) % horizontalRadioButton->count;
						HorizontalRadioButton_Print(horizontalRadioButton);
						break;
					}
				}
				break;
			}
		}
	}
	return horizontalRadioButton->selectedIndex;
}

const char* HorizontalRadioButton_GetSelectedContent(HorizontalRadioButton* horizontalRadioButton){
	return horizontalRadioButton->items[horizontalRadioButton->selectedIndex];
}
