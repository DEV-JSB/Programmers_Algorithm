#include<vector>
#include <queue>
#include <utility>
using namespace std;

int moveY[4] = { 1,0,-1,0 };
int moveX[4] = { 0,1,0,-1 };

int solution(vector<vector<int> > maps)
{
    int answer{ -1 };
    int YSize{ (int)maps.size() };
    int XSize{ (int)maps[0].size() };
    queue<pair<int, int>> nodes;
    nodes.push({ 0,0 });
    // �̰� �ϳ� ���
    vector<vector<int>> isPassed(YSize, vector<int>(XSize, -1));
    while (!nodes.empty())
    {
        pair<int, int> nowNode;
        nowNode = nodes.front();
        nodes.pop();
        // ����
        if (nowNode.first == maps[0].size() - 1 && nowNode.second == maps.size() - 1)
            return isPassed[nowNode.second][nowNode.first] + 2;
        // 0 �Ʒ� 1 �� 2 ���� 3 ������
        for (int i{ 0 }; i < 4; ++i)
        {
            int nextX = nowNode.first + moveX[i];
            int nextY = nowNode.second + moveY[i];
            if (0 > nextY
                || maps.size() <= nextY
                || 0 > nextX
                || maps[0].size() <= nextX
                || 0 == maps[nextY][nextX]
                || -1 != isPassed[nextY][nextX])
                continue;
            nodes.push({ nextX,nextY });
            isPassed[nextY][nextX] = isPassed[nowNode.second][nowNode.first] + 1;
        }
    }
    return -1;
}