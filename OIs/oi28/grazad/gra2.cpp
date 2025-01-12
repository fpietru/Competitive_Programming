/*
Zadanie Gra platformowa XXVIII OI, etap I  
Autor: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second
const int MxN = 1e5+7, MxX = 1e3+7;
vector<pair<int, int>> arr[MxN];
int n, x, z, ans;

// void go(int posy, int posx, int cost)

void DEB_show_arr()
{
	for (int i=1; i<=n; i++)
	{
		cout << i << ": ";
		for (auto j : arr[i])
			cout << "[" << j.FR << ", " << j.SD << "] ";
		cout << "\n";
	}
}

void go(int level, int pos, int cost)
{
	auto up = upper_bound(arr[level].begin(), arr[level].end(), make_pair(pos, -1));
	int idx = int(up - arr[level].begin());

	if (idx == arr[level].size()-1)
	{
		ans = min(ans, cost);
		// cout << cost << " [" << level << ", " << pos << "]: Dotarlem na sam koniec\n";
		return;
	}

	if (arr[level][idx].SD == 2) // wezel startowy
	{
		// cout << cost << " [" << level << ", " << pos << "]: Startuje\n";
		go(level, arr[level][idx+1].FR, cost); // ide do przodu
	}

	if (arr[level][idx].SD == 0) // dziura jest tutaj
	{
		if (level < n)
		{
			go(level+1, arr[level][idx].FR+1, cost); // spadam
			// cout << cost << " [" << level << ", " << pos << "]: Spadam\n";
		}
		
		go(level, arr[level][idx+1].FR, cost+1); // przeskakuje dziure
		// cout << cost+1 << " [" << level << ", " << pos << "]: przeskakuje dziure\n";
	}

	if (arr[level][idx].SD == 1) // dziura jest powyzej
	{
		go(level-1, arr[level][idx].FR+1, cost+1); // wskakuje na platforme wyzej 
		// cout << cost+1 << " [" << level << ", " << pos << "]: wskakuje na platforme wyzej\n";
		
		go(level, arr[level][idx+1].FR, cost); // ide do przodu
			// cout << cost << " [" << level << ", " << pos << "]: ide dalej\n";	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// Wczytywanie
	cin >> n >> x >> z;
	for (int i=1; i<=n; i++)
	{
		arr[i].push_back(make_pair(1, 2));
		int h, d; cin >> h;
		for (int j=1; j<=h; j++)
		{
			cin >> d;
			arr[i].push_back(make_pair(d, 0));
			if (i < n)
				arr[i+1].push_back(make_pair(d, 1));
		}
		arr[i].push_back(make_pair(x, 3));
	}

	for (int i=1; i<=n; i++)
		sort(arr[i].begin(), arr[i].end());

	while (z--)
	{
		int s; cin >> s;
		ans = 1e9+7;
		go(s,1,0);
		cout << ans << "\n";
	}

	// DEB_show_arr();


	// go(2, 1, 0);

	return 0;
}