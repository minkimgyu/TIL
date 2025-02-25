#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int findTotalScore(vector<int> scores, int guilder_count, int k) {
    deque<int> dq(scores.begin(), scores.end());
    int totalScore = 0;

    for (int i = 0; i < guilder_count; ++i) {
        int leftMax = INT_MIN, rightMax = INT_MIN;
        int leftIdx = 0, rightIdx = dq.size() - 1;

        // 앞쪽 k개와 뒤쪽 k개 중 최댓값 찾기
        for (int j = 0; j < k && leftIdx < dq.size(); ++j) {
            leftMax = max(leftMax, dq[leftIdx]);
            rightMax = max(rightMax, dq[rightIdx]);
            leftIdx++;
            rightIdx--;
        }

        // 최댓값 선택 및 제거
        int maxScore = max(leftMax, rightMax);
        if (leftMax == maxScore) {
            dq.pop_front();
        }
        else {
            dq.pop_back();
        }
        totalScore += maxScore;
    }

    return totalScore;
}

int main() {
    vector<int> scores = { 8, 21, 8, 15, 5, 30, 21 };
    int guilder_count = 2;
    int k = 3;

    int result = findTotalScore(scores, guilder_count, k);
    cout << "제거된 기여도 점수의 총합: " << result << endl;

    return 0;
}