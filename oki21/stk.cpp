/*
	Zadanie "Stonks" z OKI
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MxN = 2e5+5;
ll arr[MxN], ans[MxN];

struct node
{
	ll pref;
	ll suff;
	ll tsum;
	ll msub;
};

class Tree
{
private:
	node *tree;
	int leafsize;
public:
	Tree(int base)
	{
		leafsize = 1 << base;
		tree = new node[2*leafsize];
		for (int i=0; i<2*leafsize; i++)
			tree[i] = {0,0,0,0};
	}
	~Tree() { delete[] tree; }

	node merge(node A, node B)
	{
		node C;
		C.pref = max(A.pref, A.tsum + B.pref);
		C.suff = max(B.suff, B.tsum + A.suff);
		C.tsum = A.tsum + B.tsum;
		C.msub = max({A.msub, B.msub, A.suff + B.pref});
		return C;
	}

/*	void show()
	{
		for (int i=1; i<2*leafsize; i++)
		{
			if ((i&(i-1)) == 0) cout << "\n";
			cout << tree[i].msub << " ";
		}
		cout << "\n\n";
	}*/

	void build(int v, int tl, int tr)
	{
		if (tl == tr)
			tree[v] = {arr[tl], arr[tl], arr[tl], arr[tl]};
		else
		{
			int m = (tl + tr) >> 1;
			build(2*v, tl, m);
			build(2*v+1, m+1, tr);
			tree[v] = merge(tree[2*v], tree[2*v+1]);
		}
	}

	ll get() { return max(tree[1].msub, (ll)0); }

	void upd(int v, int tl, int tr, int p, int val)
	{
		if (tl == tr)
			tree[v] = {val, val, val, val};
		else
		{
			int m = (tl + tr) >> 1;
			if (p <= m)
				upd(2*v, tl, m, p, val);
			else
				upd(2*v+1, m+1, tr, p, val);
			tree[v] = merge(tree[2*v], tree[2*v+1]);
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; ll x, a, b;
	cin >> n >> q >> x;
	for (int i=0; i<n; i++)
		cin >> arr[i], arr[i] -= x;

	Tree drzewo(18);
	drzewo.build(1, 0, n-1);

	ans[0] = drzewo.get();
	for (int i=1; i<=q; i++)
	{
		cin >> a >> b;
		drzewo.upd(1, 0, n-1, a-1, b-x);
		ans[i] = drzewo.get();
	}

	for (int i=0; i<=q; i++)
		cout << ans[i] << " ";
	cout << "\n";
	
	return 0;
}