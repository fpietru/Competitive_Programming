#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+6;
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, ans=1; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	bool d = 0;
	for (int i=0; i<n-1; i++)
	{
		if (d == 0 && a[i] > a[i+1])
			ans++, d = 1;
		else if (d == 1 && a[i] < a[i+1])
			ans++, d = 0;
	}

	cout << ans << "\n";

	return 0;
}