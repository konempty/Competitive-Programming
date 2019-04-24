// https://www.acmicpc.net/problem/9464

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXL = 1000000/2;
vector <pair<int,int>> PT;

int gcd(int a, int b){
	int mod;
    while ((mod = a%b) > 0) {
        a = b;
        b = mod;
    }
    return b;
}

bool cmp(pair<int,int> pt1, pair<int,int> pt2){
	return pt1.first+pt1.second < pt2.first+pt2.second;
}

void init_PT(){
	int L = MAXL;
	for(int y = 1; ; y++){
		int x = y+1;
		int a = 2*x*y;
		int b = x*x-y*y;
		
		if(a+b > MAXL)	break;
		while(true){
			a = 2*x*y;
			b = x*x-y*y;
			
			if (a+b > MAXL)	break;
			if (a > b)	swap(a,b);
			int g = gcd(a,b);
			PT.push_back({ a/g,b/g });
			x++;
		}
	}
	// 합동 제거
	sort(PT.begin(), PT.end());
	PT.erase(unique(PT.begin(), PT.end()), PT.end());
	// L 크기 순으로 정렬
	sort(PT.begin(), PT.end(), cmp);
}

int main() {
	init_PT();
	
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; t++){
		int L;
		scanf("%d", &L);
		L /= 2;
		
		int sum = 0, i = 0;
		while(true){
			int l = PT[i].first + PT[i].second;
			if((sum += l) > L)	break;
			i++;
		}
		printf("%d\n", i);
	}
}
