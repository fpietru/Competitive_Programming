#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int k; cin >> k;
		if (__builtin_popcount(2*(k-1)) % 2 == 0)
			cout << 2*(k-1) << "\n";
		else cout << 2*(k-1)+1 << "\n";
	}

    return 0;
}
