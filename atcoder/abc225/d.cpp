#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

struct node
{
	int przed;
	int po;
};
constexpr int MxN = 1e5+5;
node nodes[MxN];

void init(int v)
{
	nodes[v] = {-1, -1};
}

void connect(int a, int b)
{
	nodes[a].po = b;
	nodes[b].przed = a;
}

void disconnect(int a, int b)
{
	nodes[a].po = -1;
	nodes[b].przed = -1;
}

void wypisz(int x)
{
	vector<int> wszystkie_przed;
	vector<int> wszystkie_po;
	int v = x;
	while (nodes[v].przed != -1)
	{
		wszystkie_przed.push_back(nodes[v].przed);
		v = nodes[v].przed;
	}
	v = x;
	while (nodes[v].po != -1)
	{
		wszystkie_po.push_back(nodes[v].po);
		v = nodes[v].po;
	}
	reverse(wszystkie_przed.begin(), wszystkie_przed.end());
	
	cout << wszystkie_przed.size() + wszystkie_po.size() + 1 << " ";
	for (int p : wszystkie_przed)
		cout << p << " ";
	cout << x << " ";
	for (int p : wszystkie_po)
		cout << p << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;
	
	for (int i=1; i<=n; i++)
		init(i);
	
	for (int i=1; i<=k; i++)
	{
		int a, b;
		int op; cin >> op;
		if (op == 1)
		{
			cin >> a >> b;
			connect(a, b);
		}
		else if (op == 2)
		{
			cin >> a >> b;
			disconnect(a, b);
		}
		else
		{
			cin >> a;
			wypisz(a);
		}
	}

    return 0;
}













