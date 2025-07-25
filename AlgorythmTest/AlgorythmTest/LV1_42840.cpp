#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> answers) 
{
    vector<int> solutionAnswer;

    vector<vector<int>> students{{1, 2, 3, 4, 5}, { 2,1,2,3,2,4,2,5 }, { 3,3,1,1,2,2,4,4,5,5 }};
    
    int maxCorrectCount = 0;

    vector<int> temp;

    for (int i = 0; i < students.size() ; ++i)
    {
        int studentAnswerIndex = 0;
        int correctCount = 0;
        for (int answer : answers)
        {
            if (answer == students[i][studentAnswerIndex])
            {
                ++correctCount;
            }
            studentAnswerIndex = studentAnswerIndex + 1 >= students[i].size() ? 0 : studentAnswerIndex + 1;
        }
        temp.push_back(correctCount);
        maxCorrectCount = correctCount > maxCorrectCount ? correctCount : maxCorrectCount;
    }

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