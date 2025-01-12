/*
	Zadanie "Podwójne Podsłowa" z KI
	1/2 rolling hashe
	1/2 brut
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	const int p = 31;
	const int mod = 1e9+7;

	int n; cin >> n;
	string s; cin >> s;

	vector<ll> p_pow(n);
	p_pow[0] = 1;
	for (int i=1; i<n; i++)
		p_pow[i] = (p_pow[i-1] * p) % mod;

	vector<ll> h(n+1, 0);
	for (int i=0; i<n; i++)
		h[i+1] = (h[i] + (s[i]-'a'+1) * p_pow[i]) % mod;

	int q; cin >> q;
	while (q--)
	{
		bool ok;
		int a, b;
		cin >> a >> b;

		if (b - a > 1 && ((b-a)/2)+1 >= 1000)
		{
			int m = (a+b) / 2;
			int i1 = a-1, j1 = m-1;
			int i2 = m, j2 = b-1;
			ll ch1, ch2;

			ch1 = (h[j1] + mod - h[i1]) % mod;
			ch1 = (ch1 * p_pow[n-i1-1]) % mod;

			ch2 = (h[j2] + mod - h[i2]) % mod;
			ch2 = (ch2 * p_pow[n-i2-1]) % mod;

			(ch1 == ch2 ? ok = 1 : ok = 0);
		}
		else
		{
			string s1 = s.substr(a-1, ((b-a)/2)+1);
			string s2 = s.substr(((a+b)/2), ((b-a)/2)+1);

			(s1 == s2 ? ok = 1 : ok = 0);
		}

		cout << (ok ? "TAK\n" : "NIE\n");

	}
	
	return 0;
}