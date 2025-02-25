#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long sumVips(vector<int> scores, int guild_count, int k) {
    vector<pair<int, int>> scoreArr;

    for (int i = 0; i < scores.size(); i++) {
        scoreArr.push_back({ scores[i], i });
    }

    // 내림차순 정렬 (기본 설정)
    priority_queue<pair<int, int>> pq(scoreArr.begin(), scoreArr.end());

    long sum = 0;
    while (guild_count--) {
        sum += pq.top().first;
        pq.pop();

        // 필요에 따라 앞뒤 k개 중 하나를 다시 넣어줌
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
    cout << result << endl; // 출력: 51
    return 0;
}