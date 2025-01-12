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
		cin >> a[i];
	
	int ans = 0;
	for (int i=0; i<n; i++)
	{
		if (suma + a[i] < 0)
			ans++;
		else
			suma += a[i];
	}
	
	cout << ans << "\n";
	
    return 0;
}
