#include <string>
#include <vector>

using namespace std;


int Filter1(string& _id)
{
    for (int i = 0; i < _id.size(); ++i)
    {
        if ('A' <= _id[i] && _id[i] <= 'Z')
            _id[i] += 32;
    }
    return 0;
}
int Filter2(string& _id)
{
    bool erase = false;
    for (int i = 0; i < _id.size();)
    {
        if (!('a' <= _id[i] && _id[i] <= 'z')
            && !('0' <= _id[i] && _id[i] <= '9')
            && !(_id[i] == '-')
            && !(_id[i] == '_')
            && !(_id[i] == '.'))
        {
            _id.erase(i, 1);
        }
        else
            ++i;
    }
    
    return 0;
}

int Filter3(string& _id)
{
    for (int i = 0; i < _id.size();)
    {
        if (_id[i] == '.' && _id[i + 1] == '.')
        {
            _id.erase(i, 1);
        }
        else
            ++i;
    }  
    return 0;

}

int Filter4(string& _id)
{
    if (_id[0] == '.')
        _id.erase(0, 1);
    if (_id[_id.size() - 1] == '.')
        _id.erase(_id.size() - 1, 1);
    return 0;

}

int Filter5(string& _id)
{
    if (0 == _id.size())
        _id += 'a';
    return 0;

}
int Filter6(string& _id)
{
    if(16 <= _id.length())
        _id.erase(15);
    if (_id[14] == '.')
        _id.pop_back();
    return 0;

}
int Filter7(string& _id)
{
    while (_id.length() <= 2)
    {
        _id += _id[_id.length() - 1];
    }
    return 0;

}

string solution(string new_id) {
    string test = new_id;
    Filter1(test);
    Filter2(test);
    Filter3(test);
    Filter4(test);
    Filter5(test);
    Filter6(test);
    Filter7(test);
    return test;
}

void main()
{
    solution(string{ "abcdefghijklmn.p" });
}