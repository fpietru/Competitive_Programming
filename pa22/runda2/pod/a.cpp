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

constexpr int MxN = 5e5+5;
constexpr int INF = 1e9+7;
int tab[MxN];
int mi[MxN], mx[MxN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> tab[i];
	mi[0] = INF;
	for (int i=1; i<=n; i++)
		mi[i] = min(mi[i-1], tab[i]);
	mx[n+1] = -INF;
	for (int i=n; i>=1; i--)
		mx[i] = max(mx[i+1], tab[i]);
	
	vector<int> ans;
	if (k == 2) {
		for (int i=1; i<=n-1; i++)
			if (mi[i] >= mx[i+1]) {
				ans.PB(i);
				break;
			}
	}
	else if (k == 3) {
		for (int i=2; i<=n-1; i++)
			if (mi[i-1] >= tab[i] || tab[i] >= mx[i+1]) {
				ans.PB(i-1);
				ans.PB(i);
				break;
			}
	}
	else {
		for (int i=1; i<=n-1; i++)
			if (tab[i] >= tab[i+1]) {
				if (i > 1)
					ans.PB(i-1);
				ans.PB(i);
				ans.PB(i+1);
				
				int x = k;
				x -= 2;
				if (i-1 >= 1) x--;
				if (i+1 <= n) x--;
				
				int j = 1;
				while (j < i-1 && x > 0) {
					ans.PB(j++);
					x--;
				}
				j = i+2;
				while (j <= n && x > 0) {
					ans.PB(j++);
					x--;
				}
				break;
			}
	}
	sort(ans.begin(), ans.end());
	
	if (ans.empty()) {
		cout << "NIE\n";
		return 0;
	}
	
	cout << "TAK\n";
	/*for (auto it : ans)
		cout << it << " ";
	cout << "\n"; */

	bool powt = false;
	for (int i=0; i<(int)ans.size()-1; i++)
		if (ans[i] == ans[i+1]) powt = true;
	if ((int)ans.size() != k-1 || powt)
		cout << "AAAAA!\n";

	return 0;
}
