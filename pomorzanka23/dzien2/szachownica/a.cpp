#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second

struct pionek {
	char typ;
	int y, x;
	ll ans;
};
int n, m;
constexpr int MxN = 2e5+5;
pionek pionki[MxN];
map<int, set<int>> kolumny;
map<int, set<int>> wiersze;
map<int, set<int>> przekatna1;
map<int, set<int>> przekatna2;
map<pii, bool> mp;

inline int prz1(int y, int x) {
	return y-x;
}
inline int prz2(int y, int x) {
	return y-(m-x+1);
} 

bool ok(int y, int x) {
	if (y < 1 || y > m || x < 1 || x > m || mp.find({y, x}) != mp.end())
		return false;
	return true;
}

ll miejsce(set<int> &st, int x) {
	ll res = 0LL;
	auto it = st.upper_bound(x);
	if (it != st.end()) res += (*it) - x - 1;
	it = st.lower_bound(x);
	if (it != st.begin()) {
		it--;
		res += x - (*it) - 1;
	}
	return res;
}

ll krol(int y, int x) {
	vector<pii> ruchy = {{-1,0}, {+1,0}, {0,-1}, {0,+1}, {-1,-1}, {-1,+1}, {+1,-1}, {+1,+1}};
	ll res = 0LL;
	for (auto r : ruchy)
		res += ok(y+r.FR, x+r.SD);
	return res;
}

ll skoczek(int y, int x) {
	vector<pii> ruchy = {{-2,+1}, {-1,+2}, {+1,+2}, {+2,+1}, {+2,-1}, {+1,-2}, {-1,-2}, {-2,-1}};
	ll res = 0LL;
	for (auto r : ruchy)
		res += ok(y+r.FR, x+r.SD);
	return res;
}

/*
ll wieza(int y, int x) {
	
}*/

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		char t; int y, x; cin >> t >> y >> x;
		pionki[i] = {t, y, x, 0};
		kolumny[x].insert(y);
		wiersze[y].insert(x);
		przekatna1[prz1(y,x)].insert(prz2(y,x));
		przekatna2[prz2(y,x)].insert(prz1(y,x));
		mp[{y, x}] = true;
	}
	
	for (auto it : kolumny) {
		it.SD.insert(0);
		it.SD.insert(m+1);
	}
	for (auto it : wiersze) {
		it.SD.insert(0);
		it.SD.insert(m+1);
	}
	for (auto it : przekatna1) {
		pii b1 = {m+1, 0};
		pii b2 = {0, m+1};
		it.SD.insert(prz2(b1));
		it.SD.insert(prz2(b2));
	}
	for (auto it : przekatna2) {
		pii b1 = {m+1, 0};
		pii b2 = {0, m+1};
		it.SD.insert(prz2(b1));
		it.SD.insert(prz2(b2));
	}

	return 0;
}
