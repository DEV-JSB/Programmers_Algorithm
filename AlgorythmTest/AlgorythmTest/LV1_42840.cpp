#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> solutionAnswer;

    vector<vector<int>> students{{1, 2, 3, 4, 5}, { 2,1,2,3,2,4,2,5 }, { 3,3,1,1,2,2,4,4,5,5 }};
    
    vector<int> temp;

    for (int i = 0; i < students.size() ; ++i)
    {
        int correctCount = 0;
        for (int answerIndex = 0 ; answerIndex < answers.size() ; ++answerIndex)
        {
            if (answers[answerIndex] == students[i][answerIndex % students[i].size()])
            {
                ++correctCount;
            }
        }
        temp.push_back(correctCount);
    }

    int maxCorrectCount = 0;
    maxCorrectCount = *max_element(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); ++i)
    {
        if (temp[i] == maxCorrectCount)
        {
            solutionAnswer.push_back(i + 1);
        }
    }

    return solutionAnswer;
}

void main()
{
    solution({ 1,2,3,4,5 });
}