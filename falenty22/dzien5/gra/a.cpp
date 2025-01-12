#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int MxN = 22;
ll t[MxN][MxN];
map<ll, ll> mp[MxN][MxN];
bool przek[MxN][MxN];
int n, m, D;
ll K, ans;

void go1(int y, int x, int dl, ll xsum) {
	if (y > n || x > m) return;
	xsum ^= t[y][x];
	if (dl == D) {
		przek[y][x] = true;
		mp[y][x][xsum]++;
		return;
	}
	go1(y+1, x, dl+1, xsum);
	go1(y, x+1, dl+1, xsum);
}

void go2(int y, int x, int dl, ll xsum) {
	if (y < 1 || x < 1) return;
	if (przek[y][x]) {
		ans += mp[y][x][xsum];
		return;
	}
	xsum ^= t[y][x];
	go2(y-1, x, dl+1, xsum);
	go2(y, x-1, dl+1, xsum);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> K;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			cin >> t[i][j];
	D = (n+m) / 2;

	go1(1, 1, 1, K);
	go2(n, m, 1, 0LL);
	
	cout << ans << "\n";

	return 0;
}
