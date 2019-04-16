// https://www.acmicpc.net/problem/8891

#include <cstdio>

using namespace std;

int px, py;

void find_coord(int num){
	int dist = 1, lev = 1;
	
	while(dist < num)	dist += ++lev;
	dist -= num;
	px += lev-dist;
	py += 1+dist;
}

int main() {
	int T;
	
	scanf("%d", &T);
	for(int t= 0; t < T; t++){
		int a, b;
		px = 0;	py = 0;
		scanf("%d %d", &a, &b);
		
		find_coord(a);
		find_coord(b);
		
		int cnt = px + py -2;
		cnt = cnt*(cnt+1)/2;
		cnt += px;
		printf("%d\n", cnt);
	}
	return 0;
}