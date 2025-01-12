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

constexpr int MxN = 1e6+6;
ll dp[MxN], a[MxN];

vector<int> divs(int x)
{
	vector<int> res;
	for (int i=1; i*i<=x; i++)
		if (x % i == 0)
		{
			if (i == x / i)
				res.push_back(i);
			else {
				res.push_back(i);
				if (x / i != x)
					res.push_back(x/i);			
			}
		}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
		
	dp[1] = a[1];
	for (int i=2; i<=n; i++)
	{
		// dla dzielników i:
		ll mx = 0LL;
		//cout << i << ": ";
		for (auto p : divs(i))
		{
			//cout << p << " ";
			mx = max(mx, dp[p]);
		}
		//cout << "\n";
			
		dp[i] = max(dp[i-1], a[i] - mx);
	}
	
	/*
	for (int i=1; i<=n; i++)
		cout << dp[i] << "\n";
	cout << "\n";
	*/

	cout << dp[n] << "\n";

    return 0;
}
