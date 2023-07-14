#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int stringCombine = std::stoi((to_string(a) + to_string(b)));
    int multipleValue = 2 * a * b;
    return stringCombine <= multipleValue ? multipleValue : stringCombine;
}