// http://tech.kakao.com/2017/09/27/kakao-blind-recruitment-round-1/

#include <cstdio>
#include <string>
using namespace std;

const int MAXSIZE = 16+2;

int main() {
	int N;
	int arr1[MAXSIZE];
	int arr2[MAXSIZE];
	
	scanf("%d", &N);
	for(int i =0; i < N; i++)	scanf("%d", &arr1[i]);
	for(int i =0; i < N; i++)	scanf("%d", &arr2[i]);
	
	for(int r =0; r < N; r++){
		string res;
		int val = arr1[r] | arr2[r];
		
		while(val){
			res = (char)(val%2 ? '#' : ' ') + res;
			val /= 2;
		}
		printf("%s\n", res.c_str());
	}	
	return 0;
}