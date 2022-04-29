#include <string>
#include <vector>
#include<iostream>
using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        answer += (double)arr[i];
    }
    return answer/(double)arr.size();
}

// 내가 짰던 C 코드


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
double solution(int arr[], size_t arr_len) {
	double answer = 0;
	for (int i = 0; i < arr_len; ++i)
	{
		answer += arr[i];
	}
	return answer / arr_len;
}