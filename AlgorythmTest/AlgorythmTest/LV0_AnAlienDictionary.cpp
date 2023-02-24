#include <string>
#include <vector>

using namespace std;


void copy(int a[26], int b[26])
{
    for (int i = 0; i < 26; ++i)
    {
        b[i] = a[i];
    }
}
bool RemainWordCheck(const int tmp[26])
{
    for (int i = 0; i < 26; ++i)
    {
        if (tmp[i] != 0)
            return true;
    }
    return false;
}
int solution(vector<string> spell, vector<string> dic) {
    bool canMake{ false };
    int spellAppearCount[26]{};
    int spellTmp[26]{};
    for (string str : spell)
    {
        ++spellAppearCount[str[0] - 'a'];
    }
    for (string str : dic)
    {
        canMake = true;
        copy(spellAppearCount, spellTmp);
        for (char c : str)
        {
            if (0 != spellTmp[c - 'a'])
                --spellTmp[c - 'a'];
            else
            {
                canMake = false;
                break;
            }
        }
        if (canMake && !RemainWordCheck(spellTmp))
            return 1;
    }
    return 2;
}