#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

struct pt {
	ll x, y;
	pt operator+ (pt p) { return {x+p.x, y+p.y}; }
	pt operator- (pt p) { return {x-p.x, y-p.y}; }
	pt operator* (ll k) { return {k*x, k*y}; }
};
istream& operator>> (istream &is, pt &p) { is >> p.x >> p.y; return is; }
ostream& operator<< (ostream &os, pt p) { os << "(" << p.x << "," << p.y << ")"; return os; }
ll dl(pt p) { return p.x*p.x + p.y*p.y; }

constexpr int MxN = 2e3+3;
map<pair<pair<ll,ll>, ll>, int> mp;
pt p[MxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> p[i];
		
	for (int i=1; i<n; i++)
		for (int j=i+1; j<=n; j++) {
			pt a = p[i]; pt b = p[j];
			pt sr = a+b;
			mp[{{sr.x, sr.y}, dl(a-b)}]++;
		}
	
	ll ans = 0;	
	for (auto it : mp) {
		// cout << it.FR.FR.FR << " " << it.FR.FR.SD << " " << it.FR.SD << " : " << it.SD << "\n";
		ans += (it.SD >> 1);
	}
	
	cout << ans << "\n";
	
	return 0;
}
