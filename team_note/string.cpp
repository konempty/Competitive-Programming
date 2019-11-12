#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXLEN = 10000 + 2;

string get_str() {
	char input[MAXLEN];
	fgets(input, MAXLEN, stdin);
	input[strlen(input)-1] = NULL;
	return (string)input;
}