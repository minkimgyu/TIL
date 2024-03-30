#pragma once
#include "Queue.h"

// 시간복잡도: O(dn)
// 공간 복잡도가 매우 크다.
// 알파벳이나 한글같은 종류는 사용하기 어렵다.

// Stable: Yes 
// In-place: No

void RadixSort(int* arr, int size) {
    //# 배열, 최댓값, 배열크기를 파라미터로 받는다.

    int max = 0;
    for (int i = 0; i < size; i++) if (max < arr[i]) max = arr[i];

    Queue<int>* q = new Queue<int>[10]; // 버킷 --> 10진수라서 10개 필요함
    int radix = 1; // 최대자릿수

    while (true) { // 최대자릿수를 구하는 과정 --> max 값을 이용해서 찾는다.
        if (radix > max) break;
        radix *= 10;
    }

    for (int cipher = 1; cipher < radix; cipher *= 10) { // cipher는 자릿수를 뜻한다.
        for (int i = 0; i < size; i++) {

            int value = (arr[i] / cipher) % 10; // 해당 자릿 수를 찾는 코드

            q[value].Push(arr[i]); // 버킷의 자릿수의 값 위치에 원래 값을 push한다.
        }

        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!q[i].IsEmpty()) {
                arr[index] = q[i].Front();
                q[i].Pop();
                index++;
            }
        }
    }

    delete[] q;
}