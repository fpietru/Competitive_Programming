#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MxN = 1e6+6;
int t[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		if (x > n) // kosztowało mnie pare dobrych minut :((
		{
			cout << "NIE\n";
			return 0;
		}
		t[x]++;
	}

	for (int i=1; i<=n; i++)
		if (t[i] != 1)
		{
			cout << "NIE\n";
			return 0;
		}

	cout << "TAK\n";
	
	return 0;
}