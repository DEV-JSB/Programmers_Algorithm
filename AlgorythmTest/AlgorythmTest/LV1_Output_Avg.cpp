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

// ���� ®�� C �ڵ�


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len�� �迭 arr�� �����Դϴ�.
double solution(int arr[], size_t arr_len) {
	double answer = 0;
	for (int i = 0; i < arr_len; ++i)
	{
		answer += arr[i];
	}
	return answer / arr_len;
}