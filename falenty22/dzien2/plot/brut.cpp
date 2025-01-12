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

constexpr int MxN = 2e5+5;
constexpr int LOG = 19;
int st[LOG+1][MxN];
int lg[MxN];
int t[MxN];

int getmax(int a, int b) {
	int p = lg[b-a+1];
	return max(st[p][a], st[p][b-(1<<p)+1]);	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	lg[1] = 0;
	for (int i=2; i<MxN; i++)
		lg[i] = lg[i/2] + 1;	
	
	int n; cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> t[i];
		st[0][i] = t[i];
	}
	
	for (int k=1; k<=lg[n]; k++)
		for (int i=1; i+(1<<k)<=n+1; i++)
			st[k][i] = max(st[k-1][i], st[k-1][i+(1<<(k-1))]);
	
	int ans = 0;
	for (int i=1; i<=n-1; i++)
		for (int j=i+1; j<=n; j++) {
			if (getmax(i, j) == t[i] + t[j]) {
				ans++;
				// deb(i, j, getmax(i, j));			
			}
		}
	cout << ans << "\n";

	return 0;
}
