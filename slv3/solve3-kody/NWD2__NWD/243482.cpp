#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n; cin >> n;
	if (n <= 2)
		cout << "NIE\n";
	else
		cout << 1 << " " << n-2 << " " << n-2 << "\n";	

    return 0;
}
