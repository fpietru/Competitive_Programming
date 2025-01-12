#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 3e6+66;
int t[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, a, b; cin >> n;
	cin >> b;
	for (int i=1; i<n; i++)
	{
		cin >> a;
		t[i] = b - a;
		b = a;
	}
	
	// Kadane's algorithm
	int bestsum = -1e9-9, currsum = 0;
	for (int i=0; i<n; i++)
	{
		currsum = max(0, currsum+t[i]);
		bestsum = max(bestsum, currsum);
	}

	cout << bestsum << "\n";

	return 0;
}