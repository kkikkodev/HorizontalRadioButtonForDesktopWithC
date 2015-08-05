#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HorizontalRadioButton.h"

int main(int argc, char* argv[]){
	HorizontalRadioButton horizontalRadioButton = { 0, };
	char items[ITEMS_COUNT][ITEMS_CONTENT_SIZE] = { '\0', };
	int i;
	int count;
	int startPositionXToPrint;
	int startPositionYToPrint;
	int selectedIndex;
	printf("라디오 버튼 개수 입력 : ");
	scanf("%d", &count);
	printf("라디오 버튼 시작 위치 입력 (x, y)\n콘솔 창 크기 벗어나지 않도록 주의 : ");
	scanf("%d %d", &startPositionXToPrint, &startPositionYToPrint);
	getchar();
	printf("라디오 버튼 내용들 입력\n");
	for (i = 0; i < count; i++){
		printf("%d 번째 : ex) [1] 라디오 버튼 1 : ", i + 1);
		fgets(items[i], ITEMS_CONTENT_SIZE, stdin);
		items[i][strlen(items[i]) - 1] = '\0';
	}
	system("cls");
	HorizontalRadioButton_Create(&horizontalRadioButton, items, count, startPositionXToPrint, startPositionYToPrint);
	HorizontalRadioButton_Print(&horizontalRadioButton);
	selectedIndex = HorizontalRadioButton_ProcessKey(&horizontalRadioButton);
	printf("\n\n선택된 라디오 버튼 내용 : %s\n", HorizontalRadioButton_GetSelectedContent(&horizontalRadioButton));
	return 0;
}