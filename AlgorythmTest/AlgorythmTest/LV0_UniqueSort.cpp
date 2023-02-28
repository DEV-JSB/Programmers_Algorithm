#include <string>
#include <vector>

using namespace std;

struct Information
{
    int num;
    int differenceValue;
};

int Abs(const int num)
{
    return num < 0 ? -num : num;
}
vector<int> solution(vector<int> numlist, int n) {
    vector<Information> inform;
    vector<int> answer;
    for (int number : numlist)
        inform.push_back({ number,Abs(number - n) });
    for (int i{0}; i < inform.size() - 1; ++i)
    {
        int minIndex{ i };
        Information tmp{ 0 };
        for (int j{ i }; j < inform.size(); ++j)
        {
            if (inform[j].differenceValue < inform[minIndex].differenceValue)
                minIndex = j;
            else if (inform[j].differenceValue == inform[minIndex].differenceValue)
                minIndex = inform[j].num < inform[minIndex].num ? minIndex : j;
        }
        tmp = inform[minIndex];
        inform[minIndex] = inform[i];
        inform[i] = tmp;
    }
    for (int i{ 0 }; i < inform.size(); ++i)
    {
        answer.push_back(inform[i].num);
    }

    return answer;
}
