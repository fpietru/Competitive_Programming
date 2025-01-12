#include <bits/stdc++.h>
using namespace std;

const int MxN = 1e6+66;
int a[MxN], s[MxN];

void merge(int st, int md, int ed);

void mergesort(int st, int ed)
{
	if (st < ed)
	{
		int md = (st + ed) >> 1;
		mergesort(st, md);
		mergesort(md+1, ed);
		merge(st, md, ed);
	}
}

void merge(int st, int md, int ed)
{
	int i = st;
	int j = md + 1;
	int k = st;

	while (i <= md && j <= ed)
	{
		if (a[i] <= a[j])
		{
			s[k] = a[i];
			i++;
			k++;
		}
		else
		{
			s[k] = a[j];
			j++;
			k++;
		}
	}

	while (i <= md)
	{
		s[k] = a[i];
		i++;
		k++;
	}
	while (j <= ed)
	{
		s[k] = a[j];
		j++;
		k++;
	}

	for (int x=st; x<=ed; x++)
		a[x] = s[x];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	mergesort(0, n-1);

	for (int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << "\n";
	
	return 0;
}