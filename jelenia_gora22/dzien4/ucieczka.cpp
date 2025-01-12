#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second // debugging 
/*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << "[ " << vars << " = "; string delim = "";
	(..., (cout << delim << values, delim = ", "));
	cout << " ]\n";
}
/**/

constexpr int MxN = 1e5+5;
int dp[2][MxN];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string a = "&", b = "#", x;
	cin >> x, a += x;
	cin >> x, b += x;
	int n = a.size() - 1;
	int m = b.size() - 1;
	
	// vector<vector<int>> dp(n+1, vector<int>(m+1, 0)); 
	
	
	/*
	for (int i=1; i<=n; i++)
		dp[i][0] = i;
	for (int j=1; j<=m; j++)
		dp[0][j] = j;
	*/
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			if (a[i] == b[j])
				dp[1][j] = dp[0][j-1] + 1;
			else
				dp[1][j] = max(dp[0][j], dp[1][j-1]);
			
			if (dp[1][j] > 100)
			{
				cout << "DUZO\n";		
				return 0;
			}
		}
		for (int j=0; j<=m; j++)
			dp[0][j] = dp[1][j];
	}
	
	/*
	for (int i=0; i<=n; i++)
	{
		for (int j=0; j<=m; j++)
			cout << dp[i][j] << " ";
		cout << "\n";
	}*/

	cout << dp[1][m] << "\n";	

	return 0;
}
