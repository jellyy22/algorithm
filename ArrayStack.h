#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 100 // ���� ũ��

double stack[STACK_SIZE]; // ���� ����
int top; // ������ TOP

void initialize(void);
int isEmpty(void);
int getTop(void);
double push(double p);
double pop(void);
int isOperator(int ex);
int priority(int op);
