#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second
#define ll long long
#define dd long double

constexpr int MxN = 1e3+33;
struct node { int p; ll s; };
pair<ll, ll> P[MxN];
node nodes[MxN];

dd distance(pair<ll, ll> A, pair<ll, ll> B) {
	return sqrt((dd)(B.FR-A.FR)*(B.FR-A.FR) + (B.SD-A.SD)*(B.SD-A.SD)); 
}

void init(int v)
{
	nodes[v].p = v;
	nodes[v].s = 1LL;
}

int getLeader(int v)
{
	if (nodes[v].p == v)
		return v;
	return nodes[v].p = getLeader(nodes[v].p);
}

void join(int a, int b)
{
	a = getLeader(a);
	b = getLeader(b);
	if (nodes[a].s < nodes[b].s)
		swap(a, b);
	nodes[a].s += nodes[b].s;
	nodes[b].p = a;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, st; cin >> n >> st;
	ll d; cin >> d;
	for (int i=1; i<=n; i++)
	{
		cin >> P[i].FR >> P[i].SD;
		init(i);
	}

	for (int i=1; i<=n-1; i++)
		for (int j=i+1; j<=n; j++)
			if (distance(P[i], P[j]) <= (dd)d)
				join(i, j);

	dd mxdist = 0.0;
	for (int i=1; i<=n; i++)
		if (mxdist <= distance(P[i], P[st]) && getLeader(i) == getLeader(st))
			mxdist = distance(P[i], P[st]);

	cout << fixed << setprecision(3) << mxdist + (dd)d << "\n";

	return 0;
}