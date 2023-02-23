#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int numAppearIndex[26]{};
    int pressCount{};
    for (int i{}; i < keymap.size(); ++i)
    {
        for (int j{}; j < keymap[i].length(); ++j)
        {
            // 0 �̸� �ּ��̹Ƿ� , ������ ������ �ڿ��� ������ ���� ���´�. ( �ּҰ� �ƴϰ� �ȴ�. )
            if (0 == numAppearIndex[keymap[i][j] - 'A']
                || j + 1 < numAppearIndex[keymap[i][j] - 'A'] )
                numAppearIndex[keymap[i][j] - 'A'] = j + 1;
        }
    }
    
    for (int i{}; i < targets.size(); ++i)
    {
        pressCount = 0;
        for (int j{}; j < targets[i].length(); ++j)
        {
            if (0 != numAppearIndex[targets[i][j] - 'A'])
            {
                pressCount += numAppearIndex[targets[i][j] - 'A'];
            }
            else
            {
                answer.push_back(-1);
                break;
            }   
        }
        // ���� else ������ -1 �� �־����� �ߺ����� ���� ��츦 ����Ѵ�
        if (i == answer.size())
            answer.push_back(pressCount);
    }
    

    return answer;
}