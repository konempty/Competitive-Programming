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
typedef pair <int, int> pii;
typedef struct NODE{
	int data;
	NODE* link;
}node;

class pot {
public:
	int r, c;
	pot(int _r, int _c) {
		r = _r, c = _c;
	}
};

const ll MOD = 1e9 + 7;
const int MAXN = 10000+2;
// 북 동 남 서
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

// 8방면
const int dr2[] = {-1,-1,-1,0,1,1,1,0};
const int dc2[] = {-1,0,1,1,1,0,-1,-1};

// 북서 동북 남동 서남 
const int l_turn[] = {3,0,1,2};
// 북동 동남 남서 서북
const int r_turn[] = {1,2,3,0};

pii operator + (const pii &a, const pii &b){	
	return pii(a.first+b.first, a.second+b.second);
}

void direction_check(int r, int c){
	FOR(i, 0, 4){
		int nr = r + dr[i];
		int nc = c + dc[i];
		if(nr < 0 || nr >= 10 || nc < 0 || nc >= 8)	continue;
		// if(visited[nr][nc])	continue;
	}
}