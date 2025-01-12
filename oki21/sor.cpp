/*
	Zadanie "Sortowanie biżuterii" z I OIG
*/
#include <bits/stdc++.h>
using namespace std;

const int MxN = 155;
pair<int, string> arr[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		string s; cin >> s;
		arr[i] = {s.size(), s};
	}

	sort(arr, arr+n);

	for (int i=0; i<n; i++)
		cout << arr[i].second << "\n";

	
	return 0;
}