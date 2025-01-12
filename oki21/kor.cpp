/*
	Zadanie "Korale" z XVII OI, etap I
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	const int p = 4e5+9;
	const int mod = 1e9+9;

	int n; cin >> n;
	vector<int> arr(n);

	for (int i=0; i<n; i++)
		cin >> arr[i];

	vector<ll> p_pow(n);
	p_pow[0] = 1;
	for (int i=1; i<n; i++)
		p_pow[i] = (p_pow[i-1] * p) % mod;

	vector<ll> h1(n+1, 0), h2(n+1, 0);
	for (int i=0; i<n; i++)
	{
		h1[i+1] = (h1[i] + arr[i] * p_pow[i]) % mod;
		h2[i+1] = (h2[i] + arr[n-i-1] * p_pow[i]) % mod;
	}

	map<int, vector<int>> mp;
	for (int k=1; k<=n; k++)
	{
		if (n / k == 1)
		{
			mp[1].push_back(k);
			continue;
		}

		set<ll> st;
		for (int i=0; i<=n-k; i+=k)
		{
			int a = i;
			int b = i + k;
			int ra = n - b;
			int rb = n - a;

			ll ch1 = (h1[b] + mod - h1[a]) % mod;
			ch1 = (ch1 * p_pow[n-a-1]) % mod;

			ll ch2 = (h2[rb] + mod - h2[ra]) % mod;
			ch2 = (ch2 * p_pow[n-ra-1]) % mod;

			if (st.find(ch1) == st.end() && st.find(ch2) == st.end())
				st.insert(ch1);
		}

		mp[st.size()].push_back(k);
	}

	int key = mp.rbegin()->first;
 	cout << key << " " << mp[key].size() << "\n";
	for (auto p : mp[key])
		cout << p << " ";
	cout << "\n";

	return 0;
}