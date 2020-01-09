// https://www.acmicpc.net/problem/12173

#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORo(i,e,o) for(int i = 0, e = o.size(); i < e; i++)
using namespace std;

const int MAXN = 20 + 2;

int X, R, C;

string solve(){
    bool ans = false;
    ans += (X >= 7);            	// 둘러싸기 도형 있는 경우 
    ans += (R*C%X);            		// 개수가 나누어 떨어지지 않는 경우
    ans += (X > max(R,C));        	// 최대 길이가 모서리 벗어나는 경우
    ans += (X/2+X%2 > min(R,C));    // 최소 길이가 모서리 벗어나는 경우
    return ans ? "RICHARD" : "GABRIEL";
}

int main(){
    int T;    scanf("%d", &T);
    FOR(t, 1, T){
        scanf("%d %d %d", &X, &R, &C);
        printf("Case #%d:%s\n", t, solve().c_str());
    }
    return 0;
}