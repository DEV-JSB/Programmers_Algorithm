#include <string>
#include <vector>
#include <set>
#include <math.h>
#include<iostream>
using namespace std;

int TheFirstNegativeNumber(vector<int> num_list) {
    for (int i = 0; i < num_list.size(); ++i)
    {
        if (num_list[i] < 0)
            return i;
    }
    return -1;
}

vector<int> AddElementsArray(vector<int> arr) {
    vector<int> answer;

    for (int num : arr)
    {
        for (int i = 0; i < num; ++i)
        {
            answer.insert(answer.end(), arr[i], arr[i]);
        }
    }

    return answer;
}

int AddSpecificSum(int a, int d, vector<bool> included) {
    int answer = 0;
    int num = a;
    for (int i = 0; i < included.size(); ++i)
    {
        if (included[i])
            answer += num;
        num += d;
    }
    return answer;
}

int DiceGame2(int a, int b, int c) {
    int answer = 0;
    set<int> s{ a,b,c };
    if (3 == s.size())
    {
        answer = (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2)) * (pow(a, 3) + pow(b, 3) + pow(c, 3));
    }
    else if (2 == s.size())
    {
        answer = (a + b + c) * (pow(a, 2) + pow(b, 2) + pow(c, 2));
    }
    else
        answer = a + b + c;
    return answer;
}

int ProductAndSumOfElements(vector<int> num_list) {
    int multipleValue = 1;
    int plusValue = 0;
    for (int num : num_list)
    {
        multipleValue *= num;
        plusValue += num;
    }
    plusValue *= plusValue;
    return plusValue < multipleValue ? 0 : 1;
}

int StickOddEvenNum(vector<int> num_list) {
    int answer = 0;
    int oddSum = 0;
    int evenSum = 0;
    for (int num : num_list)
    {
        if (0 == num % 2)
        {
            evenSum += num;
            evenSum *= 10;
        }
        else
        {
            oddSum += num;
            oddSum *= 10;
        }
    }
    oddSum /= 10;
    evenSum /= 10;
    answer = oddSum + evenSum;
    return answer;
}

vector<int> LastTwoElements(vector<int> num_list) {
    int lastNum = num_list[num_list.size() - 1];
    int lastBackNum = num_list[num_list.size() - 2];
    
    num_list.push_back(lastBackNum < lastNum ? lastNum - lastBackNum : lastNum * 2);
    return num_list;
}

int NumControl1(int n, string control) {
    int answer = n;
    for (char c : control)
    {
        switch (c)
        {
        case 'w':
            ++answer;
            break;
        case 's':
            --answer;
            break;
        case 'd':
            answer += 10;
            break;
        case 'a':
            answer -= 10;
            break;
        }
    }
    return answer;
}

string NumControl2(vector<int> numLog) {
    string answer = "";

    for (int i = 1; i < numLog.size(); ++i)
    {
        int minValue = numLog[i] - numLog[i - 1];
        if (minValue == 1)
            answer.push_back('w');
        else if (minValue == -1)
            answer.push_back('s');
        else if (minValue == 10)
            answer.push_back('d');
        else if (minValue == -10)
            answer.push_back('a');
    }

    return answer;
}

vector<int> 수열과구간쿼리3(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    answer = arr;
    for (vector<int> querie : queries)
    {
        int tmp = answer[querie[0]];
        answer[querie[0]] = answer[querie[1]];
        answer[querie[1]] = tmp;
    }
    return answer;
}


vector<int> 수열과구간쿼리2(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;

    for (vector<int> querie : queries)
    {
        bool findBigNum = false;
        int inQuerieCompareNum = querie[2];
        int bigNum = 1000000;
        for (int i = querie[0]; i <= querie[1]; ++i)
        {
            if (inQuerieCompareNum < arr[i] && arr[i] < bigNum)
            {
                findBigNum = true;
                bigNum = arr[i];
            }
        }
        if (findBigNum)
            answer.push_back(bigNum);
        else
            answer.push_back(-1);
    }

    return answer;
}

vector<int> 수열과구간쿼리4(vector<int> arr, vector<vector<int>> queries) {
    for (vector<int> querie : queries)
    {
        for (int i = 0; i < arr.size() ; ++i)
        {
            if ((querie[0] <= i && i <= querie[1])
                && (i == 0 || i % querie[2] == 0))
            {
                ++arr[i];
            }
        }
    }
    return arr;
}

