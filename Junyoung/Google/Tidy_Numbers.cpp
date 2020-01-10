// https://www.acmicpc.net/problem/14791

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define FORo(i,o) for(int i = 0, e = o.size(); i < e; i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair <int, int> pii;
typedef priority_queue<int> pqi;

const int MAXLEN = 20+2;

string str_in() {
	char input[MAXLEN];
	fgets(input, MAXLEN, stdin);
	input[strlen(input)-1] = '\0';
	return (string)input;
}

void solve(){
    string num = str_in();
    int s = 0, e = 0, sz = num.size();
    for(; e < sz-1; e++){
        if(num[e] > num[e+1])   break;
        if(num[e] < num[e+1])   s = e+1;
    }
    // tidy number
    if(e == sz-1){
        printf("%s\n", num.c_str());
        return;
    }
    string tidy = num.substr(0, s);
	if(num[s] > '1')  tidy.push_back(num[s]-1);
    FOR(i, s+1, sz) tidy.push_back('9');
	
    printf("%s\n", tidy.c_str());
}

int main(){
	int T;
	scanf("%d ", &T);
	FOR(t, 1, T+1){
	    printf("Case #%d: ", t);
	    solve();
	}
	return 0;
}