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

constexpr int MxN = 3e3+3;
int tab[MxN], pos[MxN];
bool vis[MxN];
vector<vector<int>> ans;
vector<int> v;
int n;

int binsearch(int x) {
	int low = 0;
	int high = n;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (v[mid] <= x) low = mid + 1;
		else high = mid;
	}
	return low - 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> tab[i];
		v.PB(tab[i]);
	}
	sort(v.begin(), v.end());
	for (int i=1; i<=n; i++) {
		tab[i] = binsearch(tab[i]) + 1;
		pos[tab[i]] = i;
	}

	while (true) {
		deque<int> Q;
		memset(vis, 0, sizeof(vis));
		for (int i=1; i<=n; i++)
			if (!vis[i] && !vis[tab[i]] && pos[i] != i) {					
				Q.push_back(pos[i]);
				Q.push_front(i);
				tab[pos[i]] = tab[i];
				pos[tab[i]] = pos[i];
				vis[tab[i]] = vis[i] = true;
				tab[i] = i;
				pos[i] = i;
			}
		if (!Q.empty()) {
			vector<int> nop;
			for (auto it : Q)
				nop.PB(it);
			ans.PB(nop);
		}
		else break;
	}
	
	cout << ans.size() << "\n";
	for (auto it : ans) {
		cout << it.size() << "\n";
		for (auto itit : it)
			cout << itit << " ";
		cout << "\n";
	}

	return 0;
}
