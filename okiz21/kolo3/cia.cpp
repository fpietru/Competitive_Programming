#include <bits/stdc++.h>
using namespace std;

const int MxN = 5e4+4;
int pref[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		pref[i+1] = pref[i] + x;
	}

	for (int i=1; i<=n; i++)
		cout << pref[i] << " ";
	cout << "\n";
	
	return 0;
}