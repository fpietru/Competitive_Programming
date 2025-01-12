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

constexpr int MxN = 1e6+16;
vector<int> G[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	G[1].push_back(2);
	G[2].push_back(1);

	int licznik = 3;
	int q; cin >> q;
	while (q--)
	{
		char op; cin >> op;
		if (op == 'W')
		{
			int x; cin >> x;
			G[licznik].push_back(x);
			G[x].push_back(licznik);
			licznik++;
		}
		else if (op == 'Z')
		{
			int x; cin >> x;
			for (auto u : G[x])
			{
				G[licznik].push_back(u);
				G[u].push_back(licznik);
			}
			licznik++;
		}
		else
		{
			int x; cin >> x;
			cout << G[x].size() << "\n";
		}
		
		/*
		for (int i=1; i<=licznik; i++)
		{
			cout << i << ": ";
			for (auto u : G[i])
				cout << u << " ";
			cout << "\n";
		}*/
	}

    return 0;
}
