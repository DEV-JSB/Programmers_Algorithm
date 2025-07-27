#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void RecordPassedWay(map<pair<int, int>, vector<pair<int, int>>>& map, const pair<int, int> startPos, const pair<int, int> endPos)
{
	map[startPos].push_back(endPos);
	map[endPos].push_back(startPos);
}

bool IsPassedWay(map<pair<int, int>, vector<pair<int, int>>>& map, const pair<int, int> startPos, const pair<int, int> endPos)
{
	auto startPassedWay = map.find(startPos);
	auto endPassedWay = map.find(endPos);

	if (startPassedWay == map.end() || endPassedWay == map.end())
	{
		return false;
	}
	
	vector<pair<int, int>>& startPassedWayVec = startPassedWay->second;
	vector<pair<int, int>>& endPassedWayVec = endPassedWay->second;

	return find(startPassedWayVec.begin(), startPassedWayVec.end(), endPos) != startPassedWayVec.end()
		|| find(endPassedWayVec.begin(), endPassedWayVec.end(), startPos) != endPassedWayVec.end();

}

int solution(string dirs)
{
	int answer = 0;

	map<pair<int, int>, vector<pair<int,int>>> passedWay;
	pair<int, int> nowPos{ 0,0 };
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

		if (!IsPassedWay(passedWay, nowPos, willMovePos))
		{
			++answer;
		}
		RecordPassedWay(passedWay, nowPos, willMovePos);
		nowPos = willMovePos;
	}

	return answer;
}