bool IsOnlyFiveAndZero(int num)
{
    while (num)
    {
        int tmp = num % 10;
        if (tmp != 0 && tmp != 5)
            return false;
        num /= 10;
    }
    return true;
}
vector<int> 배열만들기2(int l, int r) {
    vector<int> answer;
    int startNum = l % 5 != 0 ? l + (5 - (l % 5)) : l;
    for (int i = startNum ; i <= r; i += 5)
    {
        if (IsOnlyFiveAndZero(i))
            answer.push_back(i);
    }
    if (answer.empty())
        answer.push_back(-1);
    return answer;
}


vector<int> 카운트업(int start, int end) {
    vector<int> answer;
    for (int i = start; i <= end; ++i)
        answer.push_back(i);
    return answer;
}

vector<int> 콜라츠수열만들기(int n) {
    vector<int> answer;
    answer.push_back(n);
    while (n != 1)
        answer.push_back(n % 2 == 0 ? n /= 2 : ++(n *= 3));
    return answer;
}

vector<int> 배열만들기4(vector<int> arr) {
    vector<int> stk;
    int i = 0;
    while (i < arr.size())
    {
        if (stk.empty())
        {
            stk.push_back(arr[i]);
            ++i;
        }
        else if (stk.back() < arr[i])
        {
            stk.push_back(arr[i]);
            ++i;
        }
        else if (stk.back() >= arr[i])
            stk.pop_back();
    }
    return stk;
}

bool 간단한논리연산(bool x1, bool x2, bool x3, bool x4) {
    return (x1 || x2) && (x3 || x4);
}


int GetScore(const int a, const int b, const int c,const int d)
{
    int number[4]{ a,b,c,d };
    int sameCount[4]{ 0 };
    int same = 0;
    if (a == b)
    {
        ++sameCount[0];
        ++sameCount[1];
        ++same;
    }
    if (a == c)
    {
        ++sameCount[0];
        ++sameCount[2];
        ++same;
    }
    if (a == d)
    {
        ++sameCount[0];
        ++sameCount[3];
        ++same;
    }
    if (b == c)
    {
        ++sameCount[1];
        ++sameCount[2];
        ++same;
    }
    if (b == d)
    {
        ++sameCount[1];
        ++sameCount[3];
        ++same;
    }
    if (c == d)
    {
        ++sameCount[2];
        ++sameCount[3];
        ++same;
    }

    int sameNumber1 = 0;
    int sameNumber2 = 0;

    switch (same)
    {
    case 6:
        return 1111 * a;
    case 3:
        for (int i = 0; i < 4; ++i)
        {
            if (sameCount[i] == 2)
                sameNumber1 = number[i];
            else if (sameCount[i] == 0)
                sameNumber2 = number[i];
        }
        return pow((10 * sameNumber1 + sameNumber2), 2);
    case 2:
    {
        for (int i = 0; i < 4; ++i)
        {
            if (sameNumber1 == 0 && sameCount[i] != 0)
                sameNumber1 = number[i];
            else if (sameNumber1 != 0 && number[i] != sameNumber1)
            {
                sameNumber2 = number[i];
                break;
            }
        }
        return (sameNumber1 + sameNumber2) * abs(sameNumber1 - sameNumber2);
    }
    case 1:
    {
        int score = 1;
        for (int i = 0; i < 4; ++i)
        {
            if (sameCount[i] == 0)
            {
                score*= number[i];
            }
        }
        return score;
    }
    default:
        int smallNum = 6;
        for (int a : number)
        {
            smallNum = a < smallNum ? a : smallNum;
        }
        return smallNum;
    }
}

int 주사위게임3(int a, int b, int c, int d) {
    int answer = GetScore(a,b,c,d);
    return answer;
}

string 글자이어붙여문자열만들기(string my_string, vector<int> index_list) {
    string answer = "";
    for (int index : index_list)
    {
        answer += my_string[index];
    }
    return answer;
}


int GetNumberSum(const string number)
{
    int sum = 0;
    for (char c : number)
    {
        sum += c - '0';
    }
    return sum;
}

int 구로나눈나머지(string number) {
    int answer = 0;
    int sum = GetNumberSum(number);
    
    return sum % 9;
}


