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

constexpr int MxN = 5e4+4;
constexpr int INF = 1e9+7;
int h[MxN], tab[MxN];
int n, ans;

void mamalec(int i) {
	int hprzed = h[i-1];
	int hpo = (i == n ? INF : h[i+1]);
	if (h[i] >= hprzed) {
		ans++;
		h[i] = min(hprzed, hpo) - 1;
	}
}

void marosnac(int i) {
	int hprzed = h[i-1];
	int hpo = (i == n ? -INF : h[i+1]);
	if (h[i] <= hprzed) {
		ans++;
		h[i] = max(hprzed, hpo) + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> tab[i];
	
	int best = INF;
	for (int k=0; k<2; k++) {
		ans = 0;
		bool flag = k;
		for (int i=1; i<=n; i++)
			h[i] = tab[i];
		for (int i=2; i<=n; i++) {
			if (!flag) marosnac(i);
			else mamalec(i);
			flag = !flag;
		}
		best = min(best, ans);
	}
	cout << best << "\n";

	return 0;
}
