/*
	Zadanie "Przedział-Punkt" z OKI
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = 1 << 17, mod = 1e9+7;

class Tree
{
private:
	ll *tree;
	int s;
public:
	Tree(int base)
	{
		s = 1 << base;
		tree = new ll[2*s];
		for (int i=0; i<2*s; i++)
			tree[i] = 1;
	}
	~Tree()
	{ delete[] tree; }

	void update(int v, int tl, int tr, int l, int r, ll val)
	{
		if (l > r)
			return;
		if (tr == r && l == tl)
			tree[v] = (tree[v] * val) % mod;
		else
		{
			int m = (tl + tr) >> 1;
			update(2*v, tl, m, l, min(r, m), val);
			update(2*v+1, m+1, tr, max(l, m+1), r, val);
		}
	}

	int get(int v, int tl, int tr, int p)
	{
		if (tl == tr)
			return tree[v];

		int m = (tl + tr) >> 1;
		if (p <= m) return (tree[v] * get(2*v, tl, m, p)) % mod;
		else return (tree[v] * get(2*v+1, m+1, tr, p)) % mod;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Tree drzewko(17);

	int q; cin >> q;
	while (q--)
	{
		int t; cin >> t;
		if (!t)
		{
			int a, b, c; cin >> a >> b >> c;
			drzewko.update(1, 0, MxN-1, a, b, c);
		}
		else
		{
			int a; cin >> a;
			cout << drzewko.get(1, 0, MxN-1, a) << "\n";
		}
	} 
	
	return 0;
}