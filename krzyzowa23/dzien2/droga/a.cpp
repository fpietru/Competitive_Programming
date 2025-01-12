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

constexpr int MxN = 4e4+4;
bitset<MxN> vis;
vector<int> G[MxN];
int warstwa[6];

void bfs(int st) {
	queue<pii> Q;
	Q.push({st, 0});
	vis.reset();
	vis[st] = true;
	while (!Q.empty()) {
		pii v = Q.front(); Q.pop();
		if (st == 1) warstwa[v.SD]++;
		else warstwa[5-v.SD]++;
		assert(v.SD <= 2);
		for (auto u : G[v.FR])
			if (vis[u] == false && v.SD < 2) {
				Q.push({u, v.SD+1});
				vis[u] = true;
			}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
	}
	bfs(1);
	bfs(2);
	
	int pozostale = n;
	for (int i=0; i<=5; i++)
		pozostale -= warstwa[i];

	if (warstwa[1] > warstwa[4])
		warstwa[2] += pozostale;
	else warstwa[3] += pozostale;
	
	ll ans = 0LL;
	for (int i=0; i<=5; i++)
		ans += ((warstwa[i]*(warstwa[i]-1)) >> 1);
	for (int i=0; i<5; i++)
		ans += warstwa[i] * warstwa[i+1];
		
	cout << ans - m << "\n";

	return 0;
}
