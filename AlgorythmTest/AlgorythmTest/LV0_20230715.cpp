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
