#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int programmerStrings(string s) {
    const string target = "programmer";
    int targetLen = target.length();
    unordered_map<char, int> targetFreq;
    unordered_map<char, int> windowFreq;

    // target 문자열의 각 문자 빈도 계산
    for (char c : target) {
        targetFreq[c]++;
    }

    int left = 0, right = 0;
    // 최솟값을 찾기 위해 무한대로 초기화
    int minLeft = INT_MAX;
    int maxRight = -1;

    while (right < s.length()) {
        char c = s[right];
        windowFreq[c]++;

        // 윈도우 크기가 targetLen보다 커지면 왼쪽 포인터 이동
        if (right - left + 1 > targetLen) {
            windowFreq[s[left]]--;
            left++;
        }

        // 윈도우 안의 문자 빈도가 target과 일치하면 프로그래머 문자열 발견
        if (windowFreq == targetFreq) {
            minLeft = min(minLeft, left);
            maxRight = max(maxRight, right);
        }

        right++;
    }

    // 프로그래머 문자열이 하나도 없으면 -1 반환
    return maxRight == -1 ? -1 : maxRight - minLeft;
}

int main() {
    string s = "programmerxxxprozmerqgram";
    int result = programmerStrings(s);
    cout << result << endl;
    return 0;
}