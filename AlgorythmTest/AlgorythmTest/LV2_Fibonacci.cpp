#include <string>
#include <vector>

using namespace std;
#define LEFT 0
#define RIGHT 1
// 0 1 1 2 3 5 8 13 21
// [ 0 , 1 ] -> F(2)
// 더한거 왼쪽에
// [ 1 , 1 ] -> F(3)
// 더한거 오른쪽에
// [ 1 , 2 ] -> F(4)
// 더한거 왼쪽에
// [ 3 , 2 ] -> F(5)
// [ 3 , 5 ] -> F(6)
// [ 0 , 1 ]

int solution(int n) {
    int arr[2] = { 0,1 };
    int saveIndex = LEFT;
    for (int i = 0; i < n - 2; ++i, saveIndex++, saveIndex %= 2)
    {
        arr[saveIndex] = (arr[LEFT] + arr[RIGHT]) % 1234567;
    }
    return (arr[LEFT] + arr[RIGHT]) % 1234567;
}