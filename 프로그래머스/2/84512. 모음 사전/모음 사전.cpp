#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int maxSize = 5;

char arr[maxSize]; 
char alpha[maxSize] = {'A', 'E', 'I', 'O', 'U'};
int result = 0;

int loopCount = 0;

void dfs(int count, string words)
{
    loopCount++;
    
    if(count == maxSize)
    {
         return;
    }
    else
    {
        for(int i = 0; i < maxSize; i++)
        {
            arr[count] = alpha[i];

            if(words.size() - 1 == count) // 결과값과 개수가 같은 경우만 비교함
            {
                bool isCorrect = true;
                for(int j = 0; j < words.size(); j++)
                {
                    cout << arr[j] << " ";

                    if(words[j] != arr[j])
                    {
                        isCorrect = false;
                    }
                }
                // cout << " " << loopCount << "\n";

                if(isCorrect == true)
                {
                    result = loopCount;
                }
            }
             
            dfs(count + 1, words);
        }
    }
}

int solution(string word) {
    dfs(0, word);
    return result;
}