#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n = 2000;
	cout << n << "\n";
	
	for (int i=1; i<n; i++)
		cout << i << " " << i+1 << " " << (char)('A' + ((i-1) % 26)) << "\n";
	
	return 0;
}
