#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+66;
bool used[MxN];
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	sort(a, a+n);

	int ans = 0;
	for (int i=0; i<n-1; i++)
		if (a[i+1] - a[i] <= k && !used[i+1] && !used[i])
		{
			ans += 2;
			used[i] = 1;
			used[i+1] = 1;
		}

	cout << ans << "\n";
	
	return 0;
}