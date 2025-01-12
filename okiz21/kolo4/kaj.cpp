/*
	Zadanie "Kajak" z IV OI, etap III
	Za łatwe jak na OI'a
*/
#include <bits/stdc++.h>
using namespace std;
constexpr int MxN = 3e4+44;
int a[MxN];
bool used[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int w, n; cin >> w >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	sort(a, a+n);

	int ans = 0;
	for (int i=0, j=n-1; i<n; i++, j--)
	{
		if (j < i)
			break;

		while (a[i] + a[j] > w && i < j)
		{
			if (a[j] <= w) ans++;
			j--;
		}

		if ((i != j && a[i] + a[j] <= w) || (i == j && a[i] <= w)) ans++;
	}

	cout << ans << '\n';

	return 0;
}