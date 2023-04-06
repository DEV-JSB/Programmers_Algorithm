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
    // ���� ���� ����� �� ������ �� ������ �� �԰� , + 1 �� ���� ���� ���� ����Ǽ��̴�.
    // �ش� ������ �� �������ν� ��� ����Ǽ��� ���Ѵ�.
    // ������ �̶� ������ �ƿ� ���� ���Դ� ��츦 �����ϱ� ���� -1 �� �Ѵ�

    for (auto iter = clothStatistics.begin(); iter != clothStatistics.end(); ++iter)
        answer *= ((*iter).second + 1);
    return --answer;
}
