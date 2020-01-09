#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define FORo(i,e,o) for(int i = 0, e = o.size(); i < e; i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair <int, int> pii;
typedef priority_queue<int> pqi;

const int dr[] = { 0, 0, 1, 1 };
const int dc[] = { 0, 1, 0, 1 };
const int MAXN = 64+4;

int N;
int mtx[MAXN][MAXN];

int pmax(int R, int C, int sz) {
   int mx = -1;
   FOR(r, R, R+sz)   FOR(c, C, C+sz) {
      mx = max(mx, mtx[r][c]);
   }
   return mx;
}

string solve(int r, int c, int sz) {
   if (sz == 2) {
      return "";
   }

   int half = sz / 2;
   int mx = -1, mn = 102;
   FOR(i, 0, 4) {
      int nr = r + (dr[i] * half), nc = c + (dc[i] * half);
      int pmx = pmax(nr, nc, half);
      mx = max(mx, pmx);
      mn = min(mn, pmx);
   }
   
   if (mx > 1.2 * mn) {
      return "0";
   }

   string ret = "1";
   FOR(i, 0, 4) {
	   int nr = r + (dr[i] * half), nc = c + (dc[i] * half);
	   ret += solve(nr, nc, half);
   }
   return ret;
}

int main() {
   freopen("input.txt", "r", stdin);
   int T;
   scanf("%d", &T);
   FOR(t, 1, T+1) {
      scanf("%d", &N);
      FOR(r, 0, N) FOR(c, 0, N)   scanf("%d", &mtx[r][c]);
      printf("#%d %s\n", t, solve(0,0,N).c_str());
   }

   return 0;
}