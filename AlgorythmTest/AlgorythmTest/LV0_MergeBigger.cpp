#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int AB = std::stoi((to_string(a) + to_string(b)));
    int BA = std::stoi((to_string(b) + to_string(a)));
    return AB < BA ? BA : AB;
}