// https://www.acmicpc.net/problem/10757

#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10000+4;

int main() {
	string A, B;
	
	for(int i =0; i < 2; i++){
		char temp[MAX];
		scanf("%s", temp);
		if (!i)	A = (string)temp;
		else	B = (string)temp;
	}
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	
	int A_len = A.size();
	int B_len = B.size();
	int len = max(A_len, B_len);
	
	string R;
	int carry = 0;
	for(int i = 0; i < len; i++){
		int a = (i < A_len) ? A[i]-'0' : 0;
		int b = (i < B_len) ? B[i]-'0' : 0;
		int sum = a + b + carry;
		carry = sum / 10;
		R.push_back(sum%10+'0');
	}
	if (carry)	R.push_back('1');
	reverse(R.begin(), R.end());
	printf("%s\n", R.c_str());	
	
	return 0;
}