#include <string>
#include <vector>

using namespace std;
#define LEFT 0
#define RIGHT 1
// 0 1 1 2 3 5 8 13 21
// [ 0 , 1 ] -> F(2)
// ���Ѱ� ���ʿ�
// [ 1 , 1 ] -> F(3)
// ���Ѱ� �����ʿ�
// [ 1 , 2 ] -> F(4)
// ���Ѱ� ���ʿ�
// [ 3 , 2 ] -> F(5)
// [ 3 , 5 ] -> F(6)
// [ 0 , 1 ]
int fibonacci(int n)
{
    int add[4] = { 0, 1, 0, 0 };

    for (int i = 2; i <= n; ++i)
        add[3] = add[i % 3] = ((add[(i - 2) % 3]) + (add[(i - 1) % 3])) % 1234567;

    return add[3];
}
