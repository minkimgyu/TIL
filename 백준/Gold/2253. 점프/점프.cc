#include <vector>
#include <iostream>
#include <cstring>

#define INF 10000

using namespace std;

int stone[10000] = { 0, };   //밟을 수 없는 돌 -1
int DP[10000][150];          //DP[돌번호][점프수]  //돌이 10000개일때도 한번에 점프하는 돌은 150개를 넘지 않음 수열의 합<=10000 해보길
int N, M;

int main() {
    cin >> N >> M;

    int idx;
    for (int i = 0; i < M; i++) {
        cin >> idx;
        stone[idx - 1] = -1;      //인덱스 0부터 시작
    }
    memset(DP, 1, sizeof(DP));    //아주 큰 값(>=10000)으로 초기화. for문을 돌며 INF를 넣는 것과 같은 역할. 후술
    DP[0][0] = 0;

    int tmp;
    for (int i = 1; i < N; i++) {        //DP[돌][점프수]=돌까지의 최소점프횟수
        if (stone[i] == -1) continue;    //stone[]==-1 밟을 수 없는 돌
        for (int x = 1; x <= i && x < 149; x++) {
            tmp = min(DP[i - x][x], min(DP[i - x][x - 1], DP[i - x][x + 1])); //x, x-1, x+1 중 가장 작은 것 선택
                                                                              //i-x가 이전에 x칸 점프했음이 됨

            if (tmp >= 10000) continue;    //DP 값은 10000을 넘을 수 없다. 초기값 상태라 10000을 넘는다면 이전에 x칸을 점프하지 못한 것이니 continue    
            DP[i][x] = tmp + 1;            //이전에 점프한 수 x가 클 수록 좋으므로 x++ 하며 DP를 덮어씌운다
        }                                  //DP 값 자체는 점프 횟수이니 +1만 하면 됨
    }

    int answer = INF;
    for (int x = 1; x < 150; x++) {
        answer = min(answer, DP[N - 1][x]);
    }
    if (answer == INF) cout << -1 << endl;
    else cout << answer << endl;
}