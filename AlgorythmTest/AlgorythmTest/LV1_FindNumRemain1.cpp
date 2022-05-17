#include <string>
#include <vector>
#include<iostream>
using namespace std;

int solution(int n) {
    for (int i = 1; i < n; ++i)
    {
        if (n % i == 1)
            return i;
    }
}

void main()
{
    cout<<solution(10);
}