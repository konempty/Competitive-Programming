// https://www.acmicpc.net/problem/8901
// Brute-Force & Greedy

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int T;
	
	scanf("%d", &T);
	for(int t= 0; t < T; t++){
		int A, B, C, AB, BC, CA;
		scanf("%d %d %d", &A, &B, &C);
		scanf("%d %d %d", &AB, &BC, &CA);
		
		int res = 0;
		for(int i =0; i <= min(A,B); i++){
			int BC_n, CA_n;
			if(BC > CA){
				BC_n = min(B-i, C);
				CA_n = min(A-i, C-BC_n);
			} else {
				CA_n = min(A-i, C);
				BC_n = min(B-i, C-CA_n);
			}
			res = max(res, AB*i + BC*BC_n + CA*CA_n);
		}
		printf("%d\n", res);
	}
	return 0;
}