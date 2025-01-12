#include <bits/stdc++.h>
using namespace std;
#define PB push_back

constexpr int MxN = 2e5+5;
int tab[MxN], zlicz[MxN];
set<int> st;
int n, mx;

bool check() {
	int nr = 0;
	for (auto it : st) {
		nr += zlicz[it];
		if (nr > it) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> tab[i];
		if (zlicz[tab[i]] == 0)
			st.insert(tab[i]);
		zlicz[tab[i]]++;
	}
	
	bool ost = check();
	cout << (ost ? "TAK\n" : "NIE\n");
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		
		bool niesprawdzaj = false;
		if (ost == true && tab[a] <= b) {
			cout << "TAK\n";
			niesprawdzaj = true;
		}
		if (ost == false && tab[a] > b) {
			cout << "NIE\n";
			niesprawdzaj = true;
		} 
		
		zlicz[tab[a]]--;
		if (zlicz[tab[a]] == 0)
			st.erase(tab[a]);
		tab[a] = b;
		if (zlicz[tab[a]] == 0)
			st.insert(tab[a]);
		zlicz[tab[a]]++;
		
		if (niesprawdzaj == false) {
			ost = check();
			cout << (ost ? "TAK\n" : "NIE\n");
		}
	}
	
	return 0;
}
