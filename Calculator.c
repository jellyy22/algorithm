#include "Calculator.h"

// 중위표기법 -> 후위표기법으로 변환하는 함수 
void getPostfix(char* tmp1, char* arr1)
{
    initialize();   //스택 초기화 

    while (*arr1) { // 수식에서 하나씩 문자를 읽는다.
        if (*arr1 == '(') // 수식을 읽는 중에 ( 를 만나면 
        {
            push(*arr1); //스택에 넣는다.
            arr1++; // 다음으로 이동
        }
        else if (*arr1 == ')') // 수식을 읽는 중에 ) 를 만나면
        {
            while (getTop() != '(')  // ( 를 만날 때 까지
            {
                *tmp1++ = pop(); // 스택에서 pop하여 tep1에 넣는다.
                *tmp1++ = ' ';
            }
            pop(); // 스택에 저장되있던 ( 는 pop하여 버린다
            arr1++;
        }
        else if (isOperator(*arr1)) // 수식을 읽는 중 연산자를 만나면
        {
            while (!isEmpty() && priority(getTop()) >= priority(*arr1)) //스택에서 현재 연산자보다 낮은 우선순위의 연산자를 만날 때 까지
            {
                *tmp1++ = pop(); // pop한다.
                *tmp1++ = ' ';
            }
            push(*arr1); // 자기자신을 push한다
            arr1++;
        }
        else if (*arr1 >= '0' && *arr1 <= '9') // 수식을 읽는 중 피연산자를 만나면
        {
            do
            {
                *tmp1++ = *arr1++; // tmp1에 피연산자를 집어 넣는다.
                if (*arr1 == '.') { // 소수점인 경우
                    *tmp1++ = *arr1++; // 피연산자와 동일하게 tmp1에 집어 넣는다.
                }
            } while (*arr1 >= '0' && *arr1 <= '9');
            *tmp1++ = ' '; // 피연산자들을 구분하기 위해 공백을 넣어준다.
        }
        else // 나머지 경우는 식을 계속해서 읽는다. 
        {
            arr1++;
        }
    }
    while (!isEmpty()) //스택이 빌 때까지
    {
        *tmp1++ = pop(); //  스택에 있는 연산자들을 모두 pop하여 출력한다.
        *tmp1++ = ' ';
    }
    tmp1--;
    *tmp1 = 0;
}

// 후위표기법 계산
double calc(char* post)
{
    double i;
    int point;

    initialize();   // 스택 초기화 

    while (*post) {
        if (*post >= '0' && *post <= '9') {   // 후위식을 읽는 도중 피연산자를 만나면
            i = 0.0;
            point = -9999;

            do
            {
                // 정수 계산 방법: post는 문자이기때문에 아스키 코드 값으로 계산한다.'0' = 48
                i = i * 10 + *post - '0'; // i에 저장한다.
                post++;

                if (*post == '.') // 소수점을 만나면
                {
                    point = 0;
                    post++;
                }
                point++; // point를 증가 시키고 계속 읽어간다.
            } while (*post >= '0' && *post <= '9');

            if (point > 1)
            {
                for (int f = 1; f < point; f++) // point 크기만큼
                {
                    // 소수 계산방법
                    i = i / 10; // 소수점 자릿수 맞춘다.
                }
            }
            push(i); // 스택에 i를 넣는다.
        }
        else if (*post == '+') // 후위식을 읽는 도중 연산자를 만나면
        {
            push(pop() + pop()); // pop을 두 번 하여 두 피연산자와 해당 연산자로 계산한 다음 그 결과를 스택에 push 한다.
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

    printf("수식 입력: ");
    scanf("%s", arr);
    len = strlen(arr);

    //괄호 검사
    for (i = 0; i < len; i++) {
        if (arr[i] == '(') { // ( 를 만나면 스택에 삽입
            push(arr[i]);
        }
        else if (arr[i] == ')')
        {
            if (isEmpty()) { // ) 를 만났는데 스택이 비어있다면
                printf("괄호 개수가 맞지 않습니다.\n");
                return -1;
            }
            ch = pop(); // 스택에 넣었던 문자를 하나 가져온다.

            if (ch != '(') {
                printf("괄호 개수가 맞지 않습니다.\n");
                return -1;
            }
        }
    }
    printf("\n== == == == 계산 == == == ==\n");
    printf("괄호검사 : 정상\n");
    getPostfix(tmp, arr); // 비어있는 배열과 수식을 넘겨준다.
    printf("후위수식 : %s\n", tmp);
    result = calc(tmp);
    printf("계산결과 : %f\n", result);
    return 0;
}
