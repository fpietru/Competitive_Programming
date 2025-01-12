#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+66;
struct node { int p, s; };
node nodes[MxN];

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
	a = getL(a), b = getL(b);
	if (nodes[a].s < nodes[b].s)
		swap(a, b);
	nodes[a].s += nodes[b].s;
	nodes[b].p = a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string a, b;
	cin >> a >> b;

	for (int i=0; i<26; i++)
		init(i);

	int ans = 0;
	for (int i=0; i<a.size(); i++)
		if (a[i] != b[i])
		{
			int La = getL(a[i]-'a');
			int Lb = getL(b[i]-'a');
			if (La != Lb)
			{
				ans++;
				join(La, Lb);
			}
		}
	
	cout << ans << "\n";

	return 0;
}