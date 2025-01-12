/*
Zadanie Gang Tablica Binarna XXVIII OI, etap I  
Autor: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;

const int MxQ=1e5+7;
int quest[MxQ][4];
int n, m, q;


void DEB_show_arr(vector<vector<bool>> arr)
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
			cout << (arr[i][j] ? "#" : ".");
		cout << "\n";
	}
}

vector<vector<bool>> change(vector<vector<bool>> arr, int i1, int j1, int i2, int j2)
{
	vector<vector<bool>> ret = arr;
	for (int x=i1; x<=i2; x++)
		for (int y=j1; y<=j2; y++)
			ret[x][y] = arr[x][y] ^ 1;
	return ret;
}

pair<int, int> getmaxcords(vector<vector<bool>> arr)
{
	float mdst = 0.0;
	int p1=-1, p2=-1;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (arr[i][j])
			{
				float tdst = sqrt((j-1)*(j-1)+(i-1)*(i-1));
				// cout << "[" << i << ", " << j << "]: " << tdst << "\n";
				if (tdst >= mdst)
				{
					mdst = tdst;
					p1 = i, p2 = j;		
				}
			}

	return make_pair(p1, p2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// Wczytywanie 
	cin >> n >> m >> q;
	for (int i=0; i<q; i++)
		for (int j=0; j<4; j++)
			cin >> quest[i][j];

	vector<vector<bool>> arr1(n+1, vector<bool>(m+1,0));

	for (int i=0; i<q; i++)
	{
		arr1 = change(arr1, quest[i][0], quest[i][1], quest[i][2], quest[i][3]);
		//cout << "zmiana: " << i << "\n";
		DEB_show_arr(arr1);

		int ans = 0;
		vector<vector<bool>> arr2 = arr1;
		while (true)
		{	
			//cout << "ANS: " << ans << "\n";
			//DEB_show_arr(arr2);
			pair<int, int> mcords = getmaxcords(arr2);
			if (mcords == make_pair(-1,-1))
				break;

			arr2 = change(arr2, 1, 1, mcords.first, mcords.second);
			ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}
