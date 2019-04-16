// https://www.acmicpc.net/problem/9375

#include <cstdio>
#include <string>
#include <map>
using namespace std;

const int MAXLEN = 20 + 2;
 
int main(){
    int T;

    scanf("%d ", &T);
	for (int t = 0; t < T; t++) {
		int N;
        map <string,int> cloth;

        scanf("%d", &N);
		for (int n = 0; n < N; n++) {
			char item[MAXLEN], kind[MAXLEN];
			scanf("%s %s", item, kind);
			cloth[string(kind)]++;
		}

        int ans = 1;
		for (auto i = cloth.begin(); i != cloth.end(); i++) {
			ans *= i->second + 1;
		}
        printf("%d\n", ans-1);
    }
    return 0;
}
