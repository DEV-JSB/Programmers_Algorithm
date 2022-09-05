#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct ReportInformation
{
    int k;
    // �Ű� �ؼ� �޴� ����� �����̴�.
    int mailCount;
    // �Ű� �� ����̴�.
    vector<string> ReportList;
};
int CheckReport(vector<string>& _id, vector<string>& _report, map<string, ReportInformation>& _mapID, vector<int>& _answer)
{
    bool Overlap = false;;
    int BlinkIndex;
    string ReportString;
    string Reporter;
    // ����Ʈ ����� �ѷ����鼭 , ����Ʈ �� ����� k ��° Ƚ���� �����ϴ� �� , 
    // �׷� �� �� ReportInformation �� ���� �Ű��� ����� �־���� , ���� �Ű��� ��ܸ�ŭ�� for ���� ���°� ���?
    for (size_t i = 0; i < _report.size(); ++i)
    {
        BlinkIndex = _report[i].find(" ") + 1;
        ReportString = _report[i].substr(BlinkIndex, _report[i].length() - BlinkIndex);
        Reporter = _report[i].substr(0, BlinkIndex - 1);
        Overlap = false;

        auto iter = find(_mapID[Reporter].ReportList.begin(), _mapID[Reporter].ReportList.end(), ReportString);
        if (iter != _mapID[Reporter].ReportList.end())
            Overlap = true;
        if (!Overlap)
        {
            --_mapID[_report[i].substr(BlinkIndex, _report[i].length() - BlinkIndex)].k;
            _mapID[Reporter].ReportList.push_back(ReportString);
        }
    }

    // �׷� ���������� ������� ������ , �ʿ� ���� �Ű��� �ֵ��� ����� ����ְ� , ���� �Ű� ���� Ƚ���� k �� �ִ� . 


    for (auto iter = _mapID.begin(); iter != _mapID.end(); ++iter)
    {
        for (size_t i = 0; i < (*iter).second.ReportList.size(); ++i)
        {
            if (_mapID[(*iter).second.ReportList[i]].k <= 0)
                ++(*iter).second.mailCount;
        }
    }

    /*for (size_t i = 0; i < _id.size(); ++i)
    {
        if (0 >= (*_mapID.find(_id[i])).second.k)
        {
            for (size_t k = 0; k < _id.size(); ++k)
            {
                if (_id[i] == _id[k])
                    continue;
                for (size_t j = 0; j < _mapID[_id[k]].ReportList.size(); ++j)
                {
                    if (_mapID[_id[k]].ReportList[j] == _id[i])
                        _mapID[_id[k]].mailCount++;
                }
            }
        }
    }*/
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

    CheckReport(id_list, report, mapID, answer);
    return answer;
}