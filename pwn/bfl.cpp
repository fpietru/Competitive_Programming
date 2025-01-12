#include <bits/stdc++.h>

using namespace std;

int check(vector<int> v, int a, int b)
{
	int ans = 0;
	for (int i=0; i<v.size(); i++)
	{
		if (i % 2 == 0 && v[i] != a)
			ans++;
		if (i % 2 != 0 && v[i] != b)
			ans++;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int s; cin >> s;
	vector<int> v(s);
	vector<int> p;
	vector<int> n;
	for (int i=0; i<s; i++)
	{
		cin >> v[i];
		if (i % 2 == 0) p.push_back(v[i]);
		else n.push_back(v[i]); 
	}

	int ans = 1e9;
	for (int i=0; i<p.size(); i++)
		for (int j=0; j<n.size(); j++)
			ans = min(ans, check(v, p[i], n[j]));

	cout<<ans<<endl;

	return 0;
}