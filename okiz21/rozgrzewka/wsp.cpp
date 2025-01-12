#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+6;
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	sort(a, a+n, greater<int>());
	for (int i=0; i<10; i++)
		cout << a[i] << " ";
	cout << "\n";

	return 0;
}