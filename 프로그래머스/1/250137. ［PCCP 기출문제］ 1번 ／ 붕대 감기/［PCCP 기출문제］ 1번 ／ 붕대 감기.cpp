#include <string>
#include <vector>

using namespace std;

const int maxTime = 1000;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int maxContinueHeal = bandage[0];
    int continueHeal = 0;
    int additionalHealPoint = bandage[2];
    
    int healPoint = bandage[1];
    
    int maxHP = health;
    int hp = maxHP;
    
    int attackIndex = 0;
    int maxAttackCount = attacks.size();
    
    for(int i = 0; i <= maxTime; i++)
    {
        int closeAttackTime = attacks[attackIndex][0];
        
        if(closeAttackTime == i)
        {
            int closeAttackDamage = attacks[attackIndex][1];
            hp -= closeAttackDamage;
            if(hp <= 0)
            {
                answer = -1;
                break;
            }
            
            continueHeal = 0;
            // 공격 기능 추가
            attackIndex++;
            if(attackIndex == maxAttackCount)
            {
                answer = hp;
                break;
            }
        }
        else
        {
            hp += healPoint;
            
            continueHeal++;
            if(continueHeal == maxContinueHeal)
            {
                hp += additionalHealPoint;
                continueHeal = 0;
            }
            
            if(hp > maxHP) hp = maxHP;
        }
    }
    
    return answer;
}