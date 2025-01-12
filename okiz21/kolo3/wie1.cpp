#include <bits/stdc++.h>
using namespace std;

const string vow = "aeiouy";

bool sameending(string &a, string &b, int &k)
{
	for (int l=0; l<k; l++)
		if (a[a.size()-l-1] != b[b.size()-l-1])
			return 0;
	return 1;
}

void delspacing(string &s)
{
	int vows = 0;
	string res = "";
	for (int i=0; i<s.size(); i++)
		if (s[i] != ' ')
			res += s[i];
	s = res;
}

int countvowels(string &s)
{
	int res = 0;
	for (int i=0; i<s.size(); i++)
		for (int j=0; j<vow.size(); j++)
			if (vow[j] == s[i])
			{
				res++;
				break;
			}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string a, b;
	int n, k, ans=0;
	cin >> n >> k;

	getline(cin, a); // jakiś bug z getlinem :(
	for (int i=0; i<n; i++)
	{
		getline(cin, a);
		getline(cin, b);
		delspacing(a);
		delspacing(b);

		if (a.size() < k) continue;
		if (b.size() < k) continue;
		if (!sameending(a, b, k)) continue;
		if (countvowels(a) != countvowels(b)) continue;
		ans++;
	}

	cout << ans << "\n";

	return 0;
}