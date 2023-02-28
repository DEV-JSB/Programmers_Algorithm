#include <string>
#include <vector>

using namespace std;

long long solution(string numbers) {
    long long answer{ 0 };

    for (int i{ 0 }; i < numbers.size();)
    {
        if (numbers[i] == 'z')
        {
            answer += 0;
            i += 4;
        }
        else if (numbers[i] == 'o')
        {
            answer += 1;
            i += 3;
        }
        else if (numbers[i] == 't' && numbers[i + 1] == 'w')
        {
            answer += 2;
            i += 3;
        }
        else if (numbers[i] == 't' && numbers[i + 1] == 'h')
        {
            answer += 3;
            i += 5;
        }
        else if (numbers[i] == 'f' && numbers[i + 1] == 'o')
        {
            answer += 4;
            i += 4;
        }
        else if (numbers[i] == 'f' && numbers[i + 1] == 'i')
        {
            answer += 5;
            i += 4;
        }
        else if (numbers[i] == 's' && numbers[i + 1] == 'i')
        {
            answer += 6;
            i += 3;
        }
        else if (numbers[i] == 's' && numbers[i + 1] == 'e')
        {
            answer += 7;
            i += 5;
        }
        else if (numbers[i] == 'e')
        {
            answer += 8;
            i += 5;
        }
        else if (numbers[i] == 'n')
        {
            answer += 9;
            i += 4;
        }
        answer *= 10;
    }

    return answer / 10;
}