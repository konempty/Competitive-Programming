// https://www.acmicpc.net/problem/10453

#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;

const int MAXN = 100000+2;

int main(){
	int T;
	
	scanf("%d", &T);
	FOR(t, 0, T){
		char A[MAXN], B[MAXN];
		scanf("%s %s", A, B);
		
		// 항상 좋은 문자열임이 보장됨!
		vector<int> Aa, Ba;
		for(int i =0; A[i]; i++)	if(A[i] == 'a')	Aa.push_back(i);
		for(int i =0; B[i]; i++)	if(B[i] == 'a')	Ba.push_back(i);
		
		int cnt = 0;
		int len = Aa.size();
		FOR(i, 0, len)	cnt += abs(Aa[i]-Ba[i]);
		printf("%d\n", cnt);
	}
	
	return 0;
}