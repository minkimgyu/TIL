#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    for(int i = 0; i < array.size(); i++)
    {
        if(array[i] == 7)
        {
            answer++;
            continue;
        }
        
        int mod = 10;
        int total = 0;
        
        while(1)
        {
            if(mod > array[i])
            {
                int item = ((array[i] % mod) - total) / (mod / 10);
                if(item == 7) answer++;
                break;
            }

            int item = ((array[i] % mod) - total) / (mod / 10);
            if(item == 7) answer++;
            mod *= 10;
        }
    }
    
    return answer;
}