#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = false;
    int a = 0;
    int _x = x;
    while (_x)
    {
        a += _x % 10;
        _x /= 10;
    }
    if (x % a == 0)
        answer = true;
    return answer;
}
