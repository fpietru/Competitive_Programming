#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;

	for (int i=0; i<n-1; i++)
		cout << "9";
	cout << "8";
	for (int i=0; i<n-1; i++)
		cout << "0";
	cout << "1\n";

	return 0;
}