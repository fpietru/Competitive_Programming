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

vector<int> best[100];

void go(int l, int x, int st, vector<int> mam) {
	if (l < 1) {
		if (x == 0 && best[st].empty()) {
			best[st] = mam;
		}
		return;
	}
	else if (best[st].empty()) {
		go(l-1, x, st, mam);
		mam.PB(l);
		go(l-1, x-__builtin_popcount(l), st, mam);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	vector<int> nic;
	
	for (int i=1; i<=n; i++) {
		go(100, i, i, nic);
		cout << i << " " << best[i] << "\n";
		map<int, vector<int>> mp;
		for (int j=best[i].size()-1; j>=0; j--)
			mp[__builtin_popcount(best[i][j])].PB(best[i][j]);
		for (auto it : mp) {
			cout << it.FR << " " << it.SD << "\n";
		}
		cout << "\n";
	}
	

	return 0;
}
