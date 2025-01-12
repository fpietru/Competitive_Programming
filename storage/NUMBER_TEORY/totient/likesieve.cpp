#include <bits/stdc++.h>
using namespace std;

/*
	Znajdowanie Tocjentu Eulera dla liczb z przedziału [1,N], N=ok.10^6
	Zadanie Na sprawdzenie: https://www.spoj.com/problems/ETF/
*/

constexpr int MxN = 1e6;
int phi[MxN+10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	for (int i=0; i<=MxN; i++)
		phi[i] = i;
	
	for (int i=2; i<=MxN; i++)
		if (phi[i] == i)
			for (int j=i; j<=MxN; j+=i)
				phi[j] -= phi[j]/i;
				
	int q; cin >> q;
	while (q--)
	{
		int x; cin >> x;
		cout << phi[x] << "\n";
	}
	
    return 0;
}
