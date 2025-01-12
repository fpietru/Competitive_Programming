#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e2+22;
int arr[MxN];

void solve()
{
	int n, k; cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> arr[i];

	for (int i=0; i<n; i++)
	{
		while (k > 0 && arr[i] > 0)
		{
			arr[i]--, arr[n-1]++;
			k--;
		}
	}

	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
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