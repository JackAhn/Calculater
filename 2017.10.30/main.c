#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "Calculate.h"

int main() {
	int a = 0;
	char arr[LEN];
	int i;
	printf("���� �۵� ����\n");
	while (1) {
		for (i = 0; i < LEN; i++) {
			arr[i] = '\0';
		}
		stackinit(&stack, &stack2);
		printf("1. ��� ���� \t 2.���� ����\n");
		scanf("%d", &a);
		if (a == 1) {
			system("cls");
			printf("����� ���� �����ּ��� : ");
			scanf("%s", arr);
			Change(&arr);
			printf("%s\n", store);
			printf("%d\n", calculate(&stack2));
		}
		else if (a == 2) {
			printf("���⸦ �����մϴ�.\n");
			return 0;
		}
		else {
			printf("�߸��� �Է��Դϴ�. 1 �Ǵ� 2�� �Է��� �ּ���.\n");
			Sleep(1000);
			system("cls");
			continue;
		}
	}
}