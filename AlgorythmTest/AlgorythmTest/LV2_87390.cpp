#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) 
{
    vector<int> answer;

    int leftColumnIndex = left % n;
    int rightColumnIndex = right % n;
    int startRow = left / n;
    int endRow = right / n;

    for (int y = startRow; y <= endRow; ++y)
    {
        int columNum = y + 1;
        int endColumnIndex = 0;
        endColumnIndex = y == endRow ? rightColumnIndex + 1 : n;
        for (int x = 0; x < endColumnIndex; ++x)
        {
            if (y == startRow && x < leftColumnIndex)
            {
                continue;
            }
            answer.push_back(x < columNum ? columNum : x + 1);

        }
    }


    return answer;
}

void main()
{

    solution(4, 7, 14);
}