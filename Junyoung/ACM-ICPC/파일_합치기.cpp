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
 
int main() {
	int N;
	
	scanf("%d", &N);
	
	int cnt = -1;
	if(N%2 && N%5){
		cnt = 1;
		int one = 1;
		
		while(one %N){
			one %= N;
			one = one*10 +1;
			cnt++;
		}
	}
	printf("%d\n", cnt);
	
    return 0;
}