#include <iostream>
#include <string>
using namespace std;


// ���� Ǭ C++ Ǯ�� 

int main(void) {
    int a;
    int b;
    string str = {};
    cin >> a >> b;
    for (int i = 0; i < a; ++i)
    {
        str += '*';
    }
    for (int j = 0; j < b; ++j)
    {
        cout << str << endl;
    }

    return 0;
}

// ���� Ǭ C Ǯ��

#include <stdio.h>

int main(void) {
    int a;
    int b;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < b; ++i)
    {
        for (int i = 0; i < a; ++i)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}