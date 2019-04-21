// https://www.acmicpc.net/problem/2154

#include <cstdio>
#include <string>
using namespace std;

typedef long long ll;
const int MAXN = 100 + 2;

int main() {
	int N;
	ll sum = 0, cnt = 1, thres = 9;
	
	scanf("%d", &N);
	while(true){
		if(N < thres){
			sum += cnt*N;
			break;
		}
		N -= thres;
		sum += (cnt++)*thres;
		thres *= 10;
	}
	printf("%lld\n", sum);
	
    return 0;
}