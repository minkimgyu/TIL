#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> items;
    
    int ingredientSize = ingredient.size();
    for(int i = 0; i < ingredientSize; i++)
    {
        items.push_back(ingredient[i]);

        int itemSize = items.size();
        if(itemSize >= 4)
        {
            if(items[itemSize - 1] == 1 &&
              items[itemSize - 2] == 3 &&
              items[itemSize - 3] == 2 &&
              items[itemSize - 4] == 1)
            {
                items.pop_back();
                items.pop_back();
                items.pop_back();
                items.pop_back();
                answer++;
            }
        }
    }
    
    return answer;
}