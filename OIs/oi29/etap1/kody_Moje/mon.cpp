/*
	Zadanie "Montażysta" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 5e5+55;
pii order[MxN];
int p[MxN], d[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> p[i] >> d[i];
		order[i] = {d[i], i};
	}

	sort(order, order+n);

	ll C = 1;
	priority_queue<pair<int,pii>> qu;
	
	for (int i=0; i<n; i++)
	{
		int id = order[i].SD;
		int czas = p[id];
		int deadl = d[id];

		qu.push({czas, {id, (int)C}});
		C += (ll)czas;

		if (C > (ll)(deadl + 1))
		{
			C -= (ll)qu.top().FR;
			qu.pop();
		}
	}

	cout << qu.size() << "\n";
	while (!qu.empty())
	{
		pii ans = qu.top().SD; qu.pop();
		cout << ans.FR + 1 << " " << ans.SD << "\n";
	}

	return 0;
}
