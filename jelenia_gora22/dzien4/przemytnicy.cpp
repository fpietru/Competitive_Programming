#include <bits/stdc++.h>
using namespace std;
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


constexpr int MxN = 1e4+44;
constexpr ll INF = 1e18+7;
vector<pair<int, ll>> G[MxN];
ll d[MxN];
int n, m;

void dijkstra(int st)
{
	for (int i=0; i<=2*n; i++)
		d[i] = INF;
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
	
	d[st] = 0LL;
	Q.push({0LL, st});
	
	while (!Q.empty())
	{
		ll dst = Q.top().FR;
		int v = Q.top().SD;
		Q.pop();
		
		if (dst != d[v])
			continue;
		
		for (auto e : G[v])
			if (d[e.FR] > d[v] + e.SD)
			{
				d[e.FR] = d[v] + e.SD;
				Q.push({d[e.FR], e.FR});
			}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		ll clo; cin >> clo;
		G[i].push_back({i+n, clo / 2});
	}
		
	cin >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		G[a].push_back({b, w});
		G[a+n].push_back({b+n, w});
	}
	
	dijkstra(1);
	cout << d[1+n] << "\n";

	return 0;
}
