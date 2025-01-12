#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back // debugging 
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

constexpr int MxN = 3e4+4;
constexpr int MOD = 1e9+9;
int dp0[MxN];
int dp1[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	string s = "%", x;
	cin >> x; s += x;

	dp0[1] = 1;
	for (int i=1; i<=n; i++)
	{
		int limit = min((i+1), n-i+1);
		for (int k=1+(i&1); k<=limit; k+=2)
		{
			if (s[i] == '(')
			{
				dp1[k] = dp0[k-1] + dp0[k+1];
				if (dp1[k] >= MOD) dp1[k] -= MOD;
			}
			else dp1[k] = dp0[k+1];
		}
		for (int k=1+(i&1); k<=limit; k+=2) dp0[k] = dp1[k];
	}

	cout << dp1[1] << "\n";

	return 0;
}
