#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
public:
    float avg;
    int order;
    int sortOrder;
};

bool compare(Item a, Item b)
{
    return a.avg > b.avg;
}

bool compare1(Item a, Item b)
{
    return a.order < b.order;
}

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    vector<Item> items;
    
    for(int i = 0; i < score.size(); i++)
    {
        float avg = (float)(score[i][0] + score[i][1]) / (float)2;
        
        Item item;
        item.avg = avg;
        item.order = i;
        
        items.push_back(item);
    }
    
    sort(items.begin(), items.end(), compare);
    
    for(int i = 0; i < items.size(); i++)
    {
        if(i > 0 && items[i].avg == items[i - 1].avg)
        {
            items[i].sortOrder = items[i - 1].sortOrder;
        }
        else
        {
            items[i].sortOrder = i + 1;
        }
    }
    
    sort(items.begin(), items.end(), compare1);
    
    for(int i = 0; i < items.size(); i++)
    {
        answer.push_back(items[i].sortOrder);
    }
    
    return answer;
}