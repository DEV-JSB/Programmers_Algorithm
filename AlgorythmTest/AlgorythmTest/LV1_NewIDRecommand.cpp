#include <string>
#include <vector>

using namespace std;



int PopBack(string& _id)
{
    for (int i = _id.size() - 1; i >= 0; --i)
    {
        if(NULL == _id[i])
            _id.pop_back();
    }
    return 0;
}


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
    for (int i = 0; i < _id.size(); ++i)
    {
        if (!('a' <= _id[i] && _id[i] <= 'z')
                            && !(_id[i] == '-')
                            && !(_id[i] == '_')
                            && !(_id[i] == '.'))
        {
            for (int j = i; j < _id.size(); ++j)
                _id[j] = _id[j + 1];
            --i;
        }
    }
    
    return 0;
}

int Filter3(string& _id)
{
    for (int i = 0; i < _id.size(); ++i)
    {
        if (_id[i] == '.' && _id[i+1] == '.')
        {
            for (int j = i + 1; j < _id.size() - 1; ++j)
                _id[j] = _id[j + 1];
            --i;
        }
    }  
    return 0;

}

int Filter4(string& _id)
{
    if (_id[0] == '.')
    {
        for (int j = 0; j < _id.size() - 1; ++j)
            _id[j] = _id[j + 1];
    }
    if (_id[_id.size() - 1] == '.')
        _id[_id.size() - 1] = NULL;
    return 0;

}

int Filter5(string& _id)
{
    for (int i = 0; i < _id.size(); ++i)
    {
        if (_id[i] == ' ')
            _id[i] = 'a';
    }
    return 0;

}
int Filter6(string& _id)
{
    int Removesize = _id.size() - 15;
    for (int i = 0; i < Removesize; ++i)
        _id.pop_back();
    return 0;

}
int Filter7(string& _id)
{
    while (_id.length() <= 2)
    {
        _id[_id.length()] = _id[_id.length() - 1];
    }
    return 0;

}

string solution(string new_id) {
    string test = new_id;
    Filter1(test);
    PopBack(test);
    Filter2(test);
    PopBack(test);
    Filter3(test);
    PopBack(test);
    Filter4(test);
    PopBack(test);
    Filter5(test);
    PopBack(test);
    Filter6(test);
    PopBack(test);
    return test;
}

void main()
{
    solution(string{ "z-+.^." });
}