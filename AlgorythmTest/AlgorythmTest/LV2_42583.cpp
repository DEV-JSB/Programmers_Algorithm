#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int time = 1;
    int onBridgeWeight = 0;
    queue<int> onBridgeTruck;
    queue<int> passTime;
    queue<int> trucks;

    for (const int& truck : truck_weights)
    {
        trucks.push(truck);
    }


    while (!trucks.empty() || !onBridgeTruck.empty())
    {
        if (!trucks.empty() && bridge_length > onBridgeTruck.size()
            && trucks.front() <= weight - onBridgeWeight)
        {
            onBridgeWeight += trucks.front();
            onBridgeTruck.push(trucks.front());
            passTime.push(time + bridge_length);
            trucks.pop();
            ++time;
        }
        else
        {
            time = passTime.front();
            onBridgeWeight -= onBridgeTruck.front();
            onBridgeTruck.pop();
            passTime.pop();
        }
    }
    return passTime.back();
}
