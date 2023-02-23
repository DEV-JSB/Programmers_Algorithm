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
            // 0 이면 최소이므로 , 무작정 넣으면 뒤에서 출현한 값이 나온다. ( 최소가 아니게 된다. )
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
        // 위의 else 문에서 -1 을 넣었을시 중복으로 넣일 경우를 대비한다
        if (i == answer.size())
            answer.push_back(pressCount);
    }
    

    return answer;
}