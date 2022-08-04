#include <string>
#include <vector>
#include <map>
using namespace std;

struct ReportInformation
{
    int k;
    int mailCount;
};
int CheckReport(vector<string>& _id, vector<string>& _report, map<string, ReportInformation>& _mapID, vector<int>& _answer)
{
    int BlinkIndex;
    for (size_t i = 0; i < _report.size(); ++i)
    {
        BlinkIndex = _report[i].find(" ") + 1;
        --_mapID[_report[i].substr(BlinkIndex, _report[i].length() - BlinkIndex)].k;
    }
    for (size_t i = 0; i < _id.size(); ++i)
    {
        if (0 >= (*_mapID.find(_id[i])).second.k)
        {
            for (size_t j = 0; j < _report.size(); ++j)
            {
                BlinkIndex = _report[j].find(" ")+1;
                if (_id[i] == _report[j].substr(BlinkIndex, _report[j].length() - BlinkIndex))
                    _mapID[_report[j].substr(0, BlinkIndex-1)].mailCount++;
            }
        }
    }

    for (size_t i = 0; i < _id.size(); ++i)
    {
        _answer.push_back(_mapID[_id[i]].mailCount);
    }

    return 0;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    map<string, ReportInformation> mapID;
    for (size_t i = 0; i < id_list.size(); ++i)
    {
        ReportInformation tmp;
        tmp.k = k;
        tmp.mailCount = 0;
        mapID.insert({ id_list[i],tmp });
    }

    // �� ������ ������ �Ű��� ����� ���͸�
    for (auto iter = report.begin(); iter != report.end(); ++iter)
    {
        for (auto iter2 = iter + 1; iter2 != report.end();)
        {
            if ((*iter) == (*iter2))
                iter2 = report.erase(iter2);
            else
                ++iter2;
        }
    }
    // ���� ���� ���� ���� �ָ� �Ű��� ���� �������� . 
    // �׷��� �Ǹ� ���� ���ڴ� ���� ���� �Ǵ� ���� �ƴұ�?

    // �Ű� �� ��� �������� �߼��� �ϳ�...

    CheckReport(id_list, report, mapID, answer);
    return answer;
}

void main()
{
    solution(vector<string>({ "muzi", "frodo", "apeach", "neo" }), vector<string>({ "muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi" }), 2);
}