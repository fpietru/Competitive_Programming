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

ll sum(ll n)
{
	return ((1 + n) * n) / 2;
}

ll getcost(ll k)
{
	return k + 2*sum(k-1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int q; cin >> q;
	while (q--)
	{
		ll n; cin >> n;
	
		n *= 10;
	
		ll low = 0;
		ll high = 1e8 + 696969;
		while (low < high)
		{
			ll mid = (low + high) >> 1;
			if (getcost(mid) <= n)
				low = mid + 1;
			else high = mid;
		}
		
		if (getcost(low) > n)
			low--;
		
		// deb(low, getcost(low));
		cout << low << "\n";
	}

    return 0;
}
