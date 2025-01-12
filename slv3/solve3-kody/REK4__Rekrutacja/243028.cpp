#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxF = 88;
multiset<ll> rozklad;
ll f[MxF+1];
ll n; int k;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	f[0] = 1;
	f[1] = 1; 
	for (int i=2; i<=MxF; i++)
		f[i] = f[i-1] + f[i-2];

	cin >> n >> k;
	
	// najmniejszy rozkład na liczby fibonacciego
	while (n > 0)
		for (int i=MxF; i>=0; i--)
			if (n - f[i] >= 0)
			{
				n -= f[i];
				rozklad.insert(f[i]);
				break;
			}
	
	if (n > 0)
	{
		cout << "NIE\n";
		return 0;
	}
	
	// powiększanie tego rozkładu do mocy k
	while ((int)rozklad.size() < k)
	{
		auto biggest = rozklad.end();
		biggest--;
		
		if (*biggest == 1)
			break;
		
		int i;
		for (i=1; i<=MxF; i++)
			if (f[i] == *biggest)
				break;
		
		rozklad.erase(*biggest);
		rozklad.insert(f[i-1]);
		rozklad.insert(f[i-2]);
	}
	
	if ((int)rozklad.size() < k)
	{
		cout << "NIE\n";
		return 0;
	}
	
	for (auto p : rozklad)
		cout << p << " ";
	cout << "\n";
	
    return 0;
}
