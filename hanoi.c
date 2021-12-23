#include<stdio.h>
#include <time.h>

int count = 0;
clock_t start, finish, used_time = 0;

void hanoi(int n, char start, char tmp, char end) {


    if (n == 1) { // (n = 1)
        // c -> a�� �ű�� �����δ� c -> b -> a ������ �Űܰ���. 
        printf("%c ����� 1�� �� -> %c ������� �̵� \n", start, end);
        count++;
    }

    else { // (n > 1)
        hanoi(n - 1, start, end, tmp); // a -> b �� �ű�� 
        printf("%c ����� %d�� �� -> %c ������� �̵� \n", start, n, end);
        hanoi(n - 1, tmp, start, end); // b -> c �� �ű��
        count++;
    }
}

void CalcTime() {
    used_time = finish - start;
    printf("�ҿ� �ð� : %f sec\n\n", (float)used_time / CLOCKS_PER_SEC);
}

int main() {

    int N;
    printf("�ϳ��� �� �� �Է�: ");
    scanf("%d", &N);
    start = clock();
    printf("\n");
    hanoi(N, 'a', 'b', 'c');
    finish = clock();
    printf("\n----------- %d�� �ϳ���ž -----------", N);
    printf("\n�̵� �Ϸ�!\n");
    printf("������ Ƚ�� : %d\n", count);
    CalcTime();
    return 0;
}
