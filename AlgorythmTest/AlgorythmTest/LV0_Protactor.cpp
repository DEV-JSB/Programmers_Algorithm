#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
	if (0 < angle && angle < 90)
		return 1;
	else if (90 < angle && angle < 180)
		return 3;
	
	return angle == 90 ? 2 : 4;
}