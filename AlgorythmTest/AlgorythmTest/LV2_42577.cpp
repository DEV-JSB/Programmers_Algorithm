#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


bool solution(vector<string> phone_book)
{
    sort(phone_book.begin(), phone_book.end());
    for (int i = 0; i < phone_book.size() - 1; ++i)
    {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].length()))
        {
            return false;
        }
    }
    return true;
}

bool solution2(vector<string> phone_book) 
{
    unordered_set<string> hash;
    for (const string str : phone_book)
    {
        hash.insert(str);
    }

    for (int i = 0; i < phone_book.size(); ++i)
    {
        for (int j = 1; j <= 20; ++j)
        {
            string newStr = phone_book[i].substr(0, j);
            if (hash.find(newStr) != hash.end() && phone_book[i].length() != newStr.length())
            {
                return false;
            }
        }
        
    }
    return true;
}

void main()
{
    solution({ "119","97674223","1195524421"});
}