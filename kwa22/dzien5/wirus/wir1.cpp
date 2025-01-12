#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 3e5+5;
vector<int> G[MxN];
int rozmiar_poddrzewa[MxN];
int g[MxN], x[MxN];
int ans[MxN];
int ojciec[MxN];
int n;
map<pii, bool> usunieta;
vector<int> maja_ojca;

void dodaj(int val)
{
	bool flag = 0;
	for (auto p : maja_ojca)
		if (p == val)
			flag = 1;
	
	if (flag == 1)
		return;
	
	maja_ojca.push_back(val);
	sort(maja_ojca.begin(), maja_ojca.end());
}

void usun(int val)
{
	vector<int> nowy;
	for (int p : maja_ojca)
		if (p != val)
			nowy.push_back(p);
	maja_ojca = nowy;
}

int kty(int val)
{
	return maja_ojca[val-1];
}

void pokaz()
{
	for (int p : maja_ojca)
		cout << p << " ";
	cout << "\n";
}

void dfs(int v, int p)
{	
	for (auto u : G[v])
		if (u != p)
		{
			dodaj(u);
			ojciec[u] = v;
			dfs(u, v);
		}
	
	for (auto u : G[v])
		if (u != p)
			rozmiar_poddrzewa[v] += rozmiar_poddrzewa[u];
	
	rozmiar_poddrzewa[v]++;
}

void odejmij_poddrzewo(int v)
{
	int kto = v;
	while (v != 1 || usunieta[{min(v, ojciec[v]), max(v, ojciec[v])}])
	{
		rozmiar_poddrzewa[ojciec[v]] -= rozmiar_poddrzewa[kto];
		v = ojciec[v];
	}
}

int l(int i)
{
	return ((ans[i] + g[i]) % (n - i - 1)) + 1;
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
	
	dfs(1, 1);
	/*for (int i=1; i<=n; i++)
		deb(i, rozmiar_poddrzewa[i]);
	for (int i=1; i<=n; i++)
		deb(i, ojciec[i]);
	*/
	
	for (int i=1; i<=n-2; i++)
	{
		ans[i] = rozmiar_poddrzewa[x[i]];
		usun(x[i]);
		odejmij_poddrzewo(x[i]);
		usunieta[{min(x[i], ojciec[x[i]]), max(x[i], ojciec[x[i]])}] = 1;

		x[i+1] = kty(l(i));
		/*deb(x[i], ans[i], l(i), x[i+1]);
		for (int j=1; j<=n; j++)
			cout << j << " " << rozmiar_poddrzewa[j] << "\n";
		*/
	}
	
	ans[n-1] = rozmiar_poddrzewa[kty(1)];

	for (int i=1; i<=n-1; i++)
		cout << ans[i] << "\n";

    return 0;
}
