#include "ArrayStack.h"

// ���� �ʱ�ȭ �Լ� 
void initialize(void)
{
    top = -1;   // �ʱ�ȭ 
}

// ������ ����ִ��� �˻�
int isEmpty(void)
{
    return (top < 0); //���� �ִ��� ������ Ȯ���ϴ� �� 
}

// ���ÿ��� TOP�� ���� �����´�.
int getTop(void)
{
    return (top < 0) ? -1 : stack[top];
}

//���ÿ� �����ϴ� �Լ� 
double push(double p)
{

    if (top >= STACK_SIZE - 1)
    {
        printf("����: ������ ���� ��. \n");
        return -1;
    }

    stack[++top] = p;
    return p;
}

//���ÿ��� ���� �ϳ� �������� �Լ� 
double pop(void)
{
    if (top < 0)
    {
        printf("����: ������ �������. \n");
        return -1;
    }
    return stack[top--];
}

// ���������� ��ȯ �Լ�
int isOperator(int ex)
{
    return (ex == '+' || ex == '-' || ex == '*' || ex == '/');
}

// �������� �켱������ ��ġ�� ��ȯ���ش�.
int priority(int op)
{
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    else return 3;
}
