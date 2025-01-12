#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+66;
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	
	int i = 0, j = n-1;
	while (a[i] == a[j])
		i++;

	int ans1 = abs(i-j);

	i = 0, j = n-1;
	while (a[i] == a[j])
		j--;

	int ans2 = abs(i-j);

	cout << max(ans1, ans2) << "\n";

	return 0;
}