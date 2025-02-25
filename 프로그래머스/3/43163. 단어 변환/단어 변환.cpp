#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// 최소 몇 단계이므로 BFS를 사용하는 문제
// 변환 가능한 지점들을 찾으면서 순회

// 반례 1. target이 words에 없는 경우

map<string, int> visit;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    queue<string> q;
    q.push(begin);
    
    while(q.empty() == false)
    {
        string front = q.front();
        q.pop();
        int loopCount = visit[front]; // 처음에는 0 출력 이후에는 1 이상 나온다.
        
        vector<string> closeWords;
        for(int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            if(visit[word] > 0) continue; // 이미 방문한 단어는 체크하지 않음
            
            int differentCount = 0;
            for(int j = 0; j < word.size(); j++)
            {
                if(front[j] == word[j]) continue;
                else differentCount++;
            }
            
            if(differentCount == 1) closeWords.push_back(word);
        }
        
        for(int i = 0; i < closeWords.size(); i++)
        {
            if(closeWords[i] == target)
            {
                answer = loopCount + 1;
                return answer;
            }
            
            visit[closeWords[i]] = loopCount + 1;
            q.push(closeWords[i]);
        }
    }
    
    answer = 0;
    return answer;
}