#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int rand(int a, int b)
{
	return a + rand() % (b-a+1);
}

constexpr int MxN = 1000;
vector<pii> edges;
struct node
{
	int p;
	int s;
};
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

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = rand(2, 10);
	cout << n << "\n";
	
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (i != j)
				edges.push_back({i, j});
	
	for (int i=1; i<=n; i++)
		init(i);	
	
	random_shuffle(edges.begin(), edges.end());
	
	vector<pii> ans;
	for (auto e : edges)
	{
		int a = e.first;
		int b = e.second;
		
		if (getL(a) != getL(b))
		{
			join(a, b);
			ans.push_back(e);
		}
	}
	
	for (auto e : ans)
	{
		cout << e.first << " " << e.second << " " << (char)('A' + rand(0, 1)) << "\n";
	}
	
	return 0;
}
