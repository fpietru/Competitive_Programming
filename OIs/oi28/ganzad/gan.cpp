/*
Zadanie Gang Biciakow XXVIII OI, etap I  
Autor: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct element
{
	ll a;
	ll b;
	ll c;
};

const ll MxN = 1e5+7, MxMZ = 15e4;
vector<ll> G[MxN];
element toys[MxN];
ll n, m, z;
/*
void DEB_show_G()
{
	for (ll i=1; i<=n; i++)
	{
		cout << i << ": ";
		for (auto j : G[i])
			cout << j << " ";
		cout << "\n";
	}
}

void DEB_show_toys()
{
	for (ll i=1; i<n; i++)
		cout << toys[i].a << " " << toys[i].b << " " << toys[i].c << "\n";
}
*/

void BFS(ll st, ll dest, vector<ll> &prevvert)
{
	queue<ll> qu;
	vector<bool> vistited(n+1, 0);

	qu.push(st);
	vistited[st] = 1;

	while (!qu.empty())
	{
		ll v = qu.front();
		qu.pop();

		for (auto w : G[v])
		{
			if (!vistited[w])
			{
				vistited[w] = 1;
				qu.push(w);
				prevvert[w] = v;
			}
			
			if (w == dest)
				return;
		}
	}
}

void PATHandANSWER(ll st, ll dest)
{
	vector<ll> prevvert(n+1, -1);

	BFS(st, dest, prevvert);

	ll d = dest;
	vector<ll> path;
	path.push_back(d);
	while (prevvert[d] != -1)
	{ 
		path.push_back(prevvert[d]);
		d = prevvert[d];
	}

	set<ll> ans;
	for (ll i=0; i<path.size()-1; i++)
	{
		for (ll j=1; j<n; j++)
		{
			if ((path[i] == toys[j].a && path[i+1] == toys[j].b) || (path[i+1] == toys[j].a && path[i] == toys[j].b))
				ans.insert(toys[j].c);
		}
	}

	cout << ans.size() << "\n";

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// Wczytywanie
	cin >> n >> m >> z;
	for (ll i=1; i<=n-1; i++)
	{
		ll a, b, c; cin >> a >> b >> c;
		G[a].push_back(b);
		G[b].push_back(a);
		toys[i] = {a,b,c};
	}
	while (z--)
	{
		char op; cin >> op;
		if (op == 'Z')
		{
			ll dest; cin >> dest;
			PATHandANSWER(1, dest);
		}
		else
		{
			ll i, nc; cin >> i >> nc;
			toys[i].c = nc;
		}
	}
	
	return 0;
}