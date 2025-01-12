#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 2e5+15;
constexpr int base = (1<<20);
ll Tree[2*base+10], Lazy[2*base+10];
vector<int> G[MxN];
int pre[MxN], post[MxN];
int gtime = 0;

void lazypush(int v)
{
	Tree[2*v] += Lazy[v] / 2;
	Lazy[2*v] += Lazy[v] / 2;
	Tree[2*v+1] += Lazy[v] / 2;
	Lazy[2*v+1] += Lazy[v] / 2;
	Lazy[v] = 0;
}

void insert(int v, int lw, int rw, int L, int R, ll val)
{
	if (rw < L || R < lw)
		return;
	else if (L <= lw && rw <= R)
	{
		Tree[v] += val * (rw-lw+1);
		Lazy[v] += val * (rw-lw+1);
	}
	else
	{
		lazypush(v);
		int mid = (lw + rw) / 2;
		insert(2*v, lw, mid, L, R, val);
		insert(2*v+1, mid+1, rw, L, R, val);
		
		Tree[v] = Tree[2*v] + Tree[2*v+1];
	}
}

ll query(int v, int lw, int rw, int L, int R)
{
	if (rw < L || R < lw)
		return 0;
	else if (L <= lw && rw <= R)
		return Tree[v];
	else
	{
		lazypush(v);
		int mid = (lw + rw) / 2;
		ll Lson = query(2*v, lw, mid, L, R);
		ll Rson = query(2*v+1, mid+1, rw, L, R);
		return Lson + Rson;
	}
}

void dfs(int v, int p)
{
	pre[v] = ++gtime;
	for (auto u : G[v])
		if (u != p)
			dfs(u, v);
	post[v] = ++gtime;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		G[i].push_back(x);
		G[x].push_back(i);
	}
	
	dfs(0,0);
	
	int z; cin >> z;
	while (z--)
	{
		char op; cin >> op;
		if (op == 'D')
		{
			int a, b; cin >> a >> b;
			insert(1, 0, base-1, pre[a]+1, post[a]-1, (ll)b);
		}
		else
		{
			int a; cin >> a;
			ll sum = query(1, 0, base-1, pre[a]+1, post[a]-1);
			int range = post[a] - pre[a] - 1;
			
			if (range == 0)
				cout << "0\n";
			else
				cout << sum / (ll)range << "\n"; 
		}
	}
	
    return 0;
}
