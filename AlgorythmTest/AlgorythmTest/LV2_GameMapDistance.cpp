#include<vector>
#include <queue>
using namespace std;
struct Node
{
    int x;
    int y;
    int coast;
};
int solution(vector<vector<int> > maps)
{
    int answer{ 0 };
    queue<Node> nodes;
    nodes.push({ Node{0,0,1} });
    vector<vector<bool>> isPassed;
    isPassed.resize(maps.size());
    for (size_t i{ 0 }; i < maps.size(); ++i)
        isPassed[i].resize(maps[0].size());

    while (!nodes.empty())
    {
        Node nowNode;
        nowNode.x = nodes.front().x;
        nowNode.y = nodes.front().y;
        nowNode.coast = nodes.front().coast;
        nodes.pop();
        // µµÂø
        if (nowNode.x == maps[0].size() - 1 && nowNode.y == maps.size() - 1)
        {
            if (0 == answer)
                answer = nowNode.coast;
            else
                answer = answer < nowNode.coast ? answer : nowNode.coast;
            continue;
        }
        if (nowNode.y < maps.size() - 1)
        {
            if(!isPassed[nowNode.y + 1][nowNode.x] && maps[nowNode.y + 1][nowNode.x] == 1)
                nodes.push(Node{ nowNode.x ,nowNode.y + 1,nowNode.coast + 1 });
        }
        if (nowNode.y > 0)
        {
            if (!isPassed[nowNode.y - 1][nowNode.x] && maps[nowNode.y - 1][nowNode.x] == 1)
                nodes.push(Node{ nowNode.x, nowNode.y - 1 ,nowNode.coast + 1 });
        }
        if (nowNode.x < maps[0].size() - 1)
        {
            if (!isPassed[nowNode.y][nowNode.x + 1] && maps[nowNode.y][nowNode.x + 1] == 1)
                nodes.push(Node{ nowNode.x + 1 , nowNode.y,nowNode.coast + 1 });
        }
        if (nowNode.x > 0)
        {
            if (!isPassed[nowNode.y][nowNode.x - 1] && maps[nowNode.y][nowNode.x - 1] == 1)
                nodes.push(Node{ nowNode.x - 1 , nowNode.y ,nowNode.coast + 1 });
        }
        isPassed[nowNode.y][nowNode.x] = true;
    }
    return answer == 0 ? -1 : answer;
}