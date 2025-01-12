/*
	Zadanie "Dziedzice" z KI 
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

constexpr int MxN = 2e6+6;
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll goal = 0LL;
	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		a[i+n] = a[i];
		goal += (ll)a[i];
	}
	
	goal /= 2;
	
	int pocz = 0;
	ll sum = 0LL, ans = 0LL;
	for (int kon=0; kon<=2*n; kon++)
	{
		while (pocz+1 <= 2*n && (pocz+1)-kon+1 <= n && sum + a[pocz+1] <= goal)
			sum += a[++pocz];
		ans = max(ans, sum);
		sum -= a[kon];
	}

	cout << ans << "\n";

    return 0;
}
