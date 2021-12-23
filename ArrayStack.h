#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100 // 스택 크기

double stack[STACK_SIZE]; // 스택 선언
int top; // 스택의 TOP

void initialize(void);
int isEmpty(void);
int getTop(void);
double push(double p);
double pop(void);
int isOperator(int ex);
int priority(int op);
