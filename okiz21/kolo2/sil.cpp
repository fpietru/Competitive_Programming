#include <bits/stdc++.h>
using namespace std;

int silnia(int x)
{
	if (x == 0)
		return 1;
	return x * silnia(x-1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	cout << silnia(n) << "\n";
	
	return 0;
}