/*
	Franciszek Pietrusiak
	Zadanie: https://sio2.mimuw.edu.pl/c/pa-2024-1/p/zna/
*/
#include <bits/stdc++.h>
#define PB push_back
#define FR first
#define SD second
using namespace std;

constexpr int MxN = 3e5+5;
int ans[MxN];
int zlicz[MxN];
map<int, int> mp;
set<int> st;
vector<int> krotnosci;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		int x; cin >> x;
		mp[x]++;
	}
	
	int mx = 0;
	for (auto p : mp) {
		mx = max(mx, p.SD);
		zlicz[p.SD]++;
		st.insert(p.SD);
	}
	for (auto p : st)
		krotnosci.PB(p);
	
	for (int i=1; i<=mx; i++) {
		for (auto p : krotnosci)
			ans[i] += (p / i) * i * zlicz[p];
	}
	
	for (int i=1; i<=n; i++)
		cout << ans[i] << " ";
	cout << "\n";
	
	return 0;
}

