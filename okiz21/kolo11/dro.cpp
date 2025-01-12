/*
	Zadanie "Drogi Zmiennokierunkowe" z XXIII OI, etap II
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 5e5+15;
vector<int> G[MxN];
vector<int> tG[MxN];
vector<int> G_ssc[MxN];
vector<int> tG_ssc[MxN];
vector<int> toposorted;
int SSC[MxN];
int deg[MxN];
bool vis[MxN];
stack<int> S;
int Gtime = 0;
bool zle[MxN];

// pierwsza faza na SSC
void dfs1(int v)
{
    vis[v] = 1;
    for (auto u : G[v])
        if (!vis[u])
            dfs1(u);
   	S.push(v);
}

// druga faza na SSC
void dfs2(int v, int nr_ssc)
{
    SSC[v] = nr_ssc;
    for (auto u : tG[v])
        if (SSC[u] == 0) // można zamienić na (!vis[u]), ale by było trzeba resetować vis
            dfs2(u, nr_ssc);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    // Wczytywanie
    int n, m; cin >> n >> m;
    for (int i=1; i<=m; i++)
    {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        tG[b].push_back(a);
    }
 
    // Wyznaczanie SSC
    for (int i=1; i<=n; i++)
    	if (!vis[i])
    		dfs1(i);
    
    int nr_ssc = 0;
    while (!S.empty())
    {
    	int v = S.top();
    	S.pop();
    	
        if (SSC[v] == 0)
        	dfs2(v, ++nr_ssc);
	}

    // Tworzenie Grafów SSC
    for (int i=1; i<=n; i++)
        for (auto u : G[i])
            if (SSC[i] != SSC[u])
            {
                G_ssc[SSC[i]].push_back(SSC[u]);
                tG_ssc[SSC[u]].push_back(SSC[i]);
                deg[SSC[u]]++;
            }
    
    // Sortowanie topologiczne Grafu SSC
    queue<int> Q;
    for (int i=1; i<=nr_ssc; i++)
        if (deg[i] == 0)
            Q.push(i);
    
    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        toposorted.push_back(v);
        for (auto u : G_ssc[v])
        {
            deg[u]--;
            if (deg[u] == 0)
                Q.push(u);
        }
    }
     
    // wyznaczanie "złych" SSC dla zwykłego grafu SSC
    memset(vis, 0, size(vis));
    int licznik = 0;
    for (int i=nr_ssc-1; i>=0; i--)
    {
    	int v = toposorted[i];
    	for (auto u : G_ssc[v])
    		if (vis[u] == 0)
    		{
    			licznik--;
    			vis[u] = 1;
    		}
    		
    	if (licznik != 0)
    		zle[v] = 1;
    		
    	licznik++;
    }
    
    // wyznaczanie "złych" SSC dla transponowanego grafu SSC
    licznik = 0;
    memset(vis, 0, sizeof(vis));
   	for (int i=0; i<nr_ssc; i++)
    {
    	int v = toposorted[i];
    	for (auto u : tG_ssc[v])
    		if (vis[u] == 0)
    		{
    			licznik--;
    			vis[u] = 1;
    		}
    		
    	if (licznik != 0)
    		zle[v] = 1;
    		
    	licznik++;
    }
    
    // wypisywanie odp
    vector<int> ans;
    for (int i=1; i<=n; i++)
 		if (!zle[SSC[i]])
 			ans.push_back(i);
 	
 	cout << ans.size() << "\n";
 	for (auto p : ans)
 		cout << p << " ";
 	cout << "\n";
    
    return 0;
}
