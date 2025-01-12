#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

const int MxN = 1e2+22;
pair<int, int> a[MxN];

bool check(int i, int j)
{
	if (a[i].FR > a[j].FR || (a[i].FR == a[j].FR && a[i].SD >= a[j].SD))
		return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		string s; cin >> s;
		int cyfr = s[0]-'0';
		string miano = s.substr(1, 2);
		int mval;

		if (miano == "C") mval = 1;
		else if (miano == "D") mval = 2;
		else if (miano == "H") mval = 3;
		else if (miano == "S") mval = 4;
		else mval = 5;

		a[i] = {cyfr, mval};
	}

	for (int i=0; i<n-1; i++)
		if (!check(i, i+1))
		{
			cout << "licytacja niepoprawna\n";
			return 0;
		}


	int player = n % 4;
	if (player == 0 || player == 2)
		cout << "WE\n";
	else
		cout << "NS\n"; 

	return 0;
}