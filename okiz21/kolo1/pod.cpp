#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b, k;
	cin >> a >> b >> k;

	cout << (b/k) - (a/k) + bool(a%k == 0) << "\n";

	return 0;
}