#include <string>
#include <vector>
#include <math.h>
using namespace std;

#define START 0
#define END 1

int solution(vector<vector<int>> lines) {
    int answer = 0;
    // 시작과 끝의 범위를
    // 비교대상이 내부에 포함이 되어 있는가?
    vector<vector<int>> OverlapedLines;
    // 선분은 3개가 있고
    // 검사는 최소 3 번 밖에 필요하지 않는다
    for (int i = 0; i < lines.size() -1; ++i)
    {
        for (int j = i + 1; j < lines.size(); ++j)
        {
            // ------------------------
            //      -------------
            if (lines[i][START] <= lines[j][START]
                && lines[j][END] <= lines[i][END])
            {
                OverlapedLines.push_back({ lines[j][START] ,lines[j][END]});
            }
            //          -----
            // ------------------
            else if(lines[j][START] <= lines[i][START]
                && lines[i][END] <= lines[j][END])
            {
                OverlapedLines.push_back({ lines[i][START] ,lines[i][END] });
            }
            // -----------
            //      -------------
            else if (lines[i][START] < lines[j][START]
                && lines[j][START] < lines[i][END])
                OverlapedLines.push_back({ lines[j][START],lines[i][END] });
            //          ------------
            //  --------------
            else if (lines[i][END] > lines[j][END]
                && lines[i][START] < lines[j][END])
                OverlapedLines.push_back({ lines[i][START] ,lines[j][END] });
        }
    }

    for (int i = 0; i < OverlapedLines.size(); ++i)
    {
        for (int j = i + 1; j < OverlapedLines.size(); ++j)
        {
            if (OverlapedLines[j][START] <= OverlapedLines[i][START]
                && OverlapedLines[i][END] <= OverlapedLines[j][END])
            {
                OverlapedLines[i][END] = 0; 
                OverlapedLines[i][START] = 0;
                continue;
            }
            // -----------
            //      -------------
            else if (OverlapedLines[i][START] <= OverlapedLines[j][START]
                && OverlapedLines[j][START] <= OverlapedLines[i][END])
                OverlapedLines[i][END] = OverlapedLines[j][START];
            //          ------------
            //  --------------
            else if (OverlapedLines[i][END] >= OverlapedLines[j][END]
                && OverlapedLines[i][START] <= OverlapedLines[j][END])
                OverlapedLines[i][START] = OverlapedLines[j][END];
        }
        answer += OverlapedLines[i][END] - OverlapedLines[i][START];
    }

    return answer;
}

void main()
{
    solution({ {1,4},{0,10},{-5,9} });
}