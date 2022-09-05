#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct ReportInformation
{
    int k;
    // 신고를 해서 받는 결과의 메일이다.
    int mailCount;
    // 신고를 한 명단이다.
    vector<string> ReportList;
};
int CheckReport(vector<string>& _id, vector<string>& _report, map<string, ReportInformation>& _mapID, vector<int>& _answer)
{
    bool Overlap = false;;
    int BlinkIndex;
    string ReportString;
    string Reporter;
    // 리포트 명단을 둘러보면서 , 리포트 한 사람의 k 번째 횟수를 차감하는 것 , 
    // 그럼 이 떄 ReportInformation 에 내가 신고한 명단을 넣어놓고 , 내가 신고한 명단만큼만 for 문을 도는게 어떨까?
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

    // 그럼 최종적으로 여기까지 왔으면 , 맵에 내가 신고한 애들의 명단이 들어있고 , 내가 신고 받은 횟수인 k 가 있다 . 


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