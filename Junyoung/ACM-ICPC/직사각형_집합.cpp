// https://www.acmicpc.net/problem/9464

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXL = 1000000/2;
vector <int> PT;

void init_PT(){
	int L = MAXL;
	for(int x = 2; x < 75; x++){
		for(int y = 1; y < x; y++){
			int a = 2*x*y;
			int b = x*x-y*y;
			if (a+b > MAXL)	break;
			// 같은 길이에서 2개 이상의 피타고리안 트리플이 나올 수 없음
			if (__gcd(a,b) == 1)	PT.push_back(a+b);
		}
	}
	sort(PT.begin(), PT.end());
	
	int len = PT.size();
	for(int i = 1; i < len; i++) {
		PT[i] += PT[i-1];
	}
}

int main() {
	init_PT();
	
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		int L;
		scanf("%d", &L); L /= 2;
		// 이진탐색 (upper)
		printf("%d\n", (int)(upper_bound(PT.begin(), PT.end(), L)-PT.begin()));
	}
}
