/*
	USACO 2020 December Contest, Bronze
	Problem 2. Daisy Chains
	Author: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e2+1;
int arr[MxN];
int n, sum=0, sr, ans=0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> arr[i];

	for (int i=0; i<n; i++)
		for (int j=i; j<n; j++)
		{
			sum = 0;
			for (int k=i; k<=j; k++)
				sum += arr[k];

			if (sum % (j-i+1) == 0)
			{
				sr = sum / (j-i+1);

				for (int k=i; k<=j; k++)
					if (arr[k] == sr)
					{
						ans++;
						break;
					}
			}
		}
	
	cout << ans << "\n";

	return 0;
}