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
int a[MxN];
int n;

bool check(ll K)
{
	ll sum = 0LL;
	for (int i=1; i<=n; i++)
	{
		sum += (ll)(K - a[i]);
		if (sum > K)
			return 0;
	}
	return (sum < K);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int mi = 1e9+7;
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		mi = min(mi, a[i]);
	}

	ll low = 1LL;
	ll high = 1e18;

	while (low < high)
	{
		ll mid = (low + high) >> 1;
		// deb(mid, check(mid));
		if (check(mid))
			low = mid + 1;
		else
			high = mid;
	}

	/*ll i;	
	for (i=mi+1; i<=mi+1e9+1; i++)
		if (check(i) == i)
			break;
	ll low = i;
	*/
	
	for (int i=1; i<=n; i++)
		cout << low - (ll)a[i] << " ";
	cout << "\n";

    return 0;
}
