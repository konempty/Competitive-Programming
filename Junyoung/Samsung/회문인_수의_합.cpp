#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;

int len = 0;
vector <int> palind;

void set_palind(){
	FOR(a, 1, 10000+1){
		string num = to_string(a);
		
		bool flag = true;
		int len = num.size();
		FOR(i, 0, len/2){
			if(num[i] != num[len-1-i]){
				flag = false;	break;
			}
		}
		if(flag)	palind.push_back(a);
	}
	len = palind.size();
}

bool one(int N){
	int idx = lower_bound(ALL(palind), N) - palind.begin();
	if(palind[idx] == N){
		printf("1 %d\n", N);
		return true;
	}
	return false;
}
bool two(int N){
	int sum = 0;
	FOR(a, 0, len)	FOR(b, a, len){
		sum = palind[a]+palind[b];
		if(sum == N){
			printf("2 %d %d\n", palind[b], palind[a]);
			return true;
		}
	}
	return false;
}
bool three(int N){
	int sum = 0;
	FOR(a, 0, len)	FOR(b, a, len)	FOR(c, b, len){
		sum = palind[a]+palind[b]+palind[c];
		if(sum == N){
			printf("3 %d %d %d\n", palind[c], palind[b], palind[a]);
			return true;
		}
	}
	return false;
}

int main(){
	set_palind();
	
	int T;
	scanf("%d", &T);
	FOR(t, 1, T+1){
		int N;
		vector<int> ans;
		
		scanf("%d", &N);
		printf("Case #%d\n", t);
		if(one(N))		continue;
		if(two(N))		continue;
		if(three(N))	continue;
		printf("0\n");
	}
	return 0;
}