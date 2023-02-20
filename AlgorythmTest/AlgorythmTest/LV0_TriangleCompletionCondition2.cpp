#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    // ���⼭ �߰��� sides �� �� �� ���� ��쿡�� �ٸ��� ���ؾ� �Ѵ�.
    //if (sides[0] == sides[1])
    //{
    //    // �� �� ���� ��쿡�� �׳� sides[1] �� ���� ��ȯ�ص� �ȴ�.
    //    // �̵ ~ �� �ﰢ�������� ���̴ϱ�
    //    return sides[0];
    //}
    int answer = 0;
    // ���� �� ���� ���̴� �ٸ� �� ���� ������ �պ��� �۾ƾ� �Ѵ�.
    // sides���� �� ���� ���� ��ų� , ����Ǽ��� ���ϴ� ���� ���� ��ų�.
    // �� �� �ϳ��ΰ�?? ����

    // �켱 sides �� ���� ���� ���� �� ��쿡�� 
    // sides[0] + sides[1] ���� �۾ƾ� �ϰ� , �� �ε��� �� ū �� ���� ũ�ų� ���ƾ��Ѵ�.

    // sides �� �ִ� ���� �� �ϳ��� ���� ū�Ŷ�� ġ��
    // ����� ���� sides[������] + ? < sides[ū��] �̾�� �Ѵ�.
    // ũ�ų� ���Ƶ� ������ �װ� ���� ���̽����� ũ�ų� ���Ÿ� ���������Ƿ� 
    // �̵ �ﰢ���� �� ���� ������ �̹� ����� ��

    // �켱 �� �� ũ�� ���� �ε����� ���Ѵ�
    int bigIndex{ sides[0] < sides[1] ? 1 : 0 };
    int minIndex{ bigIndex == 1 ? 0 : 1 };

    for (int i = 1; i <= sides[bigIndex]; ++i)
    {
        if (i + sides[minIndex] > sides[bigIndex])
            ++answer;
    }
    for (int i = sides[bigIndex] + 1 ; sides[minIndex] + sides[bigIndex] > i; ++i)
    {
        ++answer;
    }
    return answer;
}