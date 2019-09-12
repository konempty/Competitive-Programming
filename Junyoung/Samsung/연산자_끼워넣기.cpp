// https://www.acmicpc.net/problem/14888

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;

const int MAXN = 11+2;

int N;
int A[MAXN];
int optr[MAXN];
int op_cnt[4];
int mx = -1e9-2, mn = 1e9+2;

void dfs(int idx){
	if(idx == N-1){
		int sum = A[0];
		FOR(i, 0, N-1){
			switch(optr[i]){
				case 0:
					sum += A[i+1];	break;
				case 1:
					sum -= A[i+1];	break;
				case 2:
					sum *= A[i+1];	break;
				case 3:
					sum /= A[i+1];	break;
			}
		}
		mx = max(mx, sum);	mn = min(mn, sum);
		return;
	}
	FOR(i, 0, 4){
		if(!op_cnt[i])	continue;
		op_cnt[i]--;
		optr[idx] = i;
		dfs(idx+1);
		op_cnt[i]++;
	}
}

int main(){
	scanf("%d", &N);
	FOR(i, 0, N)	scanf("%d", &A[i]);
	FOR(i, 0, 4)	scanf("%d", &op_cnt[i]);
	dfs(0);
	printf("%d\n%d\n", mx, mn);
	
	return 0;
}