#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s; cin >> s;
	int ca = 0, cb = 0, cc = 0;
	for (int i=0; i<s.size(); i++)
	{
		if (s[i] == 'A') ca++;
		else if (s[i] == 'B') cb++;
		else cc++;
	}

	if ((cb - ca) == cc)
		cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	while (n--)
		solve();
	
	return 0;
}