#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAXLEN = 10000 + 2;

string str_in() {
	char input[MAXLEN];
	fgets(input, MAXLEN, stdin);
	input[strlen(input)-1] = '\0';
	return (string)input;
}

int main(){
	// substr
	string a = "nice_to_meet_you";
	// nice_to_meet_you
	string a1 = a.substr();
	// to_meet_you
	string a2 = a.substr(5);
	// e_to_
	string a3 = a.substr(3, 5);
	
	
}