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

constexpr int MxN = 1e5+5;
constexpr int base = (1<<17);
vector<int> G[MxN];
int Tree[2*base];
bool Lazy[2*base];
int rozmiar[MxN];
int pre[MxN];
int lvl[MxN];
int parent[MxN];
int szczyt[MxN];
int dp[MxN];
bool lisc[MxN];
int root, licznik;

void update(int v, int sl, int sr, int l, int r)
{
    if(Lazy[v]!=0)
    {
        Tree[v]=(sr-sl+1)-Tree[v];
        if(sl!=sr){
            Lazy[2*v]=!Lazy[2*v];
            Lazy[2*v+1]=!Lazy[2*v+1];
        }
        Lazy[v]=0;
    }
    if(r<sl || l>sr || l>r)return;
    if(sl>=l && sr<=r)
    {
        Tree[v]=(sr-sl+1)-Tree[v];
        if(sl!=sr){
            Lazy[2*v]=!Lazy[2*v];
            Lazy[2*v+1]=!Lazy[2*v+1];
        }
        return;
    }
    int mid=sl+(sr-sl)/2;
    update(v*2,sl,mid,l,r);
    update(v*2+1,mid+1,sr,l,r);
    Tree[v]=Tree[v*2]+Tree[v*2+1];
}

int query(int v, int sl, int sr, int l, int r)
{
    if(Lazy[v]!=0)
    {
        Tree[v]=(sr-sl+1)-Tree[v];
        if(sl!=sr){
            Lazy[2*v]=!Lazy[2*v];
            Lazy[2*v+1]=!Lazy[2*v+1];
        }
        Lazy[v]=0;
    }
    if(r<sl || l>sr || l>r) return 0;
    if(sl>=l && sr<=r)      return Tree[v];
    int mid=sl+(sr-sl)/2;
    return query(v*2,sl,mid,l,r) + query(v*2+1,mid+1,sr,l,r);
}

void dfs(int v, int p)
{
	lvl[v] = lvl[p] + 1;
	parent[v] = p;
	rozmiar[v] = 1;
	for (auto u : G[v])
		if (u != p) {
			dfs(u, v);
			rozmiar[v] += rozmiar[u];
		}
}

void dfs2(int v, int p)
{
	int mx=0, heavy = 0;
	pre[v] = ++licznik;
	if (pre[v] == 1) szczyt[v] = v;
	for (auto u : G[v])
		if (u != p && rozmiar[u] > mx) {
			mx = rozmiar[u];
			heavy = u;
		}
	if (heavy != 0) {
		szczyt[heavy] = szczyt[p];
		dfs2(heavy, v);
	}
	for (auto u : G[v])
		if (u != p && u != heavy) {
			szczyt[u] = u;
			dfs2(u, v);
		}
}

void update_tree(int v, int u)
{
	while (szczyt[v] != szczyt[u]) {
		if (lvl[szczyt[v]] < lvl[szczyt[u]]) swap(v, u);
		update(1, 0, base-1, pre[szczyt[v]], pre[v]);
		v = parent[szczyt[v]];
	}
	if (pre[v] < pre[u]) swap(v, u);
	update(1, 0, base-1, pre[u], pre[v]);
}

int query_tree(int v, int u)
{
	int res = 0;
	while (szczyt[v] != szczyt[u]) {
		if (lvl[szczyt[v]] < lvl[szczyt[u]]) swap(v, u);
		res += query(1, 0, base-1, pre[szczyt[v]], pre[v]);
		v = parent[szczyt[v]];
	}
	if (pre[v] < pre[u]) swap(v, u);
	res += query(1, 0, base-1, pre[u], pre[v]);
	return res;
}

void dfs3(int v, int p)
{
	if (lisc[v]) dp[v] = 1;
	else {
		for (auto u : G[v])
			if (u != p) {
				dfs3(u, v);
				dp[v] += dp[u];
			}
		dp[v] &= 1;
	}
	if (dp[v]) update_tree(v, v);
}



int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=1; i<=n-1; i++) {
		int a, b; cin >> a >> b;
		G[a].PB(b), G[b].PB(a);
	}
	
	int liczliscie = 0;
	for (int i=1; i<=n; i++) {
		if (G[i].size() == 1)
			lisc[i] = 1, liczliscie++;
		else if (!root) root = i;
	}
		
	dfs(root, root);
	dfs2(root, root);
	dfs3(root, root);

	// for (int i=1; i<=n; i++)
	// 	deb(i, dp[i]);
	
	while (q--)
	{
		vector<int> cofnij;
		int ilelisci = liczliscie;
		int m; cin >> m;
		map<int, int> mp;
		for (int i=1; i<=m; i++)
		{
			int x; cin >> x;
			mp[x]++;
		}
		for (auto it : mp)
		{
			int v = it.FR;
			int dodaj = it.SD;
			
			if (dodaj == 1 && lisc[v])
				continue;
			
			if (lisc[v]) ilelisci += dodaj - 1;
			else         ilelisci += dodaj;
		
			
		
			// deb(v, dodaj);
			// cout << "Przed:\n";
			// deb(query_tree(root, v));
			if (((dp[v] + dodaj) % 2) != dp[v] || (lisc[v] && (dodaj % 2) == 0))
			{
				// cout << "Updateuje\n";
				update_tree(root, v);
				cofnij.PB(v);
			}
			// cout << "Po:\n";
			// deb(query_tree(root, v));
			// cout << "\n";
		}
		if (ilelisci&1) cout << "-1\n";
		else {
			// deb(Tree[1], m, ilelisci);
			cout << 2*(n-1) - Tree[1] + m << "\n";
			
			// for (int i=1; i<=licznik; i++)
			//	cout << query(1, 0, base-1, i, i) << " ";
			// cout << "\n";
		}
		for (auto it : cofnij)
			update_tree(root, it);
	}

	return 0;
}
