#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n; cin >> n;
	vector<int> a(n), v1, v2;
	for (int &p : a)
		cin >> p;

	v1.push_back(a[0]);
	for (int i=1; i<n; i++)
	{
		if (a[i] < v1.back())
			v1.push_back(a[i]);
		else v2.push_back(a[i]);
	}
	reverse(v1.begin(), v1.end());
	for (int p : v1)
		cout << p << " ";
	for (int p : v2)
		cout << p << " ";
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