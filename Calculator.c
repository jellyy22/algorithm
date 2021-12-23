#include "Calculator.h"

// ����ǥ��� -> ����ǥ������� ��ȯ�ϴ� �Լ� 
void getPostfix(char* tmp1, char* arr1)
{
    initialize();   //���� �ʱ�ȭ 

    while (*arr1) { // ���Ŀ��� �ϳ��� ���ڸ� �д´�.
        if (*arr1 == '(') // ������ �д� �߿� ( �� ������ 
        {
            push(*arr1); //���ÿ� �ִ´�.
            arr1++; // �������� �̵�
        }
        else if (*arr1 == ')') // ������ �д� �߿� ) �� ������
        {
            while (getTop() != '(')  // ( �� ���� �� ����
            {
                *tmp1++ = pop(); // ���ÿ��� pop�Ͽ� tep1�� �ִ´�.
                *tmp1++ = ' ';
            }
            pop(); // ���ÿ� ������ִ� ( �� pop�Ͽ� ������
            arr1++;
        }
        else if (isOperator(*arr1)) // ������ �д� �� �����ڸ� ������
        {
            while (!isEmpty() && priority(getTop()) >= priority(*arr1)) //���ÿ��� ���� �����ں��� ���� �켱������ �����ڸ� ���� �� ����
            {
                *tmp1++ = pop(); // pop�Ѵ�.
                *tmp1++ = ' ';
            }
            push(*arr1); // �ڱ��ڽ��� push�Ѵ�
            arr1++;
        }
        else if (*arr1 >= '0' && *arr1 <= '9') // ������ �д� �� �ǿ����ڸ� ������
        {
            do
            {
                *tmp1++ = *arr1++; // tmp1�� �ǿ����ڸ� ���� �ִ´�.
                if (*arr1 == '.') { // �Ҽ����� ���
                    *tmp1++ = *arr1++; // �ǿ����ڿ� �����ϰ� tmp1�� ���� �ִ´�.
                }
            } while (*arr1 >= '0' && *arr1 <= '9');
            *tmp1++ = ' '; // �ǿ����ڵ��� �����ϱ� ���� ������ �־��ش�.
        }
        else // ������ ���� ���� ����ؼ� �д´�. 
        {
            arr1++;
        }
    }
    while (!isEmpty()) //������ �� ������
    {
        *tmp1++ = pop(); //  ���ÿ� �ִ� �����ڵ��� ��� pop�Ͽ� ����Ѵ�.
        *tmp1++ = ' ';
    }
    tmp1--;
    *tmp1 = 0;
}

// ����ǥ��� ���
double calc(char* post)
{
    double i;
    int point;

    initialize();   // ���� �ʱ�ȭ 

    while (*post) {
        if (*post >= '0' && *post <= '9') {   // �������� �д� ���� �ǿ����ڸ� ������
            i = 0.0;
            point = -9999;

            do
            {
                // ���� ��� ���: post�� �����̱⶧���� �ƽ�Ű �ڵ� ������ ����Ѵ�.'0' = 48
                i = i * 10 + *post - '0'; // i�� �����Ѵ�.
                post++;

                if (*post == '.') // �Ҽ����� ������
                {
                    point = 0;
                    post++;
                }
                point++; // point�� ���� ��Ű�� ��� �о��.
            } while (*post >= '0' && *post <= '9');

            if (point > 1)
            {
                for (int f = 1; f < point; f++) // point ũ�⸸ŭ
                {
                    // �Ҽ� �����
                    i = i / 10; // �Ҽ��� �ڸ��� �����.
                }
            }
            push(i); // ���ÿ� i�� �ִ´�.
        }
        else if (*post == '+') // �������� �д� ���� �����ڸ� ������
        {
            push(pop() + pop()); // pop�� �� �� �Ͽ� �� �ǿ����ڿ� �ش� �����ڷ� ����� ���� �� ����� ���ÿ� push �Ѵ�.
            post++;
        }
        else if (*post == '*')
        {
            push(pop() * pop());
            post++;
        }
        else if (*post == '-')
        {
            i = pop();
            push(pop() - i);
            post++;
        }
        else if (*post == '/')
        {
            i = pop();
            push(pop() / i);
            post++;
        }
        else
        {
            post++;
        }
    }
    return pop();
}

int main(void) {
    int i, len, j = 0;
    double result, ch;
    char arr[STACK_SIZE];
    char tmp[STACK_SIZE];

    printf("���� �Է�: ");
    scanf("%s", arr);
    len = strlen(arr);

    //��ȣ �˻�
    for (i = 0; i < len; i++) {
        if (arr[i] == '(') { // ( �� ������ ���ÿ� ����
            push(arr[i]);
        }
        else if (arr[i] == ')')
        {
            if (isEmpty()) { // ) �� �����µ� ������ ����ִٸ�
                printf("��ȣ ������ ���� �ʽ��ϴ�.\n");
                return -1;
            }
            ch = pop(); // ���ÿ� �־��� ���ڸ� �ϳ� �����´�.

            if (ch != '(') {
                printf("��ȣ ������ ���� �ʽ��ϴ�.\n");
                return -1;
            }
        }
    }
    printf("\n== == == == ��� == == == ==\n");
    printf("��ȣ�˻� : ����\n");
    getPostfix(tmp, arr); // ����ִ� �迭�� ������ �Ѱ��ش�.
    printf("�������� : %s\n", tmp);
    result = calc(tmp);
    printf("����� : %f\n", result);
    return 0;
}
