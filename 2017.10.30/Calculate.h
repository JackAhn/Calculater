#define LEN 100
/*계산기 만들기 위한 헤더파일
1. 후위표기법으로 바꾸기
2. 스택을 이용하기
*/
typedef struct _arrayStack {
	char Stack[LEN];
	int top;
}Stack;
Stack stack;

typedef struct __arrayStack {
	int Stack2[LEN];
	int top;
}Stack2;
Stack2 stack2;


char store[LEN];
int ex[LEN];

void Change(char *arr); //중위표기법으로 되어 있는 문자열을 후위표기법으로 변경.
void stores(char num);
void stackinit(Stack *st, Stack2 *st2);
void calculate_push(Stack2 *st2, char data);
void cal_push(Stack2 *st2, int data);
int checknum(char data);
int push(Stack *st, char data, int num);
int pop(Stack *st);
int calculate(Stack2 *st2);