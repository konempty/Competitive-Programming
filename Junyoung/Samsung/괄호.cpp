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

const int MAXN = 1000000+3;

vector<int> idx;
vector<int> len;

bool is_open(char s){
	return (s == '(') || (s == '[') || (s == '{');
}
bool is_match(char s, char e){
	return (s == '(' && e == ')') ||
		(s == '[' && e == ']') ||
		(s == '{' && e == '}');
}

void solve(){
	char str[MAXN];
	fgets(str, MAXN, stdin);
	int sz = strlen(str)-1;

	int max_len = 0;
	idx.push_back(-1);
	FOR(i, 0, sz){
		if(is_open(str[i])){
			idx.push_back(i);
		} else if(!idx.empty()) {
			int s = idx.back();	
			if(is_match(str[s], str[i])){
				max_len = max(max_len, i - idx[idx.size()-2]);
				idx.pop_back();
			} else {
				idx.clear();
				idx.push_back(i);
			}
		}
	}
	printf("%d\n", max_len);
}

int main(){
	int T;
	scanf("%d ", &T);
	FOR(t, 1, T+1){
		printf("Case #%d\n", t);
		solve();
	}
	return 0;
}