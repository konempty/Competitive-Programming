// https://www.acmicpc.net/problem/5014

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;

const int MAXF = 1e6;
vector <int> move_cnt(MAXF+2, -1);
queue<int> q;

int main(){
	int F, S, G, U, D;
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	
	move_cnt[S] = 0;
	q.push(S);
	while(!q.empty()){
		int S = q.front();
		q.pop();
		
		if(S+U >= 1 && S+U <= MAXF && move_cnt[S+U] < 0){
			move_cnt[S+U] = move_cnt[S] + 1;
			q.push(S+U);
		}
		if(S-D >= 1 && S-D <= MAXF && move_cnt[S-D] < 0){
			move_cnt[S-D] = move_cnt[S] + 1;
			q.push(S-D);
		}
		if(move_cnt[G] >= 0)	return !printf("%d\n", move_cnt[G]);
	}
	printf("use the stairs\n");
	
	return 0;
}