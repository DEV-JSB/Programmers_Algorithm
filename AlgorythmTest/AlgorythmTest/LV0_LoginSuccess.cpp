#include <string>
#include <vector>

using namespace std;

#define ID 0
#define PASSWORD 1

string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    
    for (int i{ 0 }; i < db.size(); ++i)
    {
        if (db[i][ID] == id_pw[ID] && id_pw[PASSWORD] == db[i][PASSWORD])
            return "login";
        else if (db[i][ID] == id_pw[ID])
            return "wrong pw";
    }
    return "fail";
}