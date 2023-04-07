#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> peoples;
    for (int i{ 0 };i < players.size();++i)
        peoples.insert({ players[i],i + 1 });

    for (string callingPeople : callings)
    {
        ++peoples[players[peoples[callingPeople] - 2]];
        --peoples[callingPeople];
        string tmp{ players[peoples[callingPeople] - 1] };
        players[peoples[callingPeople] - 1] = callingPeople;
        players[peoples[callingPeople]] = tmp;
    }

    return players;
}
void main()
{
    solution({ "mumu", "soe", "poe", "kai", "mine" }, { "kai", "kai", "mine", "mine" });
}