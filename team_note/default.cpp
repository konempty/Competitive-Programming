#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

#define FOR(i,n) for(int i = 0; i < n; i++)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair <int, int> pii;
typedef struct NODE{
	int data;
	NODE* link;
}node;

const int MAXN = 10000+2;
// 동 서 남 북
const int dr[] = {0,0,-1,1};
const int dc[] = {1,-1,0,0};
// 북남, 남북, 동서, 서동
const int TURN[4][2] = {{3,2},{2,3},{0,1},{1,0}};

pii operator + (const pii &a, const pii &b){	
	return pii(a.first+b.first, a.second+b.second)
}