/*
	Drzewo Fenwick'a (+, sum)
	Sprawdzenie Poprawności: https://cses.fi/problemset/task/1648/
	(zawsze indeksowane od 1)

	Operacje:
	1: Zmień wartość elementu na danym indeksie
	2: Zwróć sumę elementów na prefiksie
*/
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

constexpr int MxN = 2e5+5;
ll Tree[MxN];

void upd(int v, int x)
{
	while (v < MxN)
	{
		Tree[v] += (ll)x;
		v += (v&-v);
	}
}

ll sum(int v)
{
	ll res = 0LL;
	while (v)
	{
		res += Tree[v];
		v -= (v&-v);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, q; cin >> n >> q;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		upd(i, x);
	}
	
	while (q--)
	{
		int op, a, b; cin >> op >> a >> b;
		if (op == 1)
		{
			ll val = sum(a) - sum(a-1);
			upd(a, b - val);
		}
		else cout << sum(b) - sum(a-1) << "\n";
	}

    return 0;
}
