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

int solve()
{
	int n, k; cin >> n >> k;
	k++;
	
	if (n % k == 0 && n != 0)
		return 0;
	
	if (n == 0)
	{
		int in = 1;
		while ((n + in) % k != 0)
			in++;
		return in;
	}
	
	int in = 1;
	while ((n + in) % k != 0)
		in++;
	
	int de = 1;
	while ((n - de) % k != 0)
		de++;	
	
	if (de < in && (n-de) >= k)
		return de;
	else
		return in;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t; cin >> t;
	while (t--)
		cout << solve() << "\n";

    return 0;
}
