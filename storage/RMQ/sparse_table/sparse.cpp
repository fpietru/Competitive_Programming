/*
	RMQ na sparse table
	Sprawdzenie Poprawności: https://cses.fi/problemset/task/1647/
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second
#define PB push_back // debugging /*
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

constexpr int MxN = 2e5+5;
constexpr int LOG = 19;
int dp[LOG+1][MxN]; // dp[k][i] = minimalna wartość na przedziale [i, i+2^k-1]
int lg[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	lg[1] = 0;
	for (int i=2; i<MxN; i++)
		lg[i] = lg[i/2] + 1;

	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++)
		cin >> dp[0][i];
	
	for (int k=1; k<=lg[n]; k++)
		for (int i=1; i+(1<<k)<=n+1; i++) // <- to n+1 jest ważne, bo indeksuje od 1, nie 0
			dp[k][i] = min(dp[k-1][i], dp[k-1][i+(1<<(k-1))]);
			
	while (q--)
	{
		int a, b; cin >> a >> b;
		int p = lg[b-a+1];
		int ans = min(dp[p][a], dp[p][b-(1<<p)+1]);
		cout << ans << "\n";
	}
	
	return 0;
}
