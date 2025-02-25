#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int programmerStrings(string s) {
    const string target = "programmer";
    int targetLen = target.length();
    unordered_map<char, int> targetFreq;
    unordered_map<char, int> windowFreq;

    // target ���ڿ��� �� ���� �� ���
    for (char c : target) {
        targetFreq[c]++;
    }

    int left = 0, right = 0;
    // �ּڰ��� ã�� ���� ���Ѵ�� �ʱ�ȭ
    int minLeft = INT_MAX;
    int maxRight = -1;

    while (right < s.length()) {
        char c = s[right];
        windowFreq[c]++;

        // ������ ũ�Ⱑ targetLen���� Ŀ���� ���� ������ �̵�
        if (right - left + 1 > targetLen) {
            windowFreq[s[left]]--;
            left++;
        }

        // ������ ���� ���� �󵵰� target�� ��ġ�ϸ� ���α׷��� ���ڿ� �߰�
        if (windowFreq == targetFreq) {
            minLeft = min(minLeft, left);
            maxRight = max(maxRight, right);
        }

        right++;
    }

    // ���α׷��� ���ڿ��� �ϳ��� ������ -1 ��ȯ
    return maxRight == -1 ? -1 : maxRight - minLeft;
}

int main() {
    string s = "programmerxxxprozmerqgram";
    int result = programmerStrings(s);
    cout << result << endl;
    return 0;
}