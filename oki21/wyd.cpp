/*
	Zadanie "Wydarzenie" z VIII OIG
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int parent;
	int size;
};

const int MxN = 1e6+6;
node arr[MxN];

void init(int v)
{
	arr[v].parent = v;
	arr[v].size = 1;
}

int find(int v)
{
	if (arr[v].parent == v)
		return v;
	return arr[v].parent = find(arr[v].parent);
}

void connect(int a, int b)
{
	a = find(a);
	b = find(b);

	if (arr[a].size < arr[b].size)
		swap(a, b);

	arr[b].parent = a;
	arr[a].size += arr[b].size;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n;

	for (int i=1; i<=n; i++)
		init(i);

	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		if (x != 0)
			connect(i, x);
	}

	cin >> m;
	set<int> st;
	for (int i=1; i<=m; i++)
	{
		int x; cin >> x;
		st.insert(find(x));
	}

	cout << st.size() << "\n";

	return 0;
}
