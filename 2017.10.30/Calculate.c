#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Calculate.h"

void stackinit(Stack *st, Stack2 *st2) {
	int i;
	for (i = 0; i < LEN; i++) {
		st->Stack[i] = '\0';
		st2->Stack2[i] = 0;
		store[i] = '\0';
		ex[i] = 0;
	}
	st->top = 0;
	st2->top = -1;
}

void Change(char *arr) {
	int i, j;
	int count=0, tmp=0;
	for (i = 0; arr[i] != '\0'; i++) {
		printf("%s\n", store);
		if (arr[i] >= '0' && arr[i] <= '9') {
			stores(arr[i]);
			count++;
		}
		else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/') {
			for (j = 0; store[j] != '\0'; j++) {

			}
			tmp = j;
			store[tmp] = ' ';
			push(&stack, arr[i], checknum(arr[i]));
			for (j = 0; store[j] != '\0'; j++) {

			}
			tmp = j;
			store[tmp] = ' ';
		}
		else if (arr[i] == '(') {
			push(&stack, arr[i], checknum(arr[i]));
		}
		if (arr[i + 1] == ')') {
			pop(&stack);
		}
		else
			continue;
	}
	if (count >= 1) {
		for (j = 0; store[j] != '\0'; j++) {

		}
		tmp = j;
		store[tmp] = ' ';
	}
	pop(&stack);
}

int checknum(char data) {
	switch(data) {
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	case '(':
		return 3;
	}
}
void stores(char num) {
	int i, temp = 0;
	for (i = 0; store[i] != '\0'; i++) {

	}
	temp = i;
	store[temp] = num;
}


int push(Stack *st, char data, int num) {
	int t = 0;
	char tp;
	if(st->top==LEN)
		return 0;
	if (st->top > 0) {
		st->top--;
		tp = st->Stack[st->top];
		st->top++;
		t = checknum(tp);
	}
	if (t >= num && tp!='(') {
		int i, temp=0;
		for (i = 0; store[i] != '\0'; i++) {

		}
		temp = i;
		st->top--;
		store[temp] = tp;
		st->Stack[st->top] = data;
		st->top++;
		return 1;
	}
	st->Stack[st->top] = data;
	st->top++;
	return 1;
}
int pop(Stack *st) {
	int i;
	while (st->top >= 0) {
		int cnt = 0;
		for (i = 0; store[i] != '\0'; i++) {

		}
		cnt = i;
		if (st->Stack[st->top] == '(') {
			if (st->top == 0) {
				st->Stack[st->top] = '\0';
				return;
			}
			else {
				st->Stack[st->top] = '\0';
				st->top--;
				return;
			}
		}
		store[cnt] = ' ';
		cnt += 1;
		store[cnt]	= st->Stack[st->top];
		st->Stack[st->top] = '\0';
		st->top--;
	}
}

int calculate(Stack2 *st2) {
	int i, result=0, ex=0;
	for (i = 0; store[i] != '\0'; i++) {
		if (store[i] == '+') {
			int num1 = calculate_pop(&stack2,0);
			int num2 = calculate_pop(&stack2,0);
			result = num2 + num1;
			cal_push(&stack2, result);
			continue;
		}
		else if (store[i] == '-') {
			int num1 = calculate_pop(&stack2,0);
			int num2 = calculate_pop(&stack2,0);
			result = num2 - num1;
			cal_push(&stack2, result);
			continue;
		}
		else if (store[i] == '*') {
			int num1 = calculate_pop(&stack2,0);
			int num2 = calculate_pop(&stack2,0);
			result = num2 * num1;
			cal_push(&stack2, result);
			continue;
		}
		else if (store[i] == '/') {
			int num1 = calculate_pop(&stack2, 0);
			int num2 = calculate_pop(&stack2, 0);
			result = num2 / num1;
			cal_push(&stack2, result);
			continue;
		}
		calculate_push(&stack2, store[i], ex, i);
		if(store[i]==' ')
			ex = i;
	
	}
	return result;
}

void calculate_push(Stack2 *st2, char data, int ex, int t) {
	int i, j, num = 0, ct = 0, count=0, temp = 1, tmp = 0, bk=0, tp=0;
	if (data == ' ') {
		if (ex == 0)
			tmp = t - ex;
		else
			tmp = t - ex - 1;
		if ((store[t + 1] == '+' || store[t + 1] == '-' || store[t + 1] == '*' || store[t + 1] == '/')&&tmp<2)
			return;
		if (tmp >= 2&&st2->top>1) {
			count = tmp;
			while (tmp>0) {
				if(store[tmp]>='0'&& tmp!=count)
				ct = calculate_pop(&stack2, 1);
				else
					ct = calculate_pop(&stack2, 0);
				num = num+(ct*temp);
				temp = temp * 10;
				tmp--;
			}
		}
		else if(tmp<=2&&temp==1)
			return;
		if (st2->top == -1 || st2->Stack2[st2->top]>0)
			st2->top++;
		st2->Stack2[st2->top] = num;
		st2->top++;
		return;
	}
	else {
		tp = data - '0';
		if (st2->top == -1 || st2->Stack2[st2->top] > 0)
			st2->top++;
		st2->Stack2[st2->top] = tp;
		st2->top++;
	}
	return;
}
void cal_push(Stack2 *st2, int data) {
	if (st2->top == -1|| st2->Stack2[st2->top]>0)
		st2->top++;
	st2->Stack2[st2->top] = data;
	st2->top++;
	return;
}
int calculate_pop(Stack2 *st2, int num) {
	if (st2->top == -1)
		return 0;
	if (st2->top == 0) {
		int a = st2->Stack2[st2->top];
		st2->Stack2[st2->top] = 0;
		st2->top--;
		return a;
	}
	else if (st2->top > 0) {
		if(st2->Stack2[st2->top] ==0 && num==0)
			st2->top--;
		int a = st2->Stack2[st2->top];
		st2->Stack2[st2->top] = 0;
		st2->top--;
		return a;
	}
}