#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 5e5+15;
constexpr int MxW = 5e6+16;
int wart[MxN], p[MxN];
map<int, set<int>> wskazuje;
int deg[MxW];
set<int> wartosci;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	// double mem = (sizeof(wart)+sizeof(p)+sizeof(wskazuje)+sizeof(deg)+sizeof(wartosci)) / (double)(1<<20);
	// deb(mem);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> p[i];
	for (int i=1; i<=n; i++)
	{
		cin >> wart[i];
		wartosci.insert(wart[i]);
	}
		
	for (int i=1; i<=n; i++)
		if (p[i] != -1)
			if (wskazuje[wart[i]].find(wart[p[i]]) == wskazuje[wart[i]].end())
			{
				wskazuje[wart[i]].insert(wart[p[i]]);
				deg[wart[p[i]]]++;
			}

	vector<int> ans;
	priority_queue<int, vector<int>, greater<int>> Q;
	
	for (auto v : wartosci)
		if (deg[v] == 0)
			Q.push(v);
	
	while (!Q.empty())
	{
		int v = Q.top();
		Q.pop();
		ans.push_back(v);
		for (auto u : wskazuje[v])
		{
			deg[u]--;
			if (deg[u] == 0)
				Q.push(u);
		}
	}

	if ((int)ans.size() != (int)wartosci.size())
		cout << "NIE\n";
	else
	{
		cout << "TAK\n";
		for (auto v : ans)
			cout << v << " ";
		cout << "\n";
	}

    return 0;
}
