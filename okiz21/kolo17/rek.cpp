/*
	Zadanie "Reklama"
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 5e5+5;
int a[MxN], cena[MxN];
int kupione[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k; cin >> n >> m >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=m; i++)
		cin >> cena[i];
	
	kupione[0] = 1e9+7;
	
	int pocz = 0;
	ll sum = 0LL;
	int ans = 0;
	
	for (int kon=0; kon<=n; kon++)
	{
		// deb(kon, pocz, sum);
		while (pocz+1 <= n && sum + (kupione[a[pocz+1]] == 0 ? (ll)cena[a[pocz+1]] : 0LL) <= k)
		{
			sum += (kupione[a[pocz+1]] == 0 ? (ll)cena[a[pocz+1]] : 0LL);
			kupione[a[pocz+1]]++;
			pocz++;
			// deb("W whileu", kon, pocz, sum);
		}
		
		// deb("ANS", kon, pocz);
		ans = max(ans, pocz-kon);
		
		sum -= (--kupione[a[kon+1]] == 0 ? (ll)cena[a[kon+1]] : 0LL);
	}

	cout << ans << "\n";

    return 0;
}
