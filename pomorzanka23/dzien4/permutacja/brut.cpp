#include <bits/stdc++.h>
using namespace std;
#define PB push_back

constexpr int MxN = 2e5+5;
int tab[MxN], zlicz[MxN], p[MxN];
multiset<int> st;
int n, mx;

bool check() {
	auto it = st.end(); it--;
	mx = *it;
	p[1] = zlicz[1];
	if (p[1] > 1) return false;
	for (int i=2; i<=mx; i++) {
		p[i] = p[i-1] + zlicz[i];
		if (p[i] > i) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> tab[i];
		zlicz[tab[i]]++;
		st.insert(tab[i]);
	}
	
	cout << (check() ? "TAK\n" : "NIE\n");
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		zlicz[tab[a]]--;
		st.erase(st.find(tab[a]));
		tab[a] = b;
		zlicz[tab[a]]++;
		st.insert(tab[a]);
		cout << (check() ? "TAK\n" : "NIE\n");
	}
	
	return 0;
}
