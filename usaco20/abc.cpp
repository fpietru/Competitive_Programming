/*
	USACO 2020 December Contest, Bronze
	Problem 1. Do You Know Your ABCs?
	Author: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;

long arr[7], ans[3];

bool find(int x)
{
	for (int i=0; i<7; i++)
		if (arr[i] == x)
			return 1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i=0; i<7; i++)
		cin >> arr[i];

	for (int a=0; a<5; a++)
	{
		for (int b=a+1; b<6; b++)
		{
			for (int c=b+1; c<7; c++)
			{
				long A = arr[a];
				long B = arr[b];
				long C = arr[c];

				if (find(A+B) && find(B+C) && find(C+A) && find(A+B+C))
					ans[0] = A, ans[1] = B, ans[2] = C;
			}
		}
	}

	sort(ans, ans+3);

	cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";

	
	return 0;
}