// https://www.acmicpc.net/problem/10157

#include <stdio.h>

using namespace std;

class Seat {
public:
	int r, c, val;
	Seat(int _r, int _c, int _val) {
		r = _r;
		c = _c;
		val = _val;
	}
};

int main() {
	int C, R, K;
	int dir = 1;
	Seat comp(0,1,0);

	scanf("%d %d %d", &C, &R, &K);

	if (K > R*(C--))	return !printf("0");

	while (true) {
		// horizontal
		if (K <= comp.val + R) {
			comp.r += dir * (K - comp.val);
			break;
		}
		comp.val += R;
		comp.r += dir * (R--);

		// vertical
		if (K <= comp.val + C) {
			comp.c += dir * (K - comp.val);
			break;
		}
		comp.val += C;
		comp.c += dir * (C--);

		dir *= -1;
	}
	printf("%d %d", comp.c, comp.r);

	return 0;
}