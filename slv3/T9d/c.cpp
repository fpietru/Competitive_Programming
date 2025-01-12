#include <bits/stdc++.h>
using namespace std;

string multiply(string a, string b)
{
	int as = a.size(), bs = b.size();

	vector<int> res(as+bs+1, 0);

	int pos1 = 0,  pos2 = 0;

	for (int i=as-1; i>=0; i--)
	{
		int reszta = 0;
		int cyfra1 = a[i] - '0';
		pos2 = 0;
		for (int j=bs-1; j>=0; j--)
		{
			int cyfra2 = b[j] - '0';
			int suma = cyfra1 * cyfra2 + res[pos1 + pos2] + reszta;
			res[pos1 + pos2] = suma % 10;
			reszta = suma / 10;
			pos2++;
		}

		if (reszta > 0)
			res[pos1+pos2] += reszta;
		pos1++;
	}

	int i = res.size() - 1;
	while (i >= 0 && res[i] == 0)
		i--;

	string ans = "";
	while (i >= 0)
	{
		ans += to_string(res[i]);
		i--;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string s;

	for (int i=1; i<=n; i++)
		s += "9";

	cout << multiply(s, s) << "\n";

	
	return 0;
}