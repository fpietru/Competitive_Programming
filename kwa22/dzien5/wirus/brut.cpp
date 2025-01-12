#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 3e5+13;
int g[MxN];
int x[MxN];
int y[MxN];
int ojciec[MxN];
int spojna[MxN];
int rozmiar[MxN];
vector<int> G[MxN];
int n, licznik = 1, K;
bool dasie;

constexpr int base = (1<<19);
int Tree[2*base+10];

void dodaj(int v, int val)
{
	v += base;
	while (v)
	{
		Tree[v] += val;
		v >>= 1;
	}
}

int kty(int k)
{
	int v = 1;
	while (v < base)
	{
		int L = 2*v;
		int R = 2*v+1;
		
		if (k > Tree[L])
		{
			v = R;
			k -= Tree[L];
		}
		else
			v = L;
	}
	return v - base;
}

void dfs1(int v, int p)
{	
	spojna[v] = licznik;
	rozmiar[licznik]++;
	
	for (auto u : G[v])
		if (u != p)
		{
			dodaj(u, 1);
			ojciec[u] = v;
			dfs1(u, v);
		}
}

void dfs2(int v, int p, int old)
{
	spojna[v] = licznik;
	rozmiar[licznik]++;
	
	for (auto u : G[v])
		if (u != p && spojna[u] == old)
			dfs2(u, v, old);
}

int l(int i)
{
	return (y[i] + g[i]) % (n-i-1) + 1;
}

void dfs3(int v, int p)
{
	K--;
	
	int sasiedzi = 0;
	for (auto u : G[v])
		if (dasie && u != p && spojna[u] == spojna[v])
			sasiedzi++;
	
	// deb(v, K);
	if (K <= 0 && sasiedzi > 0)
	{
		dasie = 0;
		return;
	}
	
	for (auto u : G[v])
		if (dasie && u != p && spojna[u] == spojna[v])
			dfs3(u, v);
}

bool kogowybrac(int a, int b)
{
	int kurwa = 1;
	while (true)
	{
		dasie = 1;
		K = kurwa;
		dfs3(a, b);
		if (dasie)
			return 1;
		
		dasie = 1;
		K = kurwa;
		dfs3(b, a);
		if (dasie)
			return 0;
		
		kurwa <<= 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> x[1];
	for (int i=1; i<=n-2; i++)
		cin >> g[i];
	for (int i=1; i<=n-1; i++)
	{
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	dfs1(1, 1);


	/*
	for (int j=1; j<=n; j++)
		deb(j, spojna[j]);
	cout << "\n";
	*/

	for (int i=1; i<=n-1; i++)
	{
		int S = x[i];
		int O = ojciec[S];
		dodaj(S, -1);

		bool kto = kogowybrac(S, O);

		if (kto == 1)
			swap(S, O);

		int old = spojna[S];
		licznik++;
		dfs2(S, O, old);
		
		rozmiar[spojna[O]] -= rozmiar[spojna[S]];

		if (kto == 0)
			y[i] = rozmiar[spojna[S]];			
		else
			y[i] = rozmiar[spojna[O]];

		
		if (i < n-1)
			x[i+1] = kty(l(i));
	}

	for (int i=1; i<=n-1; i++)
		cout << y[i] << "\n";	
    
    return 0;
}
