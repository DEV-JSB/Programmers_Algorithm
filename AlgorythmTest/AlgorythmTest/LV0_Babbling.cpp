#include <string>
#include <vector>
#include <map>
using namespace std;


#define A_APEAR 0b0001
#define Y_APEAR 0b0010
#define W_APEAR 0b0100
#define M_APEAR 0b1000

int solution(vector<string> babbling) {
    int answer{ 0 };
    int bitFlag{ 0 };
    bool isRightWord{ false };
    map<char, string> canSayWord{ {'a',"aya"},{'y',"ye"},{'w',"woo"},{'m',"ma"} };

    for (string str : babbling)
    {
        isRightWord = false;
        bitFlag = 0;
        for (int i{ 0 }; i < (int)str.length();)
        {
            if ('a' == str[i] && i + 2 < (int)str.length() && !(bitFlag & A_APEAR))
            {
                if (str.substr(i, canSayWord['a'].length()) == canSayWord['a'])
                {
                    i += 3;
                    bitFlag |= A_APEAR;
                    isRightWord = true;
                }
            }
            else if ('y' == str[i] && i + 1 < (int)str.length() && !(bitFlag & Y_APEAR))
            {
                if (str.substr(i, canSayWord['y'].length()) == canSayWord['y'])
                {
                    i += 2;
                    bitFlag |= Y_APEAR;
                    isRightWord = true;
                }
            }
            else if ('w' == str[i] && i + 2 < (int)str.length() && !(bitFlag & W_APEAR))
            {
                if (str.substr(i, canSayWord['w'].length()) == canSayWord['w'])
                {
                    i += 3;
                    bitFlag |= W_APEAR;
                    isRightWord = true;
                }
            }
            else if ('m' == str[i] && i + 1 < (int)str.length() && !(bitFlag & M_APEAR))
            {
                if (str.substr(i, canSayWord['m'].length()) == canSayWord['m'])
                {
                    i += 2;
                    bitFlag |= M_APEAR;
                    isRightWord = true;
                }
            }
            else
                break;
            if (i == str.length())
            {
                ++answer;
                break;
            }
            else if (!isRightWord)
                break;
        }
    }

    return answer;
}