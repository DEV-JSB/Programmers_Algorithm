#include <string>
#include <vector>
#include <map>
using namespace std;

#define KIND 1
#define CLOTHNAME 0

int solution(vector<vector<string>> clothes) {
    int answer{ 1 };
    map<string, int> clothStatistics;
    for (vector<string> cloth : clothes)
    {
        if (clothStatistics.find(cloth[KIND]) == clothStatistics.end())
            clothStatistics.insert({ cloth[KIND],1 });
        else
            ++clothStatistics[cloth[KIND]];
    }
    // 옷을 입을 경우의 수 각자의 옷 종류를 다 입고 , + 1 은 옷을 입지 않을 경우의수이다.
    // 해당 수들을 다 곱함으로써 모든 경우의수를 구한다.
    // 하지만 이때 종류에 아예 옷을 안입는 경우를 제외하기 위해 -1 을 한다

    for (auto iter = clothStatistics.begin(); iter != clothStatistics.end(); ++iter)
        answer *= ((*iter).second + 1);
    return --answer;
}