vector<int> 배열만들기5(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;

    for (string str : intStrs)
    {
        int num = stoi(str.substr(s, l));
        if (k < num)
            answer.push_back(num);
    }

    return answer;
}

string 문자열여러번뒤집기(string my_string, vector<vector<int>> queries) {

    for (vector<int> querie : queries)
    {
        for (int i = 0; i < (querie[1] - querie[0])/2 + 1; ++i)
        {
            swap(my_string[querie[0] + i], my_string[querie[1] - i]);
        }
    }

    return my_string;
}

string 부분문자열이어붙여문자열만들기(vector<string> my_strings, vector<vector<int>> parts) {
    string answer = "";

    for (int i = 0; i < my_strings.size(); ++i)
    {
        answer += my_strings[i].substr(parts[i][0], parts[i][1] - parts[i][0] + 1);
    }
    return answer;
}

string 문자열뒤의n글자(string my_string, int n) {
    string str = my_string.substr(my_string.length() - n, n);
    return str;
}

vector<string> 접미사배열(string my_string) {
    vector<string> answer;
    vector<string> tmp;
    my_string.find('a');
    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (string::npos == my_string.find(c))
            continue;
        for (int i = my_string.size() - 1; i >= 0; --i)
        {
            if (c == my_string[i])
                tmp.push_back(my_string.substr(i, my_string.size() - i));
        }
        for (int i = 0; i < tmp.size() - 1; ++i)
        {
            for (int j = i + 1 ; j < tmp.size(); ++j)
            {
                if (tmp[i] > tmp[j])
                {
                    swap(tmp[i], tmp[j]);
                }
            }
        }
        for (string str : tmp)
        {
            answer.push_back(str);
        }
        tmp.clear();
    }

    return answer;
}

int 접미사인지확인하기(string my_string, string is_suffix) 
{
    if (is_suffix.size() > my_string.size())
        return 0;
    if (my_string.substr(my_string.size() - is_suffix.size(), is_suffix.size()) == is_suffix)
        return 1;
    else
        return 0;
}

string 문자열앞의n글자(string my_string, int n) 
{
    return my_string.substr(0, n);
}

int 접두사인지확인하기(string my_string, string is_prefix) {
    if (is_prefix.size() > my_string.size())
        return 0;
    if (my_string.substr(0, is_prefix.size()) == is_prefix)
        return 1;
    else
        return 0;
}

string 세로읽기(string my_string, int m, int c) {
    string answer = "";
    int index = 0;
    while (index < my_string.size())
    {
        answer += my_string[index + (c - 1)];
        index += m;
    }
    return answer;
}

string QrCode(int q, int r, string code) {
    string answer = "";

    for (int i = 0; i < code.size(); ++i)
    {
        if (i % q == r)
            answer += code[i];
    }
    return answer;
}

vector<int> 문자개수세기(string my_string) {
    vector<int> answer;
    answer.assign(52, 0);
    for (char c : my_string)
    {
        int index = 'a' <= c && c <= 'z' ? 26 + (c - 'a') : (c - 'A');
        ++answer[index];
    }
    return answer;
}

vector<int> 배열만들기1(int n, int k) {
    vector<int> answer;
    for (int i = k; i <= n; i += k)
    {
        answer.push_back(i);
    }
    return answer;
}


void SelectSort(vector<int>& indices)
{
    for (int i = 0; i < indices.size() - 1; ++i)
    {
        for (int j = i + 1; j < indices.size(); ++j)
        {
            if (indices[j] < indices[i])
                swap(indices[j], indices[i]);
        }
    }
}

string 글자지우기(string my_string, vector<int> indices) {
    string answer = "";
    SelectSort(indices);

    for (int i = 0,j = 0; i < my_string.size(); ++i)
    {
        if (i == indices[j])
        {
            ++j;
            continue;
        }
        answer += my_string[i];
    }
    return answer;
}

vector<int> 카운트다운(int start, int end) {
    vector<int> answer;
    for (int i = start; i >= end; --i)
        answer.push_back(i);
    return answer;
}

int 가까운1찾기(vector<int> arr, int idx) {
    for (int i = idx; i < arr.size(); ++i)
    {
        if (arr[i])
        {
            return i;
        }
    }
    return -1;
}

