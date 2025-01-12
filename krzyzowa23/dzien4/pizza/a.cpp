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

vector<int> pos[26];

int licz(int a, int b) {
	int i=0, j=0;
	int n = pos[a].size();
	int m = pos[b].size();
	int mi = 1e9+7, r = 0;
	int res = 0, wywal = 0;;
	while (i < n && j < m) {
		if (pos[a][i] < pos[b][j]) r++, i++;
		else {
			r--, j++;
			mi = min(mi, wywal);
			wywal = r;
		}
		res = max(res, r - mi);
	}
	while (i < n) {
		r++, i++;
		res = max(res, r - mi);
	}
	while (j < m) {
		r--, j++;
		mi = min(mi, wywal);
		wywal = r;
		res = max(res, r - wywal);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	string s; cin >> s;
	for (int i=0; i<n; i++)
		pos[s[i]-'a'].PB(i);

	int ans = 0;
	for (int i=0; i<26; i++)
		for (int j=0; j<26; j++) {
			if (i == j || pos[i].empty() || pos[j].empty())
				continue;
			ans = max(ans, licz(i, j));			
		}
		
	cout << ans << "\n";

	return 0;
}
