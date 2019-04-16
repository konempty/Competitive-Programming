#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> num;
vector <int> divisor;

int get_gcd(int a, int b) {
    int mod;
 
    while ((mod = a%b) > 0) {
        a = b;
        b = mod;
    }
    return b;
}

int main() {
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int input;
		scanf("%d", &input);
		num.push_back(input);
	}
	sort(num.begin(), num.end());

	int gcd = num[1]-num[0];
	for (int i = 1; i < N-1; i++) {
		gcd = get_gcd(gcd, num[i+1]-num[i]);
	}
	for (int i = 1; i*i <= gcd; i++) {
		if (gcd % i != 0)	continue;
		divisor.push_back(i);
		if (i == gcd / i)	continue;
		divisor.push_back(gcd/i);
	}
	sort(divisor.begin(), divisor.end());

	int len = divisor.size();
	for (int i = 1; i < len; i++) {
		printf("%d ", divisor[i]);
	}
	return 0;
}