/*
	Znajdowanie LIS'a
	z użyciem dp i binary search'a
	Czas: O(n*logn)
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+16, INF = 1e9+7;
int a[MxN], d[MxN], p[MxN], idx[MxN];

/*
	a[i] = wartość elementu na pozycji i (tak samo jak na wejściu)
	d[i] = wartość elementu, na którym kończy się podciąg o długości i
	p[i] = poprzednik elementu z pozycji i (p[i] = idx[low-1], gdzie d[low] = a[i]
	idx[i] = indeks z tablicy a elementu w tablicy d
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
		
	d[0] = -INF;
	for (int i=1; i<=n; i++)
		d[i] = INF;

	for (int i=1; i<=n; i++)
	{
		int low = 0;
		int high = n;
		
		while (low < high)
		{
			int mid = (low + high) / 2;
			if (d[mid] < a[i])
				low = mid + 1;
			else high = mid;
		}

		if (d[low-1] < a[i] && a[i] < d[low])
		{
			p[i] = idx[low-1];
			idx[low] = i;
			d[low] = a[i];	
		}
	}

	int L = n;
	while (d[L] == INF)
		L--;
	
	vector<int> ans;
	
	int k = idx[L];
	for (int i=L-1; i>=0; i--)
	{
		ans.push_back(a[k]);
		k = p[k];
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << L << "\n";
	for (auto p : ans)
		cout << p << " ";
	cout << "\n";
	
	return 0;
}
