#include <string>
#include <vector>
#include <map>
using namespace std;

#define KIND 1
#define NAME 0
int solution(vector<vector<string>> clothes) {
    int answer = 0;
    map<string, int> mapClothes;
    bool isOnlyOneKindOfClothes{ true };
    for (size_t i{ 0 }; i < clothes.size(); ++i)
    {
      if (mapClothes.find(clothes[i][KIND]) == mapClothes.end())
          mapClothes.insert({ clothes[i][KIND],1 });
      else
      {
          isOnlyOneKindOfClothes = false;
          ++mapClothes[clothes[i][KIND]];
      }
    }

    if (isOnlyOneKindOfClothes)
        return mapClothes.size();
    else if (mapClothes.size() == 1)
        return (*mapClothes.begin()).second;

    int clothCount{0};
    int combinationCount{ 0 };
    int allCombinationCount{ 1 };
    for (auto iter = mapClothes.begin() ; iter != mapClothes.end(); ++iter)
        clothCount += (*iter).second;
    for (auto iter = mapClothes.begin(); iter != mapClothes.end(); ++iter)
    {
        allCombinationCount *= (*iter).second;
        for (map<string, int>::iterator iter2 = iter; iter2 != mapClothes.end(); ++iter2)
        {
            if (iter == iter2)
                continue;
            else
                combinationCount += (*iter).second * (*iter2).second;
        }
    }
    answer += clothCount + combinationCount + allCombinationCount;
    return answer;
}
void main()
{
    solution({ {"a", "headgear"},{"b", "headgear"},{"c", "face"},{"d", "face"} ,{"e", "google"} });
}