#include <numeric>
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> arr) {
    return accumulate(arr.begin(), arr.end(), string(""));
}