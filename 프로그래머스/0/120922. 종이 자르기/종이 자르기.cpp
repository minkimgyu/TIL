#include <string>
#include <vector>

using namespace std;

int solution(int M, int N) {
    int answer = 0;
    
    int rowCut = M - 1;
    int columnCut = M * (N - 1);
    
    answer = rowCut + columnCut;
    
    return answer;
}