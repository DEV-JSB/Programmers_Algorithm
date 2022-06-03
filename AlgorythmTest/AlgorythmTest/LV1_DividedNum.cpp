#include <string>
#include <vector>

using namespace std;


void sort(vector<int>* arr)
{
    int Min = (*arr)[0];
    int tmp = 0;
    
    for (int i = 0; i < arr->size() - 1; ++i)
    {
        Min = i;
        for (int j = i+1; j < arr->size(); ++j)
        {
            if ((*arr)[Min] > (*arr)[j])
            {
                Min = j;
            }
            if (j + 1 == arr->size())
            {
                tmp = (*arr)[Min];
                (*arr)[Min] = (*arr)[i];
                (*arr)[i] = tmp;
                break;
            }
        }
    }
}


vector<int> solution(vector<int> arr, int divisor)
{
    vector<int> answer;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (0 == arr[i] % divisor)
            answer.push_back(arr[i]);
    }
    if (answer.size() == 0)
        answer.push_back(-1);
    else
        sort(&answer);
    return answer;
}
