#include <bits/stdc++.h>
using namespace std;

vector<int> solve()
{
	int n, k; cin >> n >> k;
	vector<int> ans;

	while (k > 3)
		n--, k--, ans.push_back(1);
	
	if (n&1)
	{
		ans.push_back(n/2);
		ans.push_back(n/2);
		ans.push_back(1);
	}
	else if (n % 4 == 0)
	{
		ans.push_back(n/4);
		ans.push_back(n/4);
		ans.push_back(n/2);	
	}
	else
	{
		ans.push_back((n-2)/2);
		ans.push_back((n-2)/2);
		ans.push_back(2);	
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int t; cin >> t;
	while (t--)
	{
		for (auto a : solve())
			cout << a << " ";
		cout << "\n";
	}

	return 0;
}