#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; cin >> n;

	vector<char> ans;
	while (n)
	{
		char c;
		if (n&1) c = 'L';
		else c = 'P';
		ans.push_back(c);
		n >>= 1;
	}

	reverse(ans.begin(), ans.end());
	for (char c : ans)
		cout << c;
	cout << "\n";
	
	return 0;
}