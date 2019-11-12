#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define ALL(x) (x).begin(), (x).end()

int main(){
	int N;
	scanf("%d", &N);
	vector<int> num(N+1);
	vector<int> res;
	
	FOR(i, 0, N)	scanf("%d", &num[i]);
	num[N] = 1000+10;
	sort(ALL(num));
	FOR(i, 0, N){
		if(num[i] != num[i+1]){
			res.push_back(num[i]);
			continue;
		}
		while(num[i] == num[i+1] && i < N)	i++;
	}
	sort(ALL(res));
	int len = res.size();
	FOR(i, 0, len)	printf("%d ", res[i]);
	return 0;
}