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

constexpr int MxN = 3e3+33;
int tab[MxN], pos[MxN];
bool used[MxN];
vector<vector<int>> ans;
map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> tab[i];
		mp[tab[i]]++;
	}
	int ord = 1;
	for (auto &it : mp)
		it.SD = ord++;
	for (int i=1; i<=n; i++) {
		tab[i] = mp[tab[i]];
		pos[tab[i]] = i;
	}
	
	while (true) {
		for (int i=1; i<=n; i++)
			used[i] = false;
		deque<int> Q;
		for (int i=1; i<=n; i++)
			if (used[i] == false && used[tab[i]] == false && tab[i] != i) {
				// deb(i, tab[i], pos[i]);	
				used[i] = used[tab[i]] = true;
				Q.push_front(i);
				Q.push_back(pos[i]);
				pos[tab[i]] = pos[i];
				tab[pos[i]] = tab[i];
				tab[i] = i;
				pos[i] = i;
			}	
		if (Q.empty()) break;
		else {
			vector<int> v;
			for (auto it : Q)
				v.PB(it);
			ans.PB(v);
		}
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
