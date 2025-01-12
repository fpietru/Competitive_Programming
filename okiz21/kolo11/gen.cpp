#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n = 500000;
	int k = 500000;
	int m = n-1;
	cout << n << " " << m << " " << k << "\n";
	for (int i=1; i<=k; i++)
		cout << i << " ";
	cout << "\n";
	int a = 1, b;
	for (int i=1; i<=m; i++)
	{
		b = a + 1;
		cout << a << " " << b << " " << 1000000000 << "\n";
		a = b;
	}
	
	return 0;
}