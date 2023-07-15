#include <string>
#include <vector>
#include <set>
#include <math.h>
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
