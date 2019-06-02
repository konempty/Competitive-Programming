// https://www.acmicpc.net/problem/17144

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
typedef pair<int,int> pii;

// 북 동 남 서
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
const int MAXR = 50 + 2;

int R, C;
int s1 = -1, s2 = -1;
int A[MAXR][MAXR];

int execute(){
	int rem = 0;
	int B[MAXR][MAXR];
	
	memcpy(B, A, sizeof(A));
	FOR(r, 0, R)	FOR(c, 0, C){
		if(B[r][c] <= 0)	continue;
		int amt = B[r][c]/5;
		
		FOR(i, 0, 4){
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C)	continue;
			if(B[nr][nc] == -1)	continue;
			A[nr][nc] += amt;
			A[r][c] -= amt;
		}
	}
	FORr(r, s1-2, 0)	A[r+1][0] = A[r][0];
	FOR(r, s2+2, R-1)	A[r-1][0] = A[r][0];
	FOR(c, 1, C-1)		A[0][c-1] = A[0][c];
	FOR(c, 1, C-1)		A[R-1][c-1] = A[R-1][c];
	FOR(r, 1, s1+1)		A[r][C-1] = A[r-1][C-1];
	FORr(r, R-2, s2)	A[r+1][C-1] = A[r][C-1];
	FORr(c, C-2, 1)		A[s1][c+1] = A[s1][c];
	// FORr(c, C-2, 1)		A[s2][c+1] = A[s2][c];
	
	FOR(r, 0, R) FOR(c, 0, C)	rem += (A[r][c] > 0);
	return rem;
}

int main(){
	int T;
	scanf("%d %d %d", &R, &C, &T);
	FOR(r, 0, R)	FOR(c, 0, C) {
		scanf("%d", &A[r][c]);
		if(!A[r][c])	continue;
		if(A[r][c] == -1){
			s1 = (s1 >= 0) ? s1 : -1;
			s2 = (s1 >= 0) ? s1+1 : -1;
			continue;
		}
	}
	int rem = 0;
	FOR(t, 0, T)	rem = execute();
	printf("%d\n", rem);
	
	return 0;
}