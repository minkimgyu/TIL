#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[100001] = { 0 };

// �� �ڸ� ���� ���ؾ���

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

        if (arr[i] > arr[i + 1]) // --> ������� ���ϴ� �κ� �߿�!

            clap++;

    printf("%d", clap);

    return 0;
}