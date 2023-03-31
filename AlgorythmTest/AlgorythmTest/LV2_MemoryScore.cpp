#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> scoreMap;
    for (size_t i{ 0 }; i < name.size(); ++i)
        scoreMap.insert({ name[i],yearning[i] });
    for (vector<string> vecPhotos : photo)
    {
        int score{ 0 };
        for (string name : vecPhotos)
            score += scoreMap[name];
        answer.push_back(score);
    }
    return answer;
}