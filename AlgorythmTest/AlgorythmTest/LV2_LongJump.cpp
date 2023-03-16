#include <string>
#include <vector>

using namespace std;



void DFS(const int n ,int number , int addNum ,long long & answer)
{
    number += addNum;
    if (n == number || n < number)
    {
        if (n == number)
            ++answer;
        if (answer > 1234567)
            answer %= 1234567;
        return;
    }
    DFS(n, number,1, answer);
    DFS(n, number,2 , answer);
}

long long solution(int n) {
    long long answer = 0;
    DFS(n, 0,0, answer);
    return answer;
}
void main()
{
    solution(4);
}