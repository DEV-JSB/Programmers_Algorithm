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
            if(tmp[minindex][n] == tmp[j][n])
            {
                if (tmp[minindex] == tmp[j])
                    break;
                for (int k = 0; k < tmp[minindex].size(); ++k)
                {
                    if (tmp[j][k] > tmp[minindex][k])
                        break;
                    else if (tmp[j][k] < tmp[minindex][k])
                    {
                        swap = true;
                        minindex = j;
                        break;
                    }
                    else if (k == tmp[minindex].size() - 1)
                    {
                        if (tmp[minindex].size() > tmp[j].size())
                        {
                            swap = true;
                            minindex = j; 
                            break;
                        }
                    }
                }
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

