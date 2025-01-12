/*
	Zadanie "Przekaźniki telekomunikacyjne" z XXV OI, etap II
	Drzewo Przedział-Przedział:
	1) dodaj ciąg arytmetyczny na przedziale
	2) podaj sumę elementów na przedziale
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int base = (1<<19);
constexpr int MxN = 3e5+15;
ll Tree[2*base+10];
struct lazyinfo { ll a1, r; };
lazyinfo Lazy[2*base+10];
pii jakimaszt[MxN];

ll ity(ll a1, ll r, int i) {
	return a1 + r*(i-1);
}

ll suma(ll a1, ll r, int n) {
	return (2*a1*(ll)n + r*(ll)n*(ll)n - r*(ll)n) / 2;
}

void dodaj(int v, ll a1, ll r, int poz, int st, int ed)
{
	Tree[v] += suma(ity(a1, r, st-poz+1), r, ed-st+1);
	Lazy[v].a1 += ity(a1, r, st-poz+1);
	Lazy[v].r += r;
}

void lazypush(int v, int lw, int rw)
{
	int mid = (lw + rw) / 2;
	dodaj(2*v, Lazy[v].a1, Lazy[v].r, lw, lw, mid);
	dodaj(2*v+1, Lazy[v].a1, Lazy[v].r, lw, mid+1, rw);
	Lazy[v] = {0LL,0LL};
}

void insert(int v, int lw, int rw, int L, int R, ll a1, ll r)
{
	if (rw < L || R < lw)
		return;
	else if (L <= lw && rw <= R)
		dodaj(v, a1, r, L, lw, rw);
	else
	{
		lazypush(v, lw, rw);
		int mid = (lw + rw) / 2;
		insert(2*v, lw, mid, L, R, a1, r);
		insert(2*v+1, mid+1, rw, L, R, a1, r);
		
		Tree[v] = Tree[2*v] + Tree[2*v+1];
	}
}

ll query(int v, int lw, int rw, int L, int R)
{
	if (rw < L || R < lw)
		return 0LL;
	else if (L <= lw && rw <= R)
		return Tree[v];
	else
	{
		lazypush(v, lw, rw);
		int mid = (lw + rw) / 2;
		ll Lson = query(2*v, lw, mid, L, R);
		ll Rson = query(2*v+1, mid+1, rw, L, R);
		return Lson + Rson;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, q; cin >> n >> q;
	while (q--)
	{
		char op; cin >> op;
		if (op == 'P')
		{
			int x, s, a; cin >> x >> s >> a;
			jakimaszt[x] = {s, a};
			
			insert(1, 0, base-1, x, x+s/a, s, -a);
			insert(1, 0, base-1, x-(s/a), x-1, s%a, a);
		}
		else if (op == 'U')
		{
			int x; cin >> x;
			int s = jakimaszt[x].FR;
			int a = jakimaszt[x].SD;
			insert(1, 0, base-1, x, x+s/a, -s, a);
			insert(1, 0, base-1, x-(s/a), x-1, -(s%a), -a);
		}
		else if (op == 'Z')
		{
			int a, b; cin >> a >> b;
			cout << query(1, 0, base-1, a, b) / (b-a+1) << "\n";
		}
	}
	
	return 0;
}
