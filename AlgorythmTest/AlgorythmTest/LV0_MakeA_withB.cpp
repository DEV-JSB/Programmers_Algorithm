#include <string>
#include <vector>

using namespace std;

int solution(string before, string after) {
    int numCount[26]{ 0 };
    for (char c : before)
    {
        ++numCount[c - 'a'];
    }
    for (char c : after)
    {
        if (0 == numCount[c - 'a'])
            return 0;
        else if (0 != numCount[c - 'a'])
            --numCount[c - 'a'];
    }
    return 1;
}