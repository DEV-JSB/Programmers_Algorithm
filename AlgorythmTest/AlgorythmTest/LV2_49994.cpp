#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int GetDirectionIndex(char c)
{
	switch (c)
	{
	case 'U':
		return 0;
	case 'D':
		return 1;
	case 'L':
		return 2;
	case 'R':
		return 3;
	}
}
int GetOppositeDirectionIndex(char c)
{
	switch (c)
	{
	case 'U':
		return 1;
	case 'D':
		return 0;
	case 'L':
		return 3;
	case 'R':
		return 2;
	}
}

void RecordPassedWay(int record[][11][4], const pair<int,int> startPos , const pair<int, int> endPos, char dir)
{
	record[startPos.first + 5][startPos.second + 5][GetDirectionIndex(dir)] = 1;
	record[endPos.first + 5][endPos.second + 5][GetOppositeDirectionIndex(dir)] = 1;
}

bool IsPassedWay(const int record[][11][4], const pair<int, int> startPos, const pair<int, int> endPos, char dir)
{
	return record[startPos.first + 5][startPos.second + 5][GetDirectionIndex(dir)]
		|| record[endPos.first + 5][endPos.second + 5][GetOppositeDirectionIndex(dir)];
}

int solution(string dirs)
{
	int answer = 0;

	pair<int, int> nowPos{ 0,0 };
	int record[11][11][4]{ 0 };

	map<char, pair<int, int>> dir{ {'U',{make_pair(0,1)}}
	,{'D',{make_pair(0,-1)}}
	,{'R',{make_pair(1,0)}}
	,{'L',{make_pair(-1,0)}} };

	for (int i = 0; dirs[i] != '\0'; ++i)
	{
		int x = nowPos.first;
		int y = nowPos.second;
		pair<int, int> willMovePos;
		
		willMovePos.first = nowPos.first + dir[dirs[i]].first;
		willMovePos.second = nowPos.second + dir[dirs[i]].second;

		if (willMovePos.first < -5 || willMovePos.first > 5
			|| willMovePos.second < -5 || willMovePos.second > 5)
		{
			continue;
		}
		
		if (!IsPassedWay(record, nowPos, willMovePos , dirs[i]))
		{
			++answer;
		}
		RecordPassedWay(record, nowPos, willMovePos, dirs[i]);
		nowPos = willMovePos;
	}

	return answer;
}

void main()
{
	solution("ULURRDLLU");
}
