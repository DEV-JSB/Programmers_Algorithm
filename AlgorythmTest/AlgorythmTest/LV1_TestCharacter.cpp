#include <string>
#include <vector>
#include <map>
using namespace std;

// Survey , ������ RT , CF , JM , AN ���� ������.
// Chioce �� ���� ������ ������ , ������ 2���� �������� �й谡 �ȴ�.

// ���ڿ��� ���� �ڷ����� ����°� ���
// -> stl map �� Ȱ������

// 1 ~ 3 ������ �� ���ڿ��� ������ ���ϰ�
// 5 ~ 7 ������ �� ���ڿ��� ������ ���ؾ� �Ѵ�.

enum class CHARACTER
{
    CHARACTER_R = 82,
    CHARACTER_T = 84,

    CHARACTER_C = 67,
    CHARACTER_F = 70,

    CHARACTER_J = 74,
    CHARACTER_M = 77,

    CHARACTER_A = 65,
    CHARACTER_N = 78,

    CHARACTER_END = 8
};

void InsertMap(std::map<CHARACTER, int>& map_character)
{
    map_character.insert({ CHARACTER::CHARACTER_R,0 });
    map_character.insert({ CHARACTER::CHARACTER_T,0 });

    map_character.insert({ CHARACTER::CHARACTER_C,0 });
    map_character.insert({ CHARACTER::CHARACTER_F,0 });

    map_character.insert({ CHARACTER::CHARACTER_J,0 });
    map_character.insert({ CHARACTER::CHARACTER_M,0 });

    map_character.insert({ CHARACTER::CHARACTER_A,0 });
    map_character.insert({ CHARACTER::CHARACTER_N,0 });

}

void MakeAnswer(std::map<CHARACTER, int>& map_character, string& str_answer)
{
    if (map_character[CHARACTER::CHARACTER_R] >= map_character[CHARACTER::CHARACTER_T])
        str_answer += (char)CHARACTER::CHARACTER_R;
    else
        str_answer += (char)CHARACTER::CHARACTER_T;

    if (map_character[CHARACTER::CHARACTER_C] >= map_character[CHARACTER::CHARACTER_F])
        str_answer += (char)CHARACTER::CHARACTER_C;
    else
        str_answer += (char)CHARACTER::CHARACTER_F;

    if (map_character[CHARACTER::CHARACTER_J] >= map_character[CHARACTER::CHARACTER_M])
        str_answer += (char)CHARACTER::CHARACTER_J;
    else
        str_answer += (char)CHARACTER::CHARACTER_M;

    if (map_character[CHARACTER::CHARACTER_A] >= map_character[CHARACTER::CHARACTER_N])
        str_answer += (char)CHARACTER::CHARACTER_A;
    else
        str_answer += (char)CHARACTER::CHARACTER_N;
    
}

void DisassembleAnswer(std::map<CHARACTER, int>&map_survey,string& str_survey, const int i_choice)
{
    switch (i_choice)
    {
        case 1:
            map_survey[(CHARACTER)str_survey[0]] += 3;
            break;
        case 2:
            map_survey[(CHARACTER)str_survey[0]] += 2;
            break;
        case 3:
            map_survey[(CHARACTER)str_survey[0]] += 1;
            break;
        case 5:
            map_survey[(CHARACTER)str_survey[1]] += 1;
            break;
        case 6:
            map_survey[(CHARACTER)str_survey[1]] += 2;
            break;
        case 7:
            map_survey[(CHARACTER)str_survey[1]] += 3;
            break;
    }
}

string solution(vector<string> survey, vector<int> choices) 
{
    string answer = "";
    std::map<CHARACTER, int> mapCharacterPoint;
    InsertMap(mapCharacterPoint);
    for (size_t i = 0; i < choices.size(); ++i)
        DisassembleAnswer(mapCharacterPoint, survey[i], choices[i]);
    MakeAnswer(mapCharacterPoint, answer);
    return answer;
}