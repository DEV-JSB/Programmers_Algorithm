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

        // �̰� �����̸� , �ݿø��� �� ���� ���� ���Ѵ�?
        int resultTest1 = price - test;
        
        int resultTest2 = price - (int)test;

        int price2 = price;
        // �̰� �����̸� , �ݿø��� �� ���� ���� ���Ѵ�?
        price2 -= ((float)price * 0.1f);
        // ����� ����ȯ���� int �� �ٲ㼭 ������ �ϸ� �ݿø��� ��

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