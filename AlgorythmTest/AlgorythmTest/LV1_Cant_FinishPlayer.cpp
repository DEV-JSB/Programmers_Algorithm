#include <string>
#include <vector>
#include<algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    int i = 0;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (i; i < participant.size(); ++i)
    {
        if (i == participant.size() - 1)
            break;
        if (participant[i] != completion[i])
            break;
    }
    answer = participant[i];
    return answer;
}
