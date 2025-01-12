#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MxN = 1e5+5;
int a[MxN], b[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	
	ll tot = 0;
	for (int i=0; i<n; i++)
		tot += (ll)(a[i]*b[i]);

	cout << (tot == 0 ? "Yes\n" : "No\n");

	return 0;
}