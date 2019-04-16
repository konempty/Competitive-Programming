// https://www.acmicpc.net/problem/1181

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXLENGTH = 50+2;

int N;
vector <string> str;

bool compare(string a, string b) {
	if (a.length() == b.length())
		return (a < b);
	else
		return a.length() < b.length();
}

int main() {
	scanf("%d ", &N);

	for (int n = 0; n < N; n++) {
		char* temp = new char[MAXLENGTH];
		fgets(temp, sizeof(char)*MAXLENGTH, stdin);
		temp[strlen(temp) - 1] = NULL;
		str.push_back(string(temp));
	}

	sort(str.begin(), str.end(), compare);
	
	for (int n = 0; n < N; n++) {
		if (n != N-1 && str[n] == str[n+1])
			continue;
		printf("%s\n", str[n].c_str());
	}
	return 0;
}