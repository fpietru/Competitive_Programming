#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		
		if (x % 4 == 0 && ((x % 400 == 0) || (x % 100 != 0)))
			cout << "TAK\n";
		else cout << "NIE\n";
	}

    return 0;
}
