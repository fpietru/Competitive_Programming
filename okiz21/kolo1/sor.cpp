#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<string> v(n);
	for (int i=0; i<n; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), cmp);
	for (string s : v)
		cout << s << "\n";
	
	return 0;
}