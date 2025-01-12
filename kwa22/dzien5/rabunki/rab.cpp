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

constexpr int MxN = 10;
int P[MxN];
int B[MxN];
bool used[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> P[i];
	for (int i=1; i<=n; i++)
		cin >> B[i];
		
	ll ans = 0LL;
	for (int i=1, j=n; i<=n; i++, j--)
		ans += (ll)(B[i] - P[j]);
		
	cout << ans << "\n";
	for (int i=1; i<=n; i++)
		cout << i << " ";
	cout << "\n";

    return 0;
}
















