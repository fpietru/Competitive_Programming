#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 6e4+44;
int a[MxN], s[MxN];
int inversions = 0;

void mergeit(int st, int md, int ed);

void mergesort(int st, int ed)
{
	if (st < ed)
	{
		int md = (st + ed) >> 1;
		mergesort(st, md);
		mergesort(md+1, ed);
		mergeit(st, md, ed);
	}
}

void mergeit(int st, int md, int ed)
{
	int i = st;
	int j = md+1;
	int k = st;

	while (i <= md && j <= ed)
	{
		if (a[i] <= a[j])
			s[k++] = a[i++];
		else
		{
			s[k++] = a[j++];
			inversions += md - i + 1;
		}
	}

	while (i <= md)
		s[k++] = a[i++];
	while (j <= ed)
		s[k++] = a[j++];

	for (int i=st; i<=ed; i++)
		a[i] = s[i];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	mergesort(0, n-1);
	cout << inversions << "\n";

	return 0;
}