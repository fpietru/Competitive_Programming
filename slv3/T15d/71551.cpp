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

constexpr int MxN = 3e5+5;
int a[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll suma = 0;
	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
		suma += (ll)a[i];
	}
	
	sort(a, a+n);
	
	int ans = 0;
	while (suma < 0)
		suma -= (ll)a[ans++];
	
	cout << ans << "\n";
	
    return 0;
}
