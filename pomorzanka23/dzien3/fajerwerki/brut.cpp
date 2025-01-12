#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define PB push_back

struct pt {
	ll x, y;
};
constexpr ll INF = 1e18+7;
constexpr int MxN = 1e5+5;
pt punkt[MxN];
istream& operator>> (istream& is, pt &p) { is >> p.x >> p.y; return is; }
ostream& operator<< (ostream& os, pt p) { os << "(" << p.x << "," << p.y << ")"; return os; }
ll dist(pt a, pt b) { return abs(b.x-a.x) + abs(b.y-a.y); }

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, s; cin >> n >> s;
	vector<int> pos;
	for (int i=1; i<=n; i++) {
		int x, y; cin >> y >> x;
		punkt[i] = {x, y};
		pos.PB(punkt[i].x);
		pos.PB(punkt[i].x-s);
		pos.PB(punkt[i].x+s);
		// cout << i << " " << punkt[i] << "\n";
	}
	sort(pos.begin(), pos.end());
	pos.erase(unique(pos.begin(), pos.end()), pos.end());

	ll ans = INF;
	for (auto u : pos) {
		pt sr = {u, 0};
		pt c1 = {u, s};
		pt c2 = {u+s, 0};
		pt c3 = {u, -s};
		pt c4 = {u-s, 0};
		ll wyn = 0LL;
		for (int i=1; i<=n; i++) {
			pt p = punkt[i];
			if (abs(p.x - sr.x) < s && abs(p.y - sr.y) < s) { // jest w kwadracie
				// cout << i << " w kradracie!\n";
				wyn += min({dist(p, c1), dist(p, c2), dist(p, c3), dist(p, c4)});
			}
			else {
				//cout << i << " poza\n";
				wyn += min(abs(p.y), abs(p.x-sr.x));
			}
		}
		ans = min(ans, wyn);
	}
	cout << ans << "\n";

	return 0;
};
