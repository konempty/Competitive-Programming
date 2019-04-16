#include <stdio.h>
#include <vector>

using namespace std;

vector <int> h;

int main() {
	while (true) {
		int N;

		scanf("%d", &N);
		if (N < 0)	break;

		h.clear();
		for (int i = 0, in; i < N; i++) {
			scanf("%d", &in);
			h.push_back(in);
		}
	}
	return 0;
}