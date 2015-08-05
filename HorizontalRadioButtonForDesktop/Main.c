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
	printf("���� ��ư ���� �Է� : ");
	scanf("%d", &count);
	printf("���� ��ư ���� ��ġ �Է� (x, y)\n�ܼ� â ũ�� ����� �ʵ��� ���� : ");
	scanf("%d %d", &startPositionXToPrint, &startPositionYToPrint);
	getchar();
	printf("���� ��ư ����� �Է�\n");
	for (i = 0; i < count; i++){
		printf("%d ��° : ex) [1] ���� ��ư 1 : ", i + 1);
		fgets(items[i], ITEMS_CONTENT_SIZE, stdin);
		items[i][strlen(items[i]) - 1] = '\0';
	}
	system("cls");
	HorizontalRadioButton_Create(&horizontalRadioButton, items, count, startPositionXToPrint, startPositionYToPrint);
	HorizontalRadioButton_Print(&horizontalRadioButton);
	selectedIndex = HorizontalRadioButton_ProcessKey(&horizontalRadioButton);
	printf("\n\n���õ� ���� ��ư ���� : %s\n", HorizontalRadioButton_GetSelectedContent(&horizontalRadioButton));
	return 0;
}