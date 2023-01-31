#include <string>
#include <vector>

using namespace std;


void bubbleSort(vector<int>& _array)
{
    for (int i = 0; i < _array.size() -1 ; ++i)
    {
        for (int j = 0; j < _array.size() - (i + 1); ++j)
        {
            if (_array[j] > _array[j + 1])
            {
                int tmp = _array[j];
                _array[j] = _array[j + 1];
                _array[j + 1] = tmp;
            }
        }
    }
}

int solution(vector<int> array) {
    bubbleSort(array);

    return array[array.size() / 2];
}

void main()
{
    solution({ 9,-1,0 });
}