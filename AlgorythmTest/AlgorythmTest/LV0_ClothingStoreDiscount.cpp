#include <string>
#include <vector>

using namespace std;

int solution(int price) {
    if (price >= 500000)
    {
        price -= (int)((float)price * 0.2f);
    }
    else if (price >= 300000)
    {
        float test = ((float)price * 0.1f);
        int test2 = ((float)price * 0.1f);

        // 이게 정답이며 , 반올림이 된 후의 값을 원한다?
        int resultTest1 = price - test;
        
        int resultTest2 = price - (int)test;

        int price2 = price;
        // 이게 정답이며 , 반올림이 된 후의 값을 원한다?
        price2 -= ((float)price * 0.1f);
        // 명시적 형변환으로 int 로 바꿔서 뺄셈을 하면 반올림이 되

        price -= (int)((float)price * 0.1f);

    }
    else if (price >= 100000)
    {
        price -= (int)((float)price * 0.05f);
    }

    return price;
}
void main()
{
    solution(312341);
}