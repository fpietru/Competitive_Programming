#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 5e6+5;
constexpr int MOD = 1e6+7;
int a[MxN];
int licznik = 0;

int oblicz(int n)
{
	if (a[n] != -1)
		return a[n];
	
	if (n % 7 == 0)
	{
		licznik++;
		int n1 = (n/7) * 6;
		a[n] = 2*oblicz(n1);
		return a[n];
	}
	else
	{
		licznik++;
		int Anb = oblicz(n-1);
		a[n] = ((ll)Anb*Anb) % MOD;
		return a[n];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i=0; i<MxN; i++)
		a[i] = -1;
	a[0] = 3;
	
	int n; cin >> n;
	cout << oblicz(n) << " " << licznik << "\n";

	// for (int i=0; i<=n; i++)
	// 	cout << a[i] << "\n";

    return 0;
}
