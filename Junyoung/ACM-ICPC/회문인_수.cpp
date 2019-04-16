// https://www.acmicpc.net/problem/11068

#include <stdio.h>
#include <vector>

using namespace std;

int is_palindrome(int N) {
	for (int B = 2; B <= 64; B++) {
		vector<int> num;
		
		int temp = N;
		while (temp > 0) {
			num.push_back(temp%B);
			temp /= B;
		}
		int len = num.size();
		bool flag = true;
		for (int i = 0; i < len / 2; i++) {
			if (num[i] != num[len-1-i]){
				flag = false;
				break;
			}
		}
		if (flag)	return 1;
	}
	return 0;
}

int main() {
	int T;

	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);
		printf("%d\n", is_palindrome(N));
	}
	return 0;
}