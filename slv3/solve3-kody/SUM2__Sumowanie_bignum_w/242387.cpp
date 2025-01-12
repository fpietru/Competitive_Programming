#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string a, b; cin >> a >> b;
	
	if (a == "0" && b == "0")
	{
		cout << "0\n";
		return 0;
	}
	
	if (a.size() < b.size())
		swap(a, b);
	
	int n = a.size();
	int m = b.size();
	
	vector<int> ans;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	int r = 0;
	int i = 0;
	while (1)
	{
		int s = r;
		if (i < m)
			s += (b[i]-'0');
		if (i < n)
			s += (a[i]-'0');

		if (s == 0 && i >= n)
			break;
	
		int c = s % 10;
		r = s / 10;
		// cout << i << " " << a[i] << " " << b[i] << " " << c << " " << r  << "\n";
		
		ans.push_back(c);
		i++;
	}
		
	reverse(ans.begin(), ans.end());
	
	for (auto p : ans)
		cout << p;
		
	cout << "\n";
	
    return 0;
}
