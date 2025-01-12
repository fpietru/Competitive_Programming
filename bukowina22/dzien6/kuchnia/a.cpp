#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__) // debugging 
/*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename ...Args> void logger(string vars, Args&&... values) { cout<<"[ "<<vars<<" = "; string delim=""; (..., (cout<<delim<<values, delim=", ")); cout <<" ]\n"; }
/**/

constexpr int INF = 1e9+7;
constexpr int MxN = 333;
int czas[MxN];
int pracuje[MxN];
int suma_dan;
int dp[MxN][MxN];

int podz12(int n, int m, int k)
{
	int res = INF;
	for (int maska=0; maska<(1<<m); maska++)
	{
		int ile_mam = 0;
		int pracuja = 0;
		for (int i=0; i<m; i++)
			if (maska&(1<<i) && pracuje[i+1] >= n) 
			{
				ile_mam++;
				pracuja += pracuje[i+1];
			}
		if (ile_mam < k)
			continue;
		int wynik = pracuja - suma_dan;
		if (wynik >= 0) res = min(res, wynik);
	}
	return res;
}

int podz3(int m, int k)
{
	for (int i=0; i<=m; i++)
		for (int j=0; j<=k; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;
	for (int i=1; i<=m; i++)
		dp[i][0] = 0;
	for (int i=1; i<=m; i++)
		for (int j=1; j<=i; j++)
		{
			int wczesniej = INF;
			for (int z=0; z<i; z++)
				wczesniej = min(wczesniej, dp[z][j-1]);
			dp[i][j] = wczesniej + pracuje[i];
		}
		
	int res = INF;
	for (int i=k; i<=m; i++)
		if (dp[m][i] >= suma_dan)
			res = min(res, suma_dan - dp[m][i]);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m, k; cin >> n >> m >> k;
	for (int i=1; i<=n; i++)
	{
		cin >> czas[i];
		suma_dan += czas[i];
	}
	for (int i=1; i<=m; i++) cin >> pracuje[i];
	for (int i=1; i<=n; i++)
		if (k > m || k > czas[i])
			{ cout << "Impossible\n"; return 0; };

	int ans;
	if (k == 1 && m > 20) ans = podz3(m, k);
	else ans = podz12(n, m, k);

	if (ans == INF)
		cout << "Impossible\n";
	else cout << ans << "\n";
	
	return 0;
}
