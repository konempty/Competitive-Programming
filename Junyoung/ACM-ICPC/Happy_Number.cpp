// https://www.acmicpc.net/problem/14954

#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef long long ll;
const int square[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
const int MAXN = 10+2;

ll convert(ll N){
	ll ret = 0;
	char num[MAXN];
	
	sprintf(num, "%lld", N);	// int to char *
	int len = strlen(num);
	for(int i =0; i < len; i++){
		ret += square[num[i]-'0'];
	}
	return ret;
}

int main() {
	ll N;
	set<ll> is_in;
	
	scanf("%lld", &N);
	while(!is_in.count(N) && N != 1){
		is_in.insert(N);
		N = convert(N);
	}
	printf("%s\n", (N==1) ? "HAPPY" : "UNHAPPY");
	
    return 0;
}
