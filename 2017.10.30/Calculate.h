#define LEN 100
/*���� ����� ���� �������
1. ����ǥ������� �ٲٱ�
2. ������ �̿��ϱ�
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

void Change(char *arr); //����ǥ������� �Ǿ� �ִ� ���ڿ��� ����ǥ������� ����.
void stores(char num);
void stackinit(Stack *st, Stack2 *st2);
void calculate_push(Stack2 *st2, char data);
void cal_push(Stack2 *st2, int data);
int checknum(char data);
int push(Stack *st, char data, int num);
int pop(Stack *st);
int calculate(Stack2 *st2);