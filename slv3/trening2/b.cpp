#include <bits/stdc++.h>
using namespace std;

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

using ull = unsigned long long;
ull n;

ull product(int st, int dl)
{
	ull res = 1;
	for (int i=st; i<=st+dl-1; i++)
	{
		res *= (ull)i;
		if (res > (ull)1e15)
			return 1e18;
	}
		
	return res;
}

int bisearch(int l)
{
	int low = 1;
	int high = sqrt(n) + 1;
	
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (product(mid, l) < n)
		{
			low = mid + 1;
		}
		else
			high = mid;
	}
	
	return low-1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	
	int ans = 0;
	for (int i=2; i<=18; i++)
		ans += bisearch(i);
		
	cout << ans << "\n";

    return 0;
}
