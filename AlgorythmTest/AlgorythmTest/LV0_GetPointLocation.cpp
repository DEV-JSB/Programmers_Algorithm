#include <string>
#include <vector>

#define X 0 
#define Y 1 

using namespace std;

int solution(vector<int> dot) {
    if (dot[X] > 0 && dot[Y] > 0)
        return 1;
    else if (dot[X] < 0 && dot[Y] < 0)
        return 3;
    else if (dot[X] > 0 && dot[Y] < 0)
        return 4;
    else
        return 2;
}