#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer{ 0 };
    std::vector<int> numbers;
    int num{ 0 };
    char nextNumOperator{ ' ' };
    for (char c : my_string)
    {
        if ('0' <= c && c <= '9')
        {
            if (0 != num)
                num *= 10;
            num += c - '0';
        }
        else if (c == '-' || c == '+')
        {
            nextNumOperator == '-' ? numbers.push_back(num * -1) : numbers.push_back(num);
            nextNumOperator = c;
            num = 0;
        }
    }
    for (int i : numbers)
        answer += i;
    nextNumOperator == '-' ? answer += num * -1 : answer += num;


    return answer;
}