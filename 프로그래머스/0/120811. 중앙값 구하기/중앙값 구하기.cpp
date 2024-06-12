#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    sort(array.begin(), array.end());
    int arrSize = array.size();
    
    answer = array[arrSize / 2];
    return answer;
}