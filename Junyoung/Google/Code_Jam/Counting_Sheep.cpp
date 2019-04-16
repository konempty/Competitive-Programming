// https://www.acmicpc.net/problem/14382

#include <cstdio>
#include <string>
#include <set>
using namespace std;

void solve(){
	int N, num;
	set <int> has_digit;
	set <int> visited;
	
	scanf("%d", &N);
	
	num = N;
	while(true){
		// visit check
		if(visited.count(num))	break;
		visited.insert(num);
		
		// digit check
		string digit = to_string(num);
		int len = digit.size();
		for(int i =0; i < len; i++){
			if(!has_digit.count(digit[i])){
				has_digit.insert(digit[i]);
			}
		}
		if (has_digit.size() >= 10){
			printf("%d\n", num);
			return;
		}
		
		num += N;
	}	
	printf("INSOMNIA\n");
}

int main() {
	int T;
	
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}