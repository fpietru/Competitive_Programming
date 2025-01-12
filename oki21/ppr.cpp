/*
	Zadanie "Punkt-Przedział" z OKI
*/
#include <bits/stdc++.h>
using namespace std;

const int base = 17;
int q, t, a, b;

struct MxTree
{
	int *tree, s;

	MxTree(int size)
	{
		s = 1 << size;
		tree = new int[2*s];
		for (int i=0; i<2*s; i++)
			tree[i] = 0;
	}
	~MxTree()
	{ delete[] tree; }

	void upd(int a, int b)
	{
		for (a += s, tree[a] = b, a >>= 1; a > 0; a >>= 1)
			tree[a] = max(tree[a<<1], tree[(a<<1)+1]);
	}

	int get(int a, int b)
	{
		int res = -1e9;
		a += s;
		b += s;

		while (a < b)
		{
			if ((a&1) == 1) res = max(res, tree[a++]);
			if ((b&1) == 0) res = max(res, tree[b--]);
			a >>= 1, b >>= 1;
		}
		if (a == b) res = max(res, tree[a]);
		return res;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	MxTree drzewko(17);

	cin >> q;
	for (int i=0; i<q; i++)
	{
		cin >> t >> a >> b;
		if (t) cout << drzewko.get(a, b) << "\n";
		else drzewko.upd(a, b);
	}

	return 0;
}