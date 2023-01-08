#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int scores[9]{};
    int inBoxCount = 0;

    // ����� m �� ��´�
    // socre �� �ּ� ���ݿ� ���� ������ ������ ��������.

    // ���ڰ� ��������� ��� �ؾ��ұ�?
    // ���ڰ� ��������... ���� �ѰŸ� ��ź ó���� �ؾ��ϴµ�

    // �ִ��� �������� ���ڿ� �������� ������ �ɵ�
    

    // ������ index �� �����Ѵ�.
    for(int i = 0 ; i < score.size() ; ++i)
        ++scores[score[i] - 1];

    for (int i = 0; i < score.size() / m;)
    {
        for (int j = 9 - 1; -1 < j ;)
        {
            if (scores[j] != 0)
            {
                ++inBoxCount;
                scores[j]--;
            }
            if ((i + 1) * m == inBoxCount)
            {
                ++i;
                answer += m * (j + 1);
                break;
            }
            if(0 == scores[j])
                --j;
        }
    }

    return answer;
}

void main()
{
    solution(3, 4, { 1,2,3,1,2,3 });
}