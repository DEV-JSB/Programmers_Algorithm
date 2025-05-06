#include <string>
#include <vector>
#include <algorithm>
using namespace std;

enum class Data
{
    Code,
    Date,
    Maximum,
    Remain
};

Data StringToData(const string& str)
{
    if (str == "code")
    {
        return Data::Code;
    }
    else if (str == "date")
    {
        return Data::Date;
    }
    else if (str == "maximum")
    {
        return Data::Maximum;
    }
    else
    {
        return Data::Remain;
    }
}
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) 
{
    vector<vector<int>> answer;

    Data gruopPivot = StringToData(ext);
    Data sortPivot = StringToData(sort_by);
    for (vector<int>data : data)
    {
        if (data[(int)gruopPivot] < val_ext)
        {
            answer.push_back(data);
        }
    }

    switch (sortPivot)
    {
    case Data::Code:
        sort(answer.begin(), answer.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0];});
        break;
    case Data::Date:
        sort(answer.begin(), answer.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1];});
        break;
    case Data::Maximum:
        sort(answer.begin(), answer.end(), [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2];});
        break;
    case Data::Remain:
        sort(answer.begin(), answer.end(), [](const vector<int>& a, const vector<int>& b) { return a[3] < b[3];});
        break;
    }
    

    return answer;
}