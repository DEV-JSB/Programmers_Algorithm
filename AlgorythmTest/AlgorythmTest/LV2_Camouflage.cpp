#include <string>
#include <vector>
#include <map>
using namespace std;

#define KIND 1
#define NAME 0
int solution(vector<vector<string>> clothes) {
    int answer{ 1 };
    map<string, int> mapClothes;
    for (size_t i{ 0 }; i < clothes.size(); ++i)
    {
      if (mapClothes.find(clothes[i][KIND]) == mapClothes.end())
          mapClothes.insert({ clothes[i][KIND],1 });
      else
          ++mapClothes[clothes[i][KIND]];
    }
    for (auto iter = mapClothes.begin(); iter != mapClothes.end(); ++iter)
    {
        answer *= ((*iter).second + 1);
    }
    return --answer;
}
void main()
{
    solution({ {"a", "headgear"},{"b", "headgear"},{"c", "face"},{"d", "face"} ,{"e", "google"} });
}