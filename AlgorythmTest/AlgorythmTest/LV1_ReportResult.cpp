#include <string>
#include <vector>
#include <map>
using namespace std;

int CheckReport(vector<string>& _id,vector<string>& _report,map<string,int>& _mapID,vector<int>& _answer)
{
    int BlinkIndex;
    for (size_t i = 0; i < _report.size(); ++i)
    {
        BlinkIndex = _report[i].find(" ") + 1;
        --_mapID[_report[i].substr(BlinkIndex, _report[i].length() - BlinkIndex)];
    }

    for (size_t i = 0 ; i < _mapID.size(); ++i)
    {
        if (0 == _mapID[_id[i]])
        {
            for (size_t j = 0; j < _report.size(); ++j)
            {
                BlinkIndex = _report[j].find(" ") + 1;
                if (_id[i] == _report[j].substr(BlinkIndex, _report[j].length() - BlinkIndex))
                {
                    for (size_t k = 0; k < _id.size(); ++k)
                    {
                        if (_id[k] == _report[j].substr(0, BlinkIndex - 1))
                        {
                            ++_answer[k];
                            break;
                        }
                    }
                }
            }
        }
    }

    return 0;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    for (size_t i = 0; i < id_list.size(); ++i)
    {
        answer.push_back(0);
    }

    map<string, int> mapID;
    for (size_t i = 0; i < id_list.size(); ++i)
    {
        mapID.insert({ id_list[i],k });
    }

    // �� ������ ������ �Ű��� ����� ���͸�
    for (auto iter = report.begin(); iter != report.end(); ++iter)
    {
        for (auto iter2 = iter + 1 ; iter2 != report.end();)
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
    solution(vector<string>({ "con", "ryan" }), vector<string>({ "ryan con", "ryan con", "ryan con", "ryan con" }), 3);
}