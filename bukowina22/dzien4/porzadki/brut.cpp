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

constexpr int MxN = 2e5+5;
vector<int> G[MxN], Go[MxN];
int dp[MxN];
int jedynki, liscie;

void dfs(int v, int p)
{
	if (G[v].size() == 1) 
	{
		dp[v] = 1;
		liscie++;
	}
	else {
		for (auto u : G[v])
			if (u != p) {
				dfs(u, v);
				dp[v] += dp[u];
			}
		dp[v] &= 1;
	}
	if (dp[v]) jedynki++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].PB(b); G[b].PB(a);
		Go[a].PB(b); Go[b].PB(a);
	}
	while (q--)
	{
		int m; cin >> m;
		for (int i=n+1; i<=n+m; i++)
		{
			int x; cin >> x;
			G[i].PB(x); G[x].PB(i);
		}
		int root = 0;
		for (int i=1; i<=n+m; i++)
			if (G[i].size() > 1 && root == 0)
			{	
				root = i;
				break;
			}
		liscie = 0;
		jedynki = 0;
		memset(dp, 0, sizeof(dp));
		dfs(root, root);
		if (liscie&1) cout << "-1\n";
		else cout << 2*(n+m-1) - jedynki << "\n";
		for (int i=1; i<=n; i++)     G[i] = Go[i];
		for (int i=n+1; i<=n+m; i++) G[i].clear();
	}

	return 0;
}
