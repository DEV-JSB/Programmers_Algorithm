#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer{ 0 };
    int paintedIndex{ 0 };
    if (m == 1)
        return section.size();
    paintedIndex = 0;
    for (int i{ section[0] }; i <= section[(int)section.size() - 1]; i += m - 1)
    {
        while (i >= section[paintedIndex] && answer > 0)
        {
            ++paintedIndex;
            if (paintedIndex >= (int)section.size())
                return answer;
        }
        i = section[paintedIndex];
        ++answer;
    }
    return answer;
}

void main()
{
    solution(8, 4, { 1,2,3,4,7,8,9,10 });
}