// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/0000000000088231

#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;
const int MAXSIZE = 100+2;

void solve(){
	char N[MAXSIZE];
	string A, B;
	
	fgets(N, MAXSIZE, stdin);
	int len = strlen(N)-1;
	
	for(int i = 0; i < len; i++){
		if(N[i] == '4'){
			A.push_back('1');
			B.push_back('3');
		} else {
			A.push_back(N[i]);
			B.push_back('0');
		}
	}
	
	printf("%s ", A.c_str());
	// The value of N includes at least one digit that is a 4
	for(int i = 0; B[i]; i++){
		if (B[i] != '0'){
			printf("%s\n", B.substr(i).c_str());
			break;
		}
	}
}

int main() {
	int T;
	scanf("%d ", &T);
	for(int t = 1 ; t <= T; t++){
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}