#include <string>
#include <vector>

using namespace std;

vector<string> sort(vector<string> str, int n)
{
    string trash;
    vector<string> tmp = str;
    bool swap = false;
    int minindex;
    for (int i = 0; i < tmp.size() - 1; ++i)
    {
        minindex = i;
        for (int j = i + 1; j < tmp.size(); ++j)
        {
            int k = 1;
            while (tmp[minindex][n] == tmp[j][n])
            {
                if (tmp[j][n + k] < tmp[minindex][n + k])
                {
                    swap = true;
                    minindex = j;
                    break;
                }
                ++k;
            }
            if (tmp[j][n] < tmp[minindex][n])
            {
                swap = true;
                minindex = j;
            }
        }
        if (swap)
        {
            trash = tmp[i];
            tmp[i] = tmp[minindex];
            tmp[minindex] = trash;
            swap = false;
        }
    }
    return tmp;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    answer = sort(strings, n);
    return answer;
}

void main()
{
    vector<string> test;
    test.push_back("sun");
    test.push_back("bed");
    test.push_back("car");
    solution(test, 1);
}