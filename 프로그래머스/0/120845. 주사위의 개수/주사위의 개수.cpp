#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int answer = 0;
    
    int widthMod = box[0] / n;
    int heightMod = box[1] / n;
    int topMod = box[2] / n;
    
    answer = widthMod * heightMod * topMod;
    return answer;
}