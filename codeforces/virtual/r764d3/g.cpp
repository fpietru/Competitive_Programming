#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

constexpr int MxN = 2e5+5;
struct edge { int a, b, w; };
struct node { int p, s; };
edge edges[MxN];
node nodes[MxN];
int n, m;

void init(int v)
{
	nodes[v].p = v;
	nodes[v].s = 1;
}

int getL(int v)
{
	if (nodes[v].p == v)
		return v;
	return nodes[v].p = getL(nodes[v].p);
}

void join(int a, int b)
{
	a = getL(a);
	b = getL(b);
	if (a != b)
	{
		if (nodes[a].s < nodes[b].s)
			swap(a, b);
		nodes[a].s += nodes[b].s;
		nodes[b].p = a;
	}
}

bool isconnected(int x)
{
	for (int i=1; i<=n; i++)
		init(i);

	for (int i=1; i<=m; i++)
	{
		/*
			krawędź o wadze w nie jest ORsubmaską obecnej odpowiedzi
			np.
				odpowiedź = 11011001
				        w = 01101011
				       OR =	11111011
				
				OR != odpowiedź => w nie jest ORsubmaską odpowiedzi 	
		*/
		if ((edges[i].w | x) != x)
			continue;
		
		join(edges[i].a, edges[i].b);
	}
	
	for (int i=1; i<=n-1; i++)
		if (getL(i) != getL(i+1))
			return 0;
	
	return 1;
}

void solve()
{
	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b, w; cin >> a >> b >> w;
		edges[i] = {a, b, w};
	}
	
	/*
		zaczynamy z największą możliwą odpowiedzią 11111...111
		i będziemy się starali ją zmniejszać sprawdzając czy zmniejszona
		odpowiedź nadal jest poprawna.
		
		Zmniejszanie polega na wyłączaniu bitu na 2^i pozycji
	*/
	int ans = (1<<30)-1;
	for (int i=29; i>=0; i--)
	{
		/*
			(zmniejszony_ans) = ans z wyjączonym bitem na 2^i pozycji
			
			Sprawdzamy, czy graf mający tylko krawędzie,
			które są ORsubmaskami (zmniejszony_ans), będzie spójny.
			Jeśli będzie spójny tzn. że (zmniejszony_ans) jest poprawny
			i faktycznie możemy zmniejszyć naszą odpowiedź
		*/
	
		if (isconnected(ans^(1<<i)))
			ans ^= (1<<i);
	}
			
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--)
		solve();
	
	return 0;
}
