/*
	Zadanie: "Pociąg towarowy", XXX OI, etap I
	Autor: Franciszek Pietrusiak
*/
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

constexpr int MxN = 3e5+5;
constexpr int INF = 1e9+7;
int tab[MxN];
int wzo[MxN];
int ans[2][MxN], tmp[MxN];
vector<int> pos[MxN];
int idx[MxN];
int zbudowane;
int n, m, k;

void solve(int l) {
	for (int i=1; i<=k; i++) pos[i].clear();
	for (int i=1; i<=m; i++)
		pos[wzo[i]].PB(i-1);	
	zbudowane = 0;
	for (int i=1; i<=n; i++) {
		int x = tab[i];
		int j = min(idx[x], (int)pos[x].size()-1);
		if (pos[x].empty()) {
			ans[l][i] = -INF;
			continue;
		}
		if (pos[x][j] <= zbudowane) {
			ans[l][i] = pos[x][j];
			if (pos[x][j] == zbudowane) {
				idx[x]++;
				zbudowane++;
			}			
		}
		else if (j - 1 >= 0 && pos[x][j-1] <= zbudowane) ans[l][i] = pos[x][j-1];
		else                                             ans[l][i] = -INF;
	}
	if (l == 1) {
		for (int i=n; i>=1; i--)
			tmp[n-i+1] = ans[l][i];
		for (int i=1; i<=n; i++)
			ans[l][i] = tmp[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for (int i=1; i<=n; i++) cin >> tab[i];
	for (int i=1; i<=m; i++) cin >> wzo[i];
	
	solve(0);
	reverse(tab+1, tab+1+n);
	memset(idx, 0, sizeof(idx));
	reverse(wzo+1, wzo+1+m);
	solve(1);
		
	for (int i=1; i<=n; i++)
		cout << (ans[0][i] + ans[1][i] + 1 >= m) << (i == n ? "\n" : " ");
	
	return 0;
}
