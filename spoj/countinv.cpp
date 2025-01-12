#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MxN = 1e3+33;
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	while (cin >> n)
		if (n != 0)
		{
			for (int i=0; i<n; i++)
				cin >> a[i];

			ll inv = 0;
			for (int i=0; i<n-1; i++)
				for (int j=i+1; j<n; j++)
					if (a[i] > a[j]) inv++;

			cout << inv << "\n";
		}

	return 0;
}