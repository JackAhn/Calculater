#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "Calculate.h"

int main() {
	int a = 0;
	char arr[LEN];
	int i;
	printf("계산기 작동 시작\n");
	while (1) {
		for (i = 0; i < LEN; i++) {
			arr[i] = '\0';
		}
		stackinit(&stack, &stack2);
		printf("1. 계산 시작 \t 2.계산기 종료\n");
		scanf("%d", &a);
		if (a == 1) {
			system("cls");
			printf("계산할 식을 적어주세요 : ");
			scanf("%s", arr);
			Change(&arr);
			printf("%s\n", store);
			printf("%d\n", calculate(&stack2));
		}
		else if (a == 2) {
			printf("계산기를 종료합니다.\n");
			return 0;
		}
		else {
			printf("잘못된 입력입니다. 1 또는 2만 입력해 주세요.\n");
			Sleep(1000);
			system("cls");
			continue;
		}
	}
}