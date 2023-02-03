#include<string>
#include <iostream>

using std::string;

//()((()))()()()(())(()()()())
//(())()()(
//열렸으면 닫혀야한다.
// 열이 나온 만큼 닫이 나와야 한다!!

// 아닌데 (()()) 이건 어쩔껀데
// (()()((())))
// (()(())())
// 0011 001011
// (()) (()())
// 001011
// (()())
// (()())((()))()()(())
// 00101100011101010011
// 0010110001
// 1100101011
// 확실한건 열린 갯수와 닫힌 갯수가 무조건 같아야 한다.
// 시작은 무조건 ( 로 시작해야한다.
// 열린게 1개를 초과 하고 닫힌게 나왔을 때
bool solution(string s)
{
    if (")" == s[0])
        return false;
    bool bAnswer;
    int openCount = 0;
    int closeCount = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == "(")
            ++openCount;
        else
            --openCount;
        // 우선 닫는 갯수는 절대 열린 갯수를 넘을 수 없다
        if (openCount < 0)
            return false;
    }
    if (0 != openCount)
        return false;
    else
        return true;
}