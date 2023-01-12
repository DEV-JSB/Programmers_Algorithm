#include <string>
#include <vector>

using namespace std;



int solution(string str1, string str2) {
    int answer = 0;

    for (int i = 0; i < str1.length(); ++i)
    {
        if (str1[i] == str2[0])
        {
            for (int j = 0; j < str2.length(); ++j)
            {
                if (j + 1 == str2.length() && str1[i + j] == str2[j])
                    return 1;
                else if (str1[i + j] != str2[j])
                    break;
            }
        }
    }

    return 2;
}