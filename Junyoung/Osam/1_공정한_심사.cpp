#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)

const int MAXV = 1000;
const int MAXN = 12;
int minv = MAXV, maxv = -MAXV;
double sum = 0;

int main(){
	FOR(i, 0, MAXN){
		int N;	scanf("%d", &N);
		sum += N;
		minv = min(minv, N);
		maxv = max(maxv, N);
	}
	printf("%0.1lf\n", (sum-minv-maxv)/(MAXN-2));
	return 0;
}