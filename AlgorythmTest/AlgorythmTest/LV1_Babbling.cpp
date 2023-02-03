#include <string>
#include <vector>
#include <map>
using namespace std;

#define A 0b0001
#define Y 0b0010
#define W 0b0100
#define M 0b1000

int solution(vector<string> babbling) {
    unsigned char checkBit = 0;
    string canSay[4] = { "aya","ye","woo","ma" };
    int answer = 0;

    for (int i = 0; i < babbling.size();++i)
    {
        checkBit = 0;
        for (int j = 0; j < babbling[i].length();)
        {
            if (babbling[i][j] == "a"
                && babbling[i].substr(j, canSay[0].length()) == canSay[0]
                && !(checkBit & A))
            {
                checkBit = 0;
                checkBit |= A;
                j += canSay[0].length();
            }
            else if (babbling[i][j] == "y"
                && babbling[i].substr(j, canSay[1].length()) == canSay[1]
                && !(checkBit & Y))
            {
                checkBit = 0;

                checkBit |= Y;
                j += canSay[1].length();

            }
            else if (babbling[i][j] == "w"
                && babbling[i].substr(j, canSay[2].length()) == canSay[2]
                && !(checkBit & W))
            {
                checkBit = 0;

                checkBit |= W;
                j += canSay[2].length();

            }
            else if (babbling[i][j] == "m"
                && babbling[i].substr(j, canSay[3].length()) == canSay[3]
                && !(checkBit & M))
            {
                checkBit = 0;

                checkBit |= M;
                j += canSay[3].length();
            }
            else
                break;
            if (j == babbling[i].length())
                ++answer;
        }
    }
    return answer;
}

void main()
{
    solution({ "ayayeaya" });
}