#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100001] = { 0 };

// 앞 뒤를 보고 비교해야함

int main()
{
    int N, index = 0, clap = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)

    {

        scanf("%d", &index);

        arr[index] = i + 1;

    }

    for (int i = 1; i < N; i++)

        if (arr[i] > arr[i + 1]) // --> 순서대로 비교하는 부분 중요!

            clap++;

    printf("%d", clap);

    return 0;
}