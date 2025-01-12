/*
	Zadanie "Trójkąty jednobarwne" z IV OI, etap III
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e3+33;
int R[MxN]; // R[i] = liczba czerwonych krawędzi dla wierzchołka i

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		R[a]++, R[b]++;
	}

	ll sum = 0;
	for (int i=1; i<=n; i++)
		sum += (ll)R[i] * (ll)(n-1 - R[i]);

	ll newton = n*(n-1)*(n-2) / 6;

	cout << newton - sum / 2 << "\n";

	return 0;
}