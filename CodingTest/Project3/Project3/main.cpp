#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int minTotalWeight(vector<int> weights, int d) {
    priority_queue<int> pq; // 내림차순으로 만들기

    for (int i = 0; i < weights.size(); i++)
    {
        pq.push(weights[i]);
    }

    for (int i = 0; i < d; i++) 
    {
        float heaviest = pq.top();
        int half = floor(heaviest / 2);

        int left = heaviest - half;
        pq.pop();
        pq.push(left);
    }

    int totalWeight = 0;
    while (pq.empty() == false) 
    {
        int top = pq.top();
        totalWeight += top;
        pq.pop();
    }

    return totalWeight;
}

int main() {
    vector<int> weights = { 30, 20, 25 };
    int D = 4;

    int result = minTotalWeight(weights, D);
    cout << "남은 초콜릿의 총 무게: " << result << endl;

    return 0;
}