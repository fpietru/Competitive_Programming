#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e2+22;
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	
	int mx = a[0];
	for (int i=1; i<n; i++)
	{
		if (mx > a[i])
		{
			cout << "NIE\n";
			return 0;
		}
		mx = a[i];
	}

	cout << "TAK\n";

	return 0;
}