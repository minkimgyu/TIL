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
        int len = 1;  // ���� ��Ҹ� �����Ͽ� 1���� ����
        // �������� �̵��ϸ� �����ϴ� ��� ����
        while (left >= 0 && nums[left] < nums[left + 1]) {
            len++;
            left--;
        }
        // ���������� �̵��ϸ� �����ϴ� ��� ����
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
    cout << "�ּ� ���� Ƚ��: " << result << endl;
    return 0;
}