// https://www.acmicpc.net/problem/14791

#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXSIZE = 20+2;

void solve(){
	char num[MAXSIZE];
	fgets(num, MAXSIZE, stdin);
	int len = strlen(num)-1;
	num[len] = '\0';
	
	int s = 0, e;
	for(e = 1; e < len; e++){
		if(num[e-1] > num[e])	break;
		if(num[e-1] < num[e])	s = e;
	}
	// tidy number
	if(e == len){
		printf("%s\n", num);
		return;
	}
	
	string ret;
	for(int i = 0; i < s; i++)	ret.push_back(num[i]);
	ret.push_back(num[s]-1);
	for(int i = s+1; i < len; i++)	ret.push_back('9');
	
	for(int i = 0; ret[i]; i++){
		if (ret[i] == '0')	continue;
		printf("%s\n", ret.substr(i).c_str());
		return;
	}
}

int main() {
	int T;
	scanf("%d ", &T);
	for(int t = 1; t <= T; t++){		
		printf("Case #%d: ", t);
		solve();
	}
	return 0;
}