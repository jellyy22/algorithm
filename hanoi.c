#include<stdio.h>
#include <time.h>

int count = 0;
clock_t start, finish, used_time = 0;

void hanoi(int n, char start, char tmp, char end) {


    if (n == 1) { // (n = 1)
        // c -> a로 옮기기 실제로는 c -> b -> a 순서로 옮겨간다. 
        printf("%c 기둥의 1층 블럭 -> %c 기둥으로 이동 \n", start, end);
        count++;
    }

    else { // (n > 1)
        hanoi(n - 1, start, end, tmp); // a -> b 로 옮기기 
        printf("%c 기둥의 %d층 블럭 -> %c 기둥으로 이동 \n", start, n, end);
        hanoi(n - 1, tmp, start, end); // b -> c 로 옮기기
        count++;
    }
}

void CalcTime() {
    used_time = finish - start;
    printf("소요 시간 : %f sec\n\n", (float)used_time / CLOCKS_PER_SEC);
}

int main() {

    int N;
    printf("하노이 층 수 입력: ");
    scanf("%d", &N);
    start = clock();
    printf("\n");
    hanoi(N, 'a', 'b', 'c');
    finish = clock();
    printf("\n----------- %d층 하노이탑 -----------", N);
    printf("\n이동 완료!\n");
    printf("움직임 횟수 : %d\n", count);
    CalcTime();
    return 0;
}
