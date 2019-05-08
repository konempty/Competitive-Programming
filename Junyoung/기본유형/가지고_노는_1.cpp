// https://www.acmicpc.net/problem/1612

#include <cstdio>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	int cnt = -1;
	if(N%2 && N%5){
		cnt = 1;
		int one = 1;
		
		while(one %N){	// 나눠 떨어지는 11...1 발견
			one %= N;
			one = one*10 +1;	// 나머지에 계속 1을 확장
			cnt++;
		}
	}
	printf("%d\n", cnt);
	
    return 0;
}