// https://www.acmicpc.net/problem/2493

#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;

vector <pair<int, int> > tower;
stack <pair<int, int> > higher_tower;

int main() {
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int data;
		scanf("%d", &data);
		tower.push_back({ i + 1,data });
	}

	// for all input data (->)
	for (int i = 0; i < n; i++) {
		// (<-) until find a data higher than current tower
		while (!higher_tower.empty() && higher_tower.top().second <= tower[i].second) {
			// pop all tower lower than current tower (these are no longer reached)
			higher_tower.pop();
		}
		// if not found receiver then return 0
		int receiver = (higher_tower.empty()) ? 0 : higher_tower.top().first;
		printf("%d ", receiver);
		higher_tower.push(tower[i]);
	}
	return 0;
}
