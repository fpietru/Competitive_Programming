#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

map<int, int> mp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	
	for (int i=1; i<=n; i++)
	{
		int p, k, x; cin >> p >> k >> x;
		mp[p]++;
	}
	
	for (auto p : mp)
		if (p.SD & 1)
		{
			cout << p.FR << " " << p.SD << "\n";
			return 0;
		}

	cout << "NIE\n";

    return 0;
}
