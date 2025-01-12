/*
	Zadanie "Kolonie" z KI
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int parent;
	int mass;
	int minIQ;
	int maxIQ;
};

const int MxN = 1e6+6;
node arr[MxN];

void init(int x, int m, int i)
{
	arr[x] = {x, m, i, i};
}

int find(int x)
{
	if (arr[x].parent == x)
		return x;
	return arr[x].parent = find(arr[x].parent);
}

void connect(int a, int b)
{
	a = find(a);
	b = find(b);

	if (a != b)
	{
		if (arr[a].mass < arr[b].mass)
			swap(a, b);

		arr[b].parent = a;
		arr[a].mass += arr[b].mass;
		arr[a].minIQ = min(arr[a].minIQ, arr[b].minIQ);
		arr[a].maxIQ = max(arr[a].maxIQ, arr[b].maxIQ);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		int m, iq; cin >> m >> iq;
		init(i, m, iq);
	}

	string s;
	while (cin >> s)
	{
		if (s == "JOIN")
		{
			int a, b; cin >> a >> b;
			connect(a, b);
		}
		else if (s == "IQ_MIN")
		{
			int x; cin >> x;
			cout << arr[find(x)].minIQ << "\n";
		}
		else if (s == "IQ_MAX")
		{
			int x; cin >> x;
			cout << arr[find(x)].maxIQ << "\n";
		}
		else
		{
			int x; cin >> x;
			cout << arr[find(x)].mass << "\n";
		}
	}

	return 0;
}