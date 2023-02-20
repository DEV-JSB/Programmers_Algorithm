#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    // 여기서 추가로 sides 가 둘 다 같을 경우에는 다르게 구해야 한다.
    //if (sides[0] == sides[1])
    //{
    //    // 둘 다 같은 경우에는 그냥 sides[1] 의 값을 반환해도 된다.
    //    // 이등변 ~ 정 삼각형까지의 값이니까
    //    return sides[0];
    //}
    int answer = 0;
    // 가장 긴 변의 길이는 다른 두 변의 길이의 합보다 작아야 한다.
    // sides에서 한 변이 가장 길거나 , 경우의수를 구하는 변이 가장 길거나.
    // 둘 중 하나인가?? ㅇㅇ

    // 우선 sides 에 없는 변이 가장 길 경우에는 
    // sides[0] + sides[1] 보다 작아야 하고 , 두 인덱스 중 큰 변 보다 크거나 같아야한다.

    // sides 에 있는 변들 중 하나가 제일 큰거라고 치면
    // 경우의 수는 sides[작은거] + ? < sides[큰변] 이어야 한다.
    // 크거나 같아도 되지만 그건 위에 케이스에서 크거나 같거를 선언했으므로 
    // 이등변 삼각형이 될 경우는 위에서 이미 고려한 셈

    // 우선 둘 중 크고 작은 인덱스를 구한다
    int bigIndex{ sides[0] < sides[1] ? 1 : 0 };
    int minIndex{ bigIndex == 1 ? 0 : 1 };

    for (int i = 1; i <= sides[bigIndex]; ++i)
    {
        if (i + sides[minIndex] > sides[bigIndex])
            ++answer;
    }
    for (int i = sides[bigIndex] + 1 ; sides[minIndex] + sides[bigIndex] > i; ++i)
    {
        ++answer;
    }
    return answer;
}