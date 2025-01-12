/*
	Franciszek Pietrusiak
	Zadanie: https://sio2.mimuw.edu.pl/c/pa-2024-1/p/alc/
*/
#include <bits/stdc++.h>
#define PB push_back
#define FR first
#define SD second
using namespace std;
using pii = pair<int, int>;

constexpr int MxN = 3e4+4;
set<int> G[2][MxN];
set<pii> krawedzie[2];
vector<pair<char, pii>> ans;
vector<pii> history;
vector<pii> todo;

pii krawedz(int a, int b) {
	if (a > b) swap(a, b);
	return make_pair(a, b);
}

void dodaj(pii e) {
	if (history.size() >= 2 && e == history[history.size()-2]) {
		todo.PB(e);
		return;
	}
	history.PB(e);
	
	cout << e.FR << " " << e.SD << "\n";
	int v = e.FR;
	int u = e.SD; 
	int middle = -1;
	for (auto z : G[0][v])
		if (G[0][u].find(z) != G[0][u].end()) {
			middle = z;
			break;
		}
	if (middle != -1) {
		cout << "+ " << v << " " << u << "\n";
		ans.PB(make_pair('+', make_pair(v, u)));
		G[0][v].insert(u);
		G[0][u].insert(v);
		krawedzie[0].insert(krawedz(v, u));
	}
	else {
		// if (G[0][v].size() > G[0][u].size()) swap(v, u);
		for (auto z : G[0][v])
			if (z != u && G[0][u].find(z) == G[0][u].end()) {
				dodaj(make_pair(z, u));			
			}
		for (auto z : G[0][u])
			if (z != v && G[0][v].find(z) == G[0][v].end()) {
				dodaj(make_pair(z, v));			
			}
		dodaj(e);
	}
}

void usun(pii e) {
	if (e == make_pair(0,0))
		return;
	int v = e.FR;
	int u = e.SD;
	int middle = -1;
	for (auto z : G[0][v])
		if (G[0][u].find(z) != G[0][u].end()) {
			middle = z;
			break;
		}
	if (middle != -1) {
		cout << "- " << v << " " << u << "\n";
		ans.PB(make_pair('-', make_pair(v, u)));
		G[0][v].erase(u);
		G[0][u].erase(v);
		krawedzie[0].erase(krawedz(v, u));
	}
	else {
		pii nowa1 = {0, 0}, nowa2 = {0, 0};
		for (auto z : G[0][v])
			if (z != u && G[0][u].find(z) == G[0][u].end()) {
				nowa1 = make_pair(z, u);
				dodaj(nowa1);	
				break;
			}
		for (auto z : G[0][u])
			if (z != v && G[0][v].find(z) == G[0][v].end()) {
				nowa2 = make_pair(z, v);
				dodaj(nowa2);	
				break;
			}
		usun(e);
		usun(nowa1);
		usun(nowa2);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int k=0; k<2; k++) {
		int m; cin >> m;
		for (int i=1; i<=m; i++) {
			int a, b; cin >> a >> b;
			G[k][a].insert(b);
			G[k][b].insert(a);
			krawedzie[k].insert(krawedz(a, b));
		}	
	}
	
	/*cout << "n = " << n << "\n";
	for (int i=1; i<=n; i++) {
		cout << i << ": ";
		for (auto p : G[0][i])
			cout << p << " ";
		cout << " | ";
		for (auto p : G[1][i])
			cout << p << " ";
		cout << "\n";
	} */
	
	for (auto e : krawedzie[1]) {
		if (krawedzie[0].find(e) == krawedzie[0].end())
			dodaj(e);
	}
	
	for (auto e : todo) {
		if (krawedzie[0].find(e) == krawedzie[0].end())
			dodaj(e);
	}
	
	vector<pii> krawedzie0_vec;
	for (auto e : krawedzie[0])
		krawedzie0_vec.PB(e);
	
	for (auto e : krawedzie0_vec) {
		if ((krawedzie[0].find(e) != krawedzie[0].end()) && (krawedzie[1].find(e) == krawedzie[1].end()))
			usun(e);
	}
	
	cout << ans.size() << "\n";
	for (auto p : ans)
		cout << p.FR << " " << p.SD.FR << " " << p.SD.SD << "\n"; 
	
	

	return 0;
}
