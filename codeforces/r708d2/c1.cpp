#include <bits/stdc++.h>
using namespace std;

vector<int> solve()
{
	int n, k; cin >> n >> k;
	
	if (n&1)
		return {n/2, n/2, 1};
	if (n % 4 == 0)
		return {n/4, n/4, n/2};
	else
		return {(n-2)/2, (n-2)/2, 2};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--)
	{
		for (auto a : solve())
			cout << a << " ";
		cout << "\n";
	}

	return 0;
}