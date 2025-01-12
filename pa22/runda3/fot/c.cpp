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
vector<vector<int>> ans, cykle;
map<int, int> mp;
int n;

int rand(int a, int b) {
	return a + rand() % (b-a+1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> tab[i];
		mp[tab[i]]++;
	}
	int ord = 1;
	for (auto &it : mp)
		it.SD = ord++;
	for (int i=1; i<=n; i++)
		tab[i] = mp[tab[i]];
	
	while (true) {
		cykle.clear();
		memset(vis, 0, sizeof(vis));
		for (int i=1; i<=n; i++) {
			pos[tab[i]] = i;
			vector<int> cykl;
			int x = tab[i];
			while (vis[x] == false) {
				cykl.PB(x);
				vis[x] = true;
				x = tab[x];
			}
			if (cykl.size() >= 2) {
				if (rand(0, 1))
					rotate(cykl.begin(), cykl.begin()+1, cykl.end());
				cykle.PB(cykl);
			}
		}
		deque<int> Q;
		for (auto c : cykle) {
			// cout << c << "\n";
			int m = c.size();
			for (int i=0; i<m-1; i+=2) {
				Q.push_front(pos[c[i]]);
				Q.push_back(pos[c[i+1]]);
				tab[pos[c[i]]] = c[i+1];
				tab[pos[c[i+1]]] = c[i];
			}
		}
		if (Q.empty()) break;
		else {
			vector<int> v2;
			for (auto it : Q)
				v2.PB(it);
			ans.PB(v2);	
		}
	}
	
	cout << ans.size() << "\n";
	for (auto it : ans) {
		cout << it.size() << "\n";
		for (auto it2 : it)
			cout << it2 << " ";
		cout << "\n";
	}

	return 0;
}
