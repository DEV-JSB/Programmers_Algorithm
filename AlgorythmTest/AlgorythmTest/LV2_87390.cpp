#include <string>
#include <vector>
#include <iostream>
using namespace std;


void PrintStar(int n)
{

    for (int i = 0 ; i < n * n ; i += n)
    {
        for (int j = i; j < i + n ; ++j)
        {
            if (j / n < j % n)
                cout << "%";
            else
                cout << "\\";
        }
        cout << "\n";
    }
}

void main()
{

    PrintStar(4);
}