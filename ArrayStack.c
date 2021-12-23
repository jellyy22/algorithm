#include "ArrayStack.h"

// 스택 초기화 함수 
void initialize(void)
{
    top = -1;   // 초기화 
}

// 스택이 비어있는지 검사
int isEmpty(void)
{
    return (top < 0); //값이 있는지 없는지 확인하는 것 
}

// 스택에서 TOP의 값을 가져온다.
int getTop(void)
{
    return (top < 0) ? -1 : stack[top];
}

//스택에 삽입하는 함수 
double push(double p)
{

    if (top >= STACK_SIZE - 1)
    {
        printf("에러: 스택이 가득 참. \n");
        return -1;
    }

    stack[++top] = p;
    return p;
}

//스택에서 값을 하나 가져오는 함수 
double pop(void)
{
    if (top < 0)
    {
        printf("에러: 스택이 비어있음. \n");
        return -1;
    }
    return stack[top--];
}

// 연산자인지 반환 함수
int isOperator(int ex)
{
    return (ex == '+' || ex == '-' || ex == '*' || ex == '/');
}

// 연산자의 우선순위를 수치로 변환해준다.
int priority(int op)
{
    if (op == '(') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    else return 3;
}
