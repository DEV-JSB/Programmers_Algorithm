#include <string>
#include <vector>
#include <math.h>
#define HAND_LEFT 0
#define HAND_RIGHT 1
#define HAND_BOTH 2
using namespace std;

struct Pos
{
    int x;
    int y;
};

int GetDistance(const Pos& _left, const Pos& _right, const Pos& _pressPos)
{
    int LeftDistance = (abs(_left.x - _pressPos.x) + abs(_left.y - _pressPos.y));
    int RightDistance = (abs(_right.x - _pressPos.x) + abs(_right.y - _pressPos.y));
    if (LeftDistance < RightDistance)
        return HAND_LEFT;
    else if (LeftDistance > RightDistance)
        return HAND_RIGHT;
    else
        return HAND_BOTH;
}

string solution(vector<int> numbers, string hand) 
{
    enum class NUMPAD{ NUMPAD_0 , 
                       NUMPAD_1, NUMPAD_2, NUMPAD_3,
                       NUMPAD_4, NUMPAD_5, NUMPAD_6,
                       NUMPAD_7, NUMPAD_8, NUMPAD_9,
                       NUMPAD_SH, NUMPAD_ST };
    Pos KeyArr[12] = { {1,3},
                       {0,0},{1,0},{2,0},
                       {0,1},{1,1},{2,1},
                       {0,2},{1,2},{2,2},
                       {0,3},{2,3} };
    string answer = "";
    Pos LeftHand = { 0,3 };
    Pos RightHand = { 2,3 };

    for (int i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] == (int)NUMPAD::NUMPAD_1 ||
            numbers[i] == (int)NUMPAD::NUMPAD_4 ||
            numbers[i] == (int)NUMPAD::NUMPAD_7)
        {
            LeftHand = KeyArr[numbers[i]];
            answer += "L";
            continue;
        }
        else if (numbers[i] == (int)NUMPAD::NUMPAD_3 ||
                 numbers[i] == (int)NUMPAD::NUMPAD_6 ||
                 numbers[i] == (int)NUMPAD::NUMPAD_9)
        {
            RightHand = KeyArr[numbers[i]];
            answer += "R";
            continue;
        }
        switch (GetDistance(LeftHand, RightHand, KeyArr[numbers[i]]))
        {
        case HAND_LEFT:
            LeftHand = KeyArr[numbers[i]];
            answer += "L";
            break;
        case HAND_RIGHT:
            RightHand = KeyArr[numbers[i]];
            answer += "R";
            break;
        case HAND_BOTH:
            if (hand == "left")
            {
                LeftHand = KeyArr[numbers[i]];
                answer += "L";
            }
            else
            {
                RightHand = KeyArr[numbers[i]];
                answer += "R";
            }
            break;
        }
    }

    return answer;
}

void main()
{
    solution(std::vector<int>{7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2},"left");
}