/*
	Zadanie "Rada Nadzorcza" z OKI
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 5e5+5;
int arr[MxN], pref[MxN];
int n, sum = 0;
bool ans = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	pref[0] = 0;
	for (int i=1; i<=n; i++)
		pref[i] = pref[i-1] + arr[i-1];

	for (int i=0; i<=n; i++)
		for (int j=i; j<=n; j++)
			if (pref[j] - pref[i] == sum - (pref[j] - pref[i]))
			{
				ans = 1;
				break;
			}

	cout << (ans || sum % 360 == 0  ? "TAK\n" : "NIE\n");

	return 0;
}
