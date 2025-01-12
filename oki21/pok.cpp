/*
	Zadanie "Pokémon Army (easy version)" z CF#672(DIV.2)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, q; cin >> n >> q;
	vector<int> arr(n);
	vector<ll> a1(n+1), a2(n+1);
	for (int i=0; i<n; i++)
		cin >> arr[i];
	a1[0] = -1e9;
	a2[0] = 0;
	for (int i=0; i<n; i++)
	{
		a1[i+1] = max(a1[i], a2[i]+arr[i]);
		a2[i+1] = max(a2[i], a1[i]-arr[i]);
	}
	cout << max(a1.back(), a2.back()) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
		solve();
	
	return 0;
}