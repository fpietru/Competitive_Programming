/*
	Znajdowanie Najdłuższego Rosnącego Podciągu
	w czasie O(n^2) z użyciem dp
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e3+13;
int a[MxN], dp[MxN], p[MxN];

/*
	a[i] = element na i-tej pozycji w ciągu
	dp[i] = maksymalna długość LIS, która końcy się w i-tym elemencie
	p[i] = poprzednik w odpowiedzi i-tego elementu. Jeśli p[i] = -1 => i-ty element nie ma poprzednika
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// wczytywanie
	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	// początkowo dp[x] = 1, a p[x] = -1
	for (int i=1; i<=n; i++)
	{
		dp[i] = 1;
		p[i] = -1;
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<i; j++)
			if (a[j] < a[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
				p[i] = j;
			}


	// mx_dp może być po prostu odpowiedzią, kiedy chcemy wyznaczyć tylko długość LIS
	int mx_dp = 0, pos = -1;
	for (int i=1; i<=n; i++)
		if (dp[i] > mx_dp)
		{
			mx_dp = dp[i];
			pos = i;
		}

	// backtracking jednego z możliwych maksymalnych podciągów
	vector<int> subseq;
	while (pos != -1)
	{
		subseq.push_back(a[pos]);
		pos = p[pos];
	}
	reverse(subseq.begin(), subseq.end());

	// wypisanie odpowiedzi
	cout << mx_dp << "\n";
	for (auto p : subseq)
		cout << p << " ";
	cout << "\n";

	return 0;
}