// https://programmers.co.kr/learn/courses/30/lessons/60060

#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(i,s,e) for(int i = s; i < e; i++)
#define FORr(i,e,s) for(int i = e; i >= s; i--)
#define FORs(i,s,o) for(int i = s, e = o.size(); i < e; i++)
#define FORrs(i,o,s) for(int i = o.size()-1; i >= s; i--)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair <int, int> pii;

const int MAXLEN = 100000 + 2;

vector<int> solution(vector<string> words, vector <string> queries) {
	vector<int> ans;
	int wlen = words.size();

	FORs(r, 0, queries) {
		string query = queries[r];
		bool is_forward = (query.front() == '?');
		if (is_forward && (query.back() == '?')){
			ans.push_back(wlen);
			continue;
		}

		int cnt = 0, qlen = query.size();
		FORs(c, 0, words) {
			string word = words[c];
			if (qlen != word.size())	continue;

			bool matched = true;
			if (!is_forward) {
				FOR(i, 0, qlen) {
					if (query[i] == '?')	break;
					if (query[i] != word[i]) {
						matched = false;
						break;
					}
				}
			} else {
				FORr(i, qlen-1, 0){
					if (query[i] == '?')	break;
					if (query[i] != word[i]) {
						matched = false;
						break;
					}
				}
			}
			cnt += matched;
		}
		ans.push_back(cnt);
	}
	return ans;
}

string get_str() {
	char input[MAXLEN];
	fgets(input, MAXLEN, stdin);
	input[strlen(input)-1] = NULL;
	return (string)input;
}

int main() {
	int N, M;
	vector<string> words, queries;
	
	scanf("%d %d ", &N, &M);
	FOR(i, 0, N)	words.push_back(get_str());
	FOR(i, 0, M)	queries.push_back(get_str());

	vector<int> ans = solution(words, queries);
	//
	FORs(i, 0, ans) {
		printf("%d ", ans[i]);
	}
	//

	return 0;
}