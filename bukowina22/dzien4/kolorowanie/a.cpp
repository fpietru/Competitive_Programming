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

constexpr int M = 1e9+7;
constexpr int MxN = 2e3+3;
int f[MxN*MxN];
int inv[MxN*MxN];
int dp[MxN][MxN];

int fastpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b&1) res = ((ll)res * a) % M;
		a = ((ll)a * a) % M;
		b >>= 1;
	}
	return res;
}

int newton(int n, int k)
{
	if (k == 0 || n == 0) return 1;
	return (((ll)f[n] * inv[k]) % M * (ll)inv[n-k]) % M;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	f[0] = f[1] = 1;
	for (int i=2; i<=n*k; i++)
		f[i] = ((ll)f[i-1] * i) % M;
	inv[n*k] = fastpow(f[n*k], M-2);
	for (int i=n*k-1; i>=1; i--)
		inv[i] = ((ll)inv[i+1] * (i+1)) % M;
	
	dp[1][0] = 1;
	for (int i=1; i<=n; i++)
		for (int j=0; j<=i; j++)
		{
			if (j > 0)
			{
				int NEWTON = newton((k-1)*j+i-1, k-2);
				dp[i][j] += ((ll)NEWTON * dp[i][j-1]) % M;
				// deb(NEWTON);
			}
			if (i != j) dp[i][j] += dp[i-1][j];
		}
	
	for (int i=1; i<=n; i++)
		for (int j=0; j<=i; j++)
			deb(i, j, dp[i][j]);
		
	cout << ((ll)dp[n][n] * f[n]) % M << "\n";

	return 0;
}
