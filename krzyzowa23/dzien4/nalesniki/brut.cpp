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

constexpr int MxN = 2e3+3;
int dp[MxN][MxN]; // dp[k][n] = liczba sposobów na jakie można wybrać k łyżeczek dodatków smakowych z puli n dodatków

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i=0; i<MxN; i++)
		dp[i][0] = 1;
		
	for (int i=1; i<MxN; i++)
		for (int j=1; j<MxN; j++)
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2]) % 3;
	
	/*
	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	} */
	
	int q; cin >> q;
	while (q--) {
		int a, b; cin >> a >> b;
		cout << dp[a][b] << "\n";
	}
	  	

	return 0;
}
