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

constexpr int MxN = 1e4+4;
constexpr ll MOD = 1e9+7;
ll dp[MxN][2][100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string s; cin >> s;
	int n = s.size();
	int m; cin >> m;
	
	int lim = s[0]-'0';
	for (int c=0; c<=lim; c++)
		dp[0][(c==lim ? 1 : 0)][c%m]++;	
		
	for (int i=0; i<n-1; i++) {
		for (int suma=0; suma<m; suma++) {
			lim = s[i+1] - '0';
			for (int c=0; c<=9; c++) {
				int nsuma = (suma + c) % m;
				dp[i+1][0][nsuma] = (dp[i+1][0][nsuma] + (dp[i][0][suma] + (c < lim ? dp[i][1][suma] : 0)) % MOD) % MOD;
				dp[i+1][1][nsuma] = (dp[i+1][1][nsuma] + (c == lim ? dp[i][1][suma] : 0)) % MOD;
			}
		}
	}
	
	cout << (dp[n-1][0][0] + dp[n-1][1][0] - 1 + MOD) % MOD << "\n";

	return 0;
}
