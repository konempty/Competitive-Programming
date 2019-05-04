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

const ll MOD = 1e9 + 7;
const int MAXN = 10000+2;
// 동 서 남 북
const int dr[] = {0,0,-1,1};
const int dc[] = {1,-1,0,0};

// 8방면
const int dr2[] = {-1,-1,-1,0,1,1,1,0};
const int dc2[] = {-1,0,1,1,1,0,-1,-1};

// 북남, 남북, 동서, 서동
const int TURN[4][2] = {{3,2},{2,3},{0,1},{1,0}};

pii operator + (const pii &a, const pii &b){	
	return pii(a.first+b.first, a.second+b.second);
}