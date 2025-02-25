#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long sumVips(vector<int> scores, int guild_count, int k) {
    vector<pair<int, int>> scoreArr;

    for (int i = 0; i < scores.size(); i++) {
        scoreArr.push_back({ scores[i], i });
    }

    // �������� ���� (�⺻ ����)
    priority_queue<pair<int, int>> pq(scoreArr.begin(), scoreArr.end());

    long sum = 0;
    while (guild_count--) {
        sum += pq.top().first;
        pq.pop();

        // �ʿ信 ���� �յ� k�� �� �ϳ��� �ٽ� �־���
        if (pq.size() >= k) {
            pq.push(scoreArr[k - 1]);
        }
    }

    return sum;
}
int main() {
    vector<int> score = {8, 21, 8, 15, 5, 30, 21};
    int guilder_count = 2;
    int k = 3;

    int result = sumVips(score, guilder_count, k);
    cout << result << endl; // ���: 51
    return 0;
}