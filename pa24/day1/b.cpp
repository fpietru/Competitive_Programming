/*
	Franciszek Pietrusiak
	Zadanie: https://sio2.mimuw.edu.pl/c/pa-2024-1/p/lid/
*/
#include <bits/stdc++.h>
using namespace std;
#define PB push_back

constexpr int MxN = 5e5+5;
int zlicz[MxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		zlicz[x]++;
	}
	
	sort(zlicz+1, zlicz+1+n);
	int pocz = 1, kon = n;
	while (pocz < kon) {
		int biore = min(zlicz[pocz], zlicz[kon]-1);
		zlicz[pocz] -= biore;
		zlicz[kon] -= biore;
		if (zlicz[pocz] == 0) pocz++;
		if (zlicz[kon] <= 1) kon--;
	}
	cout << n - pocz + 1 << "\n";

	return 0;
}
