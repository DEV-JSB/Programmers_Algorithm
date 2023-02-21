#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer{ "" };
    int card1Index{ 0 };
    int card2Index{ 0 };

    for (string useWord : goal)
    {
        if (useWord == cards1[card1Index])
        {
            ++card1Index;
            continue;
        }
        else if (useWord == cards2[card2Index])
        {
            ++card2Index;
            continue;
        }
        return "No";
    }

    return "Yes";
}