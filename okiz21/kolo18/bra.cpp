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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	priority_queue<ll, vector<ll>, greater<ll>> Q;

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		ll x; cin >> x;
		Q.push(x);
	}
	
	ll ans = 0LL;
	while (Q.size() > 1)
	{
		ll FRbest = Q.top(); Q.pop();
		ll SDbest = Q.top(); Q.pop();
		ll sum = FRbest + SDbest;
		ans += sum;
		Q.push(sum);
	}
	
	cout << ans << "\n";

    return 0;
}
