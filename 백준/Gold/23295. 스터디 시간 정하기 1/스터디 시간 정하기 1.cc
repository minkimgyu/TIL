// 23295.cpp : This file contains the 'main' function. Program execution begins and ends there.
    //

#include <iostream>
#include <vector>
using namespace std;

int N, T;
vector<int> sums(100002);
int endOfTime;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> T;

    for (int i = 0; i < N; ++i) {
        int timeCnt;
        cin >> timeCnt;

        for (int j = 0; j < timeCnt; ++j) {

            int start, end;
            cin >> start >> end;

            sums[start] += 1;
            sums[end] -= 1;

            endOfTime = max(endOfTime, end);
        }
    }

    for (int i = 1; i <= endOfTime; ++i) {
        sums[i] = sums[i - 1] + sums[i];
    }

    int left = 0;
    int right = T - 1;
    int maxSum = 0;
    pair<int, int> maxSection;
    int sum = 0;

    for (int i = 0; i < T; ++i) {
        sum += sums[i];
    }

    maxSum = sum;
    maxSection.first = left;
    maxSection.second = right + 1;

    while (right + 1 <= endOfTime) {
        sum -= sums[left];
        ++left;
        ++right;
        sum += sums[right];

        if (maxSum < sum) {
            maxSum = sum;
            maxSection = make_pair(left, right + 1);
        }
    }

    cout << maxSection.first << " " << maxSection.second;

    return 0;
}