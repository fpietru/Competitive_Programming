/*
	Franciszek Pietrusiak
	Zadanie: https://sio2.mimuw.edu.pl/c/pa-2024-1/p/kto/
*/
#include <bits/stdc++.h>
using namespace std;
#define PB push_back

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int s[2];
	vector<int> wyniki[2];
	for (int i=0; i<2; i++) {
		s[i] = 0;
		for (int j=0; j<18; j++) {
			int x; cin >> x;
			wyniki[i].PB(x);
			s[i] += x;
		}
		sort(wyniki[i].begin(), wyniki[i].end(), greater<int>());
	}
	
	int ans = 3;
	if (s[0] > s[1])
		ans = 1;
	else if (s[0] < s[1])
		ans = 2;
	else {
		for (int i=0; i<18; i++) {
			if (wyniki[0][i] > wyniki[1][i]) {
				ans = 1;
				break;
			}
			if (wyniki[0][i] < wyniki[1][i]) {
				ans = 2;
				break;
			}
		}
	}
	cout << (ans == 1 ? "Algosia" : (ans == 2 ? "Bajtek" : "remis"));

	return 0;
}
