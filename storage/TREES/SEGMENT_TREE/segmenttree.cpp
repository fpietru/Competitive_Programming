#include <bits/stdc++.h>
using namespace std;

class Tree
{
private:
	int *tree, leafsize;
public:
	Tree(int base)
	{
		leafsize = 1 << base;
		tree = new int[2*leafsize];
		for (int i=0; i<2*leafsize; i++)
			tree[i] = 0;
	}

	~Tree()
	{ delete[] tree; }

	void show()
	{
		for (int i=1; i<2*leafsize; i++)
		{
			if ((i&(i-1)) == 0) cout << "\n";
			cout << tree[i] << " ";
		}
		cout << "\n";
	}

	void build(int arr[], int v, int tl, int tr)
	{
		if (tl == tr)
			tree[v] = arr[tl];
		else
		{
			int m = (tl + tr) >> 1;
			build(arr, 2*v, tl, m);
			build(arr, 2*v+1, m+1, tr);
			tree[v] = max(tree[2*v], tree[2*v+1]);
		}
	}

	void upd(int v, int val)
	{
		v += leafsize;
		tree[v] = val;
		v >>= 1;
		while (v > 0)
		{
			tree[v] = max(tree[2*v], tree[2*v+1]);
			v >>= 1;
		}
	}

	int getmax(int a, int b)
	{
		int res = -1e9;
		a += leafsize;
		b += leafsize;
		while (a < b)
		{
			if ((a&1) == 1) res = max(tree[a++], res);
			if ((b&1) == 0) res = max(tree[b--], res);
			a >>= 1, b >>= 1;
		}
		if (a == b) res = max(tree[a], res);
		return res;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int arr[8], n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];
	
	Tree drzewo(3);

	drzewo.build(arr, 1, 0, n-1);
	// drzewo.show();
	cout << drzewo.getmax(3, n-1) << "\n";

	return 0;
}