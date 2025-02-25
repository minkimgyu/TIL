#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDeletionsNoSort(vector<int> nums) {
    int n = nums.size();
    if (n <= 1) {
        return 0;
    }

    int maxLen = 1;
    for (int i = 0; i < n; ++i) {
        int left = i - 1, right = i + 1;
        int len = 1;  // 현재 요소를 포함하여 1부터 시작
        // 왼쪽으로 이동하며 감소하는 요소 세기
        while (left >= 0 && nums[left] < nums[left + 1]) {
            len++;
            left--;
        }
        // 오른쪽으로 이동하며 증가하는 요소 세기
        while (right < n && nums[right - 1] < nums[right]) {
            len++;
            right++;
        }
        maxLen = max(maxLen, len);
    }

    return n - maxLen;
}

int main() {
    vector<int> arr = { 3, 4, 2, 5, 1 };
    int result = minDeletionsNoSort(arr);
    cout << "최소 삭제 횟수: " << result << endl;
    return 0;
}