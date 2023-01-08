#include <string>
#include <vector>

using namespace std;


struct foodInfo
{
    int idx;
    int count;
};

string solution(vector<int> food) {
    string answer = "";
    vector<foodInfo> counting;
    

    // �غ�� Į�θ��� ������ ����.
    // �غ�� ������ ���� Ƚ���� food /2 �� ����
    // ������ �ѹ����� food[i] �� i + 1 ��° index �̴�.

    for (int i = 0; i < food.size(); ++i)
    {
        if (2 > food[i])
            continue;
        // �켱 ī��Ʈ�� �ؼ� �ִ´�.
        counting.push_back({ i,food[i] / 2 });
    }

    // 1 ��°���� ������ �ִ´�
    for (int i = 0; i < counting.size(); ++i)
    {
        for(int j = 0 ; j < counting[i].count; ++j)
            answer += counting[i].idx + '0';
    }
    answer += '0';
    for (int i = counting.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < counting[i].count; ++j)
            answer += counting[i].idx + '0';
    }

    return answer;
}

void main()
{
    solution({1,3,4,6});
}