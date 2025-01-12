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
 
struct start
{
	int v;
	int p;
	int t;
};
constexpr int MxN = 1e5+5;
map<string, int> mp;
vector<int> G[MxN];
vector<int> tG[MxN];
vector<int> G2[MxN];
vector<vector<int>> cykle; 
stack<int> postorder;
int skojarzony[MxN];
int vis[MxN], vis2[MxN];
int licznik, gtime, treeSZ, cykle2;
bool nacyklu[MxN];
bool jestcykl;
int parent[MxN];
int suma_matchingow;
vector<start> roots;
vector<int> curr_cykl;
 
void dfs(int v)
{
	vis[v] = 1;
	for (auto u : G[v])
		if (!vis[u]) dfs(u);
	postorder.push(v);
}
 
void dfs2(int v)
{
	curr_cykl.PB(v);
	vis[v] = 1;
	for (auto u : tG[v])
		if (!vis[u]) dfs2(u);
} 
 
void makedrzewo(int v, int p)
{
	int vid = treeSZ;
	for (auto u : tG[v])
		if (u != p)
		{
			int uid = ++treeSZ; 
			G2[vid].PB(uid);
			G2[uid].PB(vid);
			makedrzewo(u, v);
		}
}
 
bool powieksz(int v)
{
	vis2[v] = gtime;
	for (auto u : G2[v])
		if (skojarzony[u] == -1)
		{ skojarzony[v] = u; skojarzony[u] = v; return 1; }
	for (auto u : G2[v])
		if (vis2[skojarzony[u]] != gtime && powieksz(skojarzony[u]))
		{ skojarzony[v] = u; skojarzony[u] = v; return 1; }
	return 0;
}
 
int get_matching()
{
	for (int i=1; i<=treeSZ; i++)
		skojarzony[i] = -1;
	while (true)
	{
		++gtime;
		bool flag = 0;
		for (int i=1; i<=treeSZ; i++)
			if (skojarzony[i] == -1 && powieksz(i))
				flag = 1;
		if (!flag)
			break;
	}
	int res = 0;
	for (int i=1; i<=treeSZ; i++)
		if (skojarzony[i] != -1)
			res++;
	return (res>>1);
}
 
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
 
	int n; cin >> n;
	if (n&1) { cout << "-1\n"; return 0; }
	for (int i=1; i<=n; i++)
	{
		int a, b;
		string A, B; cin >> A >> B;
		if (mp[A] == 0) a = mp[A] = ++licznik;
		else            a = mp[A];
		if (mp[B] == 0) b = mp[B] = ++licznik;
		else            b = mp[B];
		G[a].PB(b); tG[b].PB(a);
		if (a == b)
			cykle.PB({a});
	}
 
	for (int i=1; i<=n; i++) 
		if (!vis[i]) dfs(i);
	memset(vis, 0, sizeof(vis));
	while (!postorder.empty())
	{
		int v = postorder.top();
		postorder.pop();
		curr_cykl.clear();
		dfs2(v);
		if (curr_cykl.size() >= 2)
			cykle.PB(curr_cykl);
	}
 
	for (auto c : cykle)
	{
		for (auto it : c)
			nacyklu[it] = 1;
		if (c.size() == 2)
			cykle2++;
		for (auto it : c)
			for (auto u : tG[it])
				if (!nacyklu[u])
				{
					if (c.size() == 2) roots.PB({u, it, 1});
					else               roots.PB({u, it, 2});
				}
	}
	
	for (auto r : roots)
	{
		treeSZ = 1;
		makedrzewo(r.v, r.p);
		int przed = get_matching();	
		if (r.t == 1)
			suma_matchingow += przed;
		else
		{			
			treeSZ++;
			G2[treeSZ].PB(1);
			G2[1].PB(treeSZ);
			int po = get_matching();
			if (nacyklu[r.p] && po > przed)
			{
				nacyklu[r.p] = 0;
				suma_matchingow += po;
			}
			else suma_matchingow += przed;
		}
		for (int i=1; i<=treeSZ; i++)
			G2[i].clear();
	}
	
	for (auto c : cykle)
	{
		if (c.size() <= 2) continue;
		vector<int> vec;
		for (auto v : c) vec.PB(v);
		for (auto v : c) vec.PB(v);
		int pierwsze_zabranie = 0;
		
		for (int i=0; i<(int)vec.size(); i++)
			if (!nacyklu[vec[i]] && pierwsze_zabranie == 0)
				pierwsze_zabranie = i;
		
		for (int j=pierwsze_zabranie+1; j<(int)vec.size()-1; j++)
			if (nacyklu[vec[j]] && nacyklu[vec[j+1]])
			{
				suma_matchingow++;
				nacyklu[vec[j]] = nacyklu[vec[j+1]] = 0;
			}
	}
	
	cout << suma_matchingow + (n - 2*suma_matchingow - 2*cykle2)<< "\n";	
 
	return 0;
}
