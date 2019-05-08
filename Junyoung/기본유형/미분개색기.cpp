// https://www.acmicpc.net/problem/14731

#include <cstdio>
#include <cmath>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

const ll MOD = 1e9 + 7;

// Fastpower & Moduler Operation (A^B mod C)
ll fast_power(ll base, ll power){
	ll ret = 1;
	// A^B mod C = ((A^(B/2) mod C) * (A^(B/2) mod C)) mod C
	while(power){
		if(power%2)	ret = (ret * base) % MOD;
		base = (base%MOD * base%MOD) % MOD;	// pow
		power /= 2;
	}
	return ret;
}

int main(){
	int N;
	ll sum = 0;
	
	scanf("%d", &N);
	FOR(i, N){
		ll C, K;
		scanf("%lld %lld", &C, &K);
		sum += (C*K % MOD * fast_power(2, K-1)) % MOD;
		sum %= MOD;
	}
	sum %= MOD;
	printf("%lld\n", sum);
	return 0;
}