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
    solution(1000000);
}