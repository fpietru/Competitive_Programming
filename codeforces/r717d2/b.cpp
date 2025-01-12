#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MxN = 2e3+33;

bool good(vector<int> arr)
{
	sort(arr.begin(), arr.end());
	for (int i=0; i<arr.size()-1; i++)
		if (arr[i] != arr[i+1])
			return 0;
	return 1;
}

void show(vector<int> arr)
{
	for (int i=0; i<arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";
}

bool solve()
{
	int n; cin >> n;
	vector<int> arr(n);
	for (int i=0; i<n; i++)
		cin >> arr[i];

	while (arr.size() > 2)
	{
		show(arr);
		if (good(arr))
			return 1;
		vector<int> nar;
		
		arr = nar;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
		cout << (solve() ? "YES\n" : "NO\n");
	
	return 0;
}