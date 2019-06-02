// https://www.acmicpc.net/problem/14499

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

const int MAXN = 20 + 2;
// 동 서 북 남
const int dr[] = {0, 0, 0, -1, 1};
const int dc[] = {0, 1, -1, 0, 0};
const int convert[5][7] = {
	{0,1,2,3,4,5,6},
	{0,4,2,1,6,5,3},	// 동
	{0,3,2,6,1,5,4},	// 서
	{0,5,1,3,4,6,2},	// 북
	{0,2,6,3,4,1,5}		// 남
};

int N, M, x, y, K;
int dice[7];
int map[MAXN][MAXN];

void dice_turn(int dir){
	int nx = x + dr[dir];
	int ny = y + dc[dir];
	if(nx < 0 || nx >= N || ny < 0 || ny >= M)	return;
	x = nx;	y = ny;
	
	int temp[7];
	FOR(i, 1, 7){
		int idx = convert[dir][i];
		temp[i] = dice[idx];
	}
	FOR(i, 1, 7)	dice[i] = temp[i];
	
	if(!map[x][y]){
		map[x][y] = dice[6];
	} else {
		dice[6] = map[x][y];
		map[x][y] = 0;
	}
	printf("%d\n", dice[1]);
}

int main(){
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	FOR(n, 0, N)	FOR(m, 0, M)	scanf("%d", &map[n][m]);
	FOR(k, 0, K){
		int order;
		scanf("%d", &order);
		dice_turn(order);
	}
	return 0;
}