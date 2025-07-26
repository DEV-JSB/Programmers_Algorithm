#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) 
{
    vector<vector<int>> answer;

    answer.assign(arr1.size(), vector<int>(arr2[0].size(), 0));

    for (int i = 0; i < arr1.size(); ++i)
    {
        for (int j = 0; j < arr2[0].size(); ++j)
        {
            for (int k = 0; k < arr1[i].size(); ++k)
            {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}



void main()
{
    vector<vector<int>> arr1 = { {2, 3, 2}, {4, 2, 4}, {3, 1, 4} };
    vector<vector<int>> arr2 = { {5, 4, 3}, {2, 4, 1}, {3, 1, 1} };

    vector<vector<int>> result = solution(arr1, arr2);
}