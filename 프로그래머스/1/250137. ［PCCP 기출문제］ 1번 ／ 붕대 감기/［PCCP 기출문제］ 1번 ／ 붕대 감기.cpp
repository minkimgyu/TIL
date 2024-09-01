#include <string>
#include <vector>

using namespace std;

const int maxTime = 1000;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int executeTime = bandage[0];
    int healPoint = bandage[1];
    int additionalHealPoint = bandage[2];
    
    int multiSuccess = 0;
    int attackIndex = 0;
    
    int maxHp = health;
    int hp = health;
    
    for(int i = 0; i <= maxTime; i++)
    {
        if(i == attacks[attackIndex][0])
        {
            hp -= attacks[attackIndex][1];
            multiSuccess = 0;
            
            if(hp <= 0)
            {
                answer = -1;
                return answer;
            }
            
            attackIndex++;
            if(attackIndex == attacks.size())
            {
                answer = hp;
                return answer;
            }
        }
        else
        {
            hp += healPoint;
            
            multiSuccess++;
            if(multiSuccess == executeTime)
            {
                hp += additionalHealPoint;
                multiSuccess = 0;
            }
            
            if(hp > maxHp) hp = maxHp;
        }
    }
}