vector<int> 리스트자르기(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    switch (n)
    {
    case 1:
    {
        auto iter = num_list.begin();
        auto dest = iter + slicer[1];
        answer.insert(answer.end(), iter, ++dest);
        break;
    }
    case 2:
    {
        auto iter = num_list.begin() + slicer[0];
        answer.insert(answer.end(), iter, num_list.end());
        break;
    }
        
    case 3:
    {
        auto iter = num_list.begin() + slicer[0];
        auto dest = iter + slicer[1] - slicer[0];
        answer.insert(answer.end(),iter, ++dest);
        break;
    }
        
    case 4:
        for (int i = slicer[0]; i <= slicer[1]; i += slicer[2])
        {
            answer.push_back(num_list[i]);
        }
        break;
    }
    return answer;
}

vector<int> 배열만들기3(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    for (vector<int> interval : intervals)
    {
        for (int i = interval[0]; i <= interval[1]; ++i)
            answer.push_back(arr[i]);
    }
    return answer;
}

vector<int> 이의영역(vector<int> arr) {
    vector<int> answer;
    int start = -1;
    int end = -1;
    for (int i = 0, j = arr.size() - 1; i <= j;)
    {
        if (start == -1 && 2 == arr[i])
            start = i;
        if (end == -1 && 2 == arr[j])
            end = j;
        if (start != -1 && end != -1)
            break;
        if (start == -1)
            ++i;
        if(end == -1)
            --j;
    }
    
    if (start == -1 && end == -1)
        answer.push_back(-1);
    else if (start == end)
        answer.push_back(2);
    else
        answer.insert(answer.begin(), arr.begin() + start,arr.begin() + (end + 1));
    return answer;
}

vector<int> 배열조각하기 (vector<int> arr, vector<int> query) {
    vector<int> answer;
    for(int num = 0 ; num < query.size() ; ++num)
    {
        answer.clear();
        if (num % 2 == 0)
        {
            answer.insert(answer.begin(), arr.begin(), arr.begin() + query[num] + 1);
        }
        else
        {
            answer.insert(answer.begin(), arr.begin() + query[num], arr.begin() +arr.size());
        }
        arr = answer;
    }
    return answer;
}


vector<int> N번째원소부터(vector<int> num_list, int n) 
{
    vector<int> answer;
    answer.insert(answer.begin(), num_list.begin() + (n-1), num_list.end());
    return answer;
}

vector<string> 왼쪽오른쪽(vector<string> str_list) {
    vector<string> answer{};
    
    for (int i = 0 ; i < str_list.size() ; ++i)
    {
        if (str_list[i] == "l")
        {
            answer.insert(answer.begin(), str_list.begin(), str_list.begin() + i);
            return answer;
        }
        else if (str_list[i] == "r")
        {
            answer.insert(answer.begin(), str_list.begin() + i + 1, str_list.end());

            return answer;
        }
    }
    return answer;
}


vector<int> N번째원소까지 (vector<int> num_list, int n)
{
    return vector<int>{num_list.begin(), num_list.begin() + n};
}

vector<int> N개간격의원소들(vector<int> num_list, int n) {
    vector<int> answer;
    for (int i = 0; i < num_list.size(); i += n)
    {
        answer.push_back(num_list[i]);
    }
    return answer;
}

int 홀수VS짝수(vector<int> num_list) {
    int answer = 0;
    int oddSum = 0;
    int evenSum = 0;

    for (int i = 0; i < num_list.size(); ++i)
    {
        i % 2 == 0 ? evenSum += num_list[i] : oddSum += num_list[i];
    }
    return evenSum < oddSum ? oddSum : evenSum;
}

vector<string> Five명씩(vector<string> names) {
    vector<string> answer;
    for (int i = 0; i < names.size(); i += 5)
    {
        answer.push_back(names[i]);
    }
    return answer;
}


vector<string> 할일목록(vector<string> todo_list, vector<bool> finished) {
    vector<string> answer;
    for (int i = 0; i < finished.size(); ++i)
    {
        if (!finished[i])
            answer.push_back(todo_list[i]);
    }
    return answer;
}


int N보다커질때까지더하기(vector<int> numbers, int n) {
    int answer = 0;
    int index = 0;
    while (answer <= n)
    {
        answer += numbers[index++];
    }
    return answer;
}

