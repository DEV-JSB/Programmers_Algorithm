#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int answer = 0;
    int loopCount = attacks[attacks.size() - 1][0];
    int playerHealth = health;
    int bandagingCount = 0;
    int extraHealAmount = bandage[2];
    int tickHealAmount = bandage[1];
    int maxBandagingTime = bandage[0];
    int attackTimeIndex = 0;

    for (int i = 0; i <= loopCount; ++i)
    {
        if (attacks[attackTimeIndex][0] == i)
        {
            bandagingCount = 0;
            playerHealth -= attacks[attackTimeIndex][1];
            ++attackTimeIndex;
            if (playerHealth <= 0)
            {
                return -1;
            }
        }
        else
        {
            ++bandagingCount;
            if (bandagingCount == maxBandagingTime)
            {
                playerHealth += extraHealAmount;
                bandagingCount = 0;
            }
            playerHealth += tickHealAmount;
            if (playerHealth > health)
            {
                playerHealth = health;
            }
        }
    }


    answer = playerHealth;
    return answer;
}

void main()
{
    solution({ 5, 1, 5 }, 30, {
        {2, 10},
        {9, 15},
        {10, 5},
        {11, 5}
        });
}