vector<int> 수열과구간쿼리1(vector<int> arr, vector<vector<int>> queries) 
{
    for (int i = 0; i < queries.size(); ++i)
    {
        for (int j = 0; j < arr.size(); ++j)
        {
            if (queries[i][0] <= j && j <= queries[i][1])
            {
                ++arr[j];
            }
        }
    }
    return arr;
}

vector<int> 조건에맞게수열변환하기(vector<int> arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] >= 50 && arr[i] % 2 == 0)
        {
            arr[i] /= 2;
        }
        else if (arr[i] <= 50 && arr[i] % 2 != 0)
        {
            arr[i] *= 2;
        }
    }
    return arr;
}

vector<int> ChangeArr(vector<int> arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] >= 50 && arr[i] % 2 == 0)
        {
            arr[i] /= 2;
        }
        else if (arr[i] <= 50 && arr[i] % 2 != 0)
        {
            arr[i] *= 2;
            ++arr[i];
        }
    }
    return arr;
}

int 조건에맞게수열변환하기2(vector<int> arr)
{
    vector<int> prevArr = arr;
    vector<int> changedArr = ChangeArr(arr);
    int changedCount = 1;
    while (prevArr != changedArr)
    {
        ++changedCount;
        prevArr = changedArr;
        changedArr = ChangeArr(changedArr);
    }
    return changedCount - 1;
}

int One으로만들기(vector<int> num_list) {
    int answer = 0;
    for (int num : num_list)
    {
        while (num != 1)
        {
            num % 2 == 0 ? num /= 2 : num = (num - 1) / 2;
            ++answer;
        }
    }
    return answer;
}

int 길이에따른연산(vector<int> num_list)
{
    int answer = 0;
    if (num_list.size() >= 11)
    {
        for (int n : num_list)
        {
            answer += n;
        }
    }
    else
    {
        answer = 1;
        for (int n : num_list)
        {
            answer *= n;
        }
    }
    return answer;
}

int 원하는문자열찾기 (string myString, string pat)
{
    if (pat.size() > myString.size())
        return 0;
    int correctCount{ 0 };
    for (int i = 0; i < myString.size(); ++i)
    {
        if (pat[correctCount] == toupper(myString[i]) || pat[correctCount] == tolower(myString[i]))
            ++correctCount;
        else
            correctCount = 0;
        if (correctCount == pat.size())
            return 1;
    }
    return 0;
}


string ToUpper(const string& str)
{
    string tmp;
    for (char c : str)
    {
        tmp += toupper(c);
    }
    return tmp;
}

string ToLower(const string& str)
{
    string tmp;
    for (char c : str)
    {
        tmp += tolower(c);
    }
    return tmp;
}
vector<string> 배열에서문자열대소문자변환하기(vector<string> strArr) {
    vector<string> answer;
    for (string str : strArr)
    {
        answer.size() % 2 == 0 ? answer.push_back(ToLower(str)) : answer.push_back(ToUpper(str));
    }
    return answer;
}

string A강조하기(string myString) 
{
    string answer = "";
    for (char c : myString)
    {
        if (c == 'a')
            answer += 'A';
        else if (c != 'A' && ('A' <= c && c <= 'Z'))
            answer += tolower(c);
        else
            answer += c;
    }
    return answer;
}

string 특정한문자를대문자로바꾸기(string my_string, string alp) 
{
    string answer;

    for (char c : my_string)
    {
        answer += (c == alp[0] && islower(c)) ? toupper(c) : c;
    }
    return answer;
}

string 특정문자열로끝나는가장긴문자열찾기(string myString, string pat)
{
    string answer = "";
    for (int i = myString.size() - pat.size(); i >= 0; --i)
    {
        if (myString.substr(i, pat.size()) == pat)
        {
            return myString.substr(0, i + pat.size());
        }
    }
    return answer;
}


int 문자열이몇번등장하는지세기(string myString, string pat) {
    int answer = 0;
    for (int i = 0; i + pat.size() <= myString.size(); ++i)
    {
        if (myString.substr(i, pat.size()) == pat)
            ++answer;
    }
    return answer;
}

vector<string> AD제거하기(vector<string> strArr) {
    vector<string> answer;
    for (string str : strArr)
    {
        if(str.find("ad") == string::npos)
            answer.push_back(str);
    }
    return answer;
}

vector<string> 공백으로구분하기1(string my_string) 
{
    vector<string> answer;
    string str = "";
    for (int i = 0; i < my_string.size(); ++i)
    {
        if (my_string[i] == ' ')
        {
            answer.push_back(str);
            str = "";
        }
        else
            str += my_string[i];
    }
    if(str != "")
        answer.push_back(str);
    return answer;
}

vector<string> 공백으로구분하기2(string my_string)
{
    vector<string> answer;
    string str = "";
    for (int i = 0; i < my_string.size(); ++i)
    {
        if (my_string[i] == ' ' && str != "")
        {
            answer.push_back(str);
            str = "";
        }
        else if(my_string[i] != ' ')
            str += my_string[i];
    }
    if (str != "")
        answer.push_back(str);
    return answer;
}

vector<int> X사이의개수(string myString) {
    vector<int> answer;
    int count = 0;
    for (char c : myString)
    {
        if (c == 'x')
        {
            answer.push_back(count);
            count = 0;
        }
        else
            ++count;
    }
    answer.push_back(count);

    return answer;
}

vector<string> 문자열잘라서정렬하기(string myString)
{
    vector<string> answer;
    string str = "";
    for (char c : myString)
    {
        if (c == 'x' && str != "")
        {
            answer.push_back(str);
            str = "";
        }
        else if (c != 'x')
            str += c;
    }
    if(str != "")
        answer.push_back(str);
    for(int i = 0 ; i < answer.size() - 1 ; ++i)
    {
        for (int j = i + 1; j < answer.size(); ++j)
        {
            if (answer[i] >= answer[j])
                swap(answer[i], answer[j]);
        }
    }

    return answer;
}


int 간단한식계산하기(string binomial) {
    int answer = 0;
    for (int i = 0; i < binomial.size(); ++i)
    {
        if (binomial[i] == '+' || binomial[i] == '-' || binomial[i] == '*')
        {
            int a = stoi(binomial.substr(0, i - 1));
            int b = stoi(binomial.substr(i + 2, binomial.size() - (i+2)));
            switch (binomial[i])
            {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            }
        }
    }

    return answer;
}


int 문자열바꿔서찾기 (string myString, string pat) {
    int answer = 0;
    for (int i = 0; i < myString.size(); ++i)
    {
        if (myString[i] == 'A')
            myString[i] = 'B';
        else if (myString[i] == 'B')
            myString[i] = 'A';
    }

    return myString.find(pat) == string::npos ? 0 : 1;
}

string rny_string(string rny_string)
{
    string answer = "";
    for (char c : rny_string)
    {
        if (c == 'm')
            answer += "rn";
        else
            answer += c;
    }
    return answer;
}


void AddNumberMultiple(vector<int>& arr, const int num)
{
    for (int i = 0; i < num * 2; ++i)
        arr.push_back(num);
}

void RemoveNumber(vector<int>& arr,const int num)
{
    for (int i = 0; i < num; ++i)
        arr.pop_back();
}

vector<int> 빈배열에추가삭제하기(vector<int> arr, vector<bool> flag) 
{
    vector<int> answer;

    for (int i = 0 ; i < flag.size() ; ++i)
    {
        flag[i] ? AddNumberMultiple(answer, arr[i]) : RemoveNumber(answer,arr[i]);
    }

    return answer;
}

vector<int> 배열만들기6(vector<int> arr) 
{
    vector<int> answer;
    for (int i = 0; i < arr.size();)
    {
        if (answer.empty())
        {
            answer.push_back(arr[i]);
            ++i;
        }
        else if (!answer.empty() && answer.back() == arr[i])
        {
            answer.pop_back();
            ++i;
        }
        else if (!answer.empty() && answer.back() != arr[i])
        {
            answer.push_back(arr[i]);
            ++i;
        }
    }
    if (answer.empty())
        answer.push_back(-1);
    return answer;
}

#include <map>
vector<int> 무작위로K개의수뽑기(vector<int> arr, int k) 
{
    vector<int> answer;
    map<int, bool> prevAppeared;
    for (int num : arr)
    {
        if (prevAppeared.find(num) == prevAppeared.end())
        {
            prevAppeared.insert({ num,true });
            answer.push_back(num);
            if (answer.size() == k)
                break;
        }
    }
    
    if (answer.size() < k)
    {
        answer.insert(answer.end(),size_t(k - answer.size()),-1);
    }

    return answer;
}


vector<int> 배열의길이를2의거듭제곱의로만들기(vector<int> arr) 
{
    vector<int> answer = arr;
    int num = 2;
    if (answer.size() == 1)
        return arr;
    while (num < answer.size())
    {
        num *= 2;
    }
    if (num != answer.size())
    {
        answer.insert(answer.end(), size_t(num - answer.size()),0);
    }
    return answer;
}

int 배열비교하기(vector<int> arr1, vector<int> arr2) 
{
    int answer = 0;
    if (arr1.size() != arr2.size())
    {
        answer = arr1.size() < arr2.size() ? -1 : 1;
    }
    else
    {
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < arr1.size(); ++i)
        {
            sum1 += arr1[i];
            sum2 += arr2[i];
        }
        if (sum1 == sum2)
            answer = 0;
        else
            answer = sum1 < sum2 ? -1 : 1;
    }
    return answer;
}

int 문자열묶기(vector<string> strArr)
{
    map<int, int> prevAppeared;
    int bigNum = 0;
    for (string str : strArr)
    {
        if (prevAppeared.find(str.size()) == prevAppeared.end())
            prevAppeared.insert({ str.size(), 1 });
        else
        {
            ++prevAppeared[str.size()];
        }
        if (bigNum < prevAppeared[str.size()])
            bigNum = prevAppeared[str.size()];
    }

    return bigNum;
}

void PlusOddEven(vector<int>& arr, bool isOdd,const int n)
{
    int startIndex = isOdd ? 0 : 1;
    int sum;
    for (int i = startIndex ; i < arr.size(); i += 2)
    {
        arr[i] += n;
    }
}
vector<int> 배열의길이에따라다른연산하기 (vector<int> arr, int n)
{
    if (arr.size() % 2 == 0)
    {
        PlusOddEven(arr, false,n);
    }
    else
    {
        PlusOddEven(arr, true,n);
    }
    return arr;
}

vector<int> 뒤에서5등까지(vector<int> num_list) 
{
    vector<int> answer;
    for (int i = num_list.size() - 1 ; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (num_list[j] > num_list[j + 1])
                swap(num_list[j], num_list[j + 1]);
        }
    }
    answer.insert(answer.end(), num_list.begin(), num_list.begin() + 5);
    return answer;
}

vector<int> 뒤에서5등위로(vector<int> num_list) 
{
    vector<int> answer;
    for (int i = num_list.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (num_list[j] > num_list[j + 1])
                swap(num_list[j], num_list[j + 1]);
        }
    }
    answer.insert(answer.end(), num_list.begin() + 5, num_list.end());

    return answer;
}

int 전국대회선발고사(vector<int> rank, vector<bool> attendance) 
{
    int answer = 0;
    map<int, int> mapRandIndex;
    vector<int> waitingList;
    for (int i = 0; i < attendance.size(); ++i)
    {
        if (attendance[i])
        {
            waitingList.push_back(rank[i]);
            mapRandIndex.insert({ rank[i],i });
        }
    }
    for (int i = 0; i < waitingList.size() - 1; ++i)
    {
        for (int j = i + 1; j < waitingList.size(); ++j)
        {
            if (waitingList[i] > waitingList[j])
            {
                swap(waitingList[i], waitingList[j]);
            }
        }
    }
    answer = 10000 * mapRandIndex[waitingList[0]] + 100 * mapRandIndex[waitingList[1]]
        + mapRandIndex[waitingList[2]];
    return answer;
}

int 문자열정수의합(string num_str) 
{
    int answer = 0;
    for (char c : num_str)
    {
        answer += c - '0';
    }
    return answer;
}

string Zero떼기(string n_str) 
{
    string answer = "";
    bool searchZero = true;
    for (char c : n_str)
    {
        if (searchZero && c == '0')
        {
            continue;
        }
        else
        {
            if (searchZero)
                searchZero = false;
            answer += c;
        }
    }
    return answer;
}

string solution(string a, string b) 
{
    string answer = "";
    string pivotString;
    string addString;
    if (a.size() < b.size())
    {
        pivotString = b;
        addString = a;
    }
    else
    {
        pivotString = a;
        addString = b;
    }
    for (int i = 0; i < addString.size(); ++i)
    {
        
    }
    return answer;
}

string 문자열로변환(int n) 
{

    return to_string(n);
}