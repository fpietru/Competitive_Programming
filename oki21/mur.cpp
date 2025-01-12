/*
	Zadanie "Mur" z III OIG
*/
#include <bits/stdc++.h>
#define FR first
#define SD second
using namespace std;
using ll = long long;
const int MxN = 1e5+5;
pair<int, int> arr[MxN];
int ilos[MxN];
int n, m, x, y, a, b;

int iv(pair<int, int> A, pair<int, int> B)
{
	ll ilo = (ll)A.FR*B.SD - (ll)B.FR*A.SD;
	if (ilo > 0) return 1;
	else if  (ilo < 0) return -1;
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> m;
	while (m--)
	{
		cin >> n >> x >> y;
		for (int i=0; i<n; i++)
		{
			cin >> a >> b;
			arr[i] = {a-x, b-y};
		}

		for (int i=0; i<n; i++)
			ilos[i] = iv(arr[i], arr[(i+1)%n]);

		bool ans = 1;
		for (int i=0; i<n; i++)
			if (ilos[i] != ilos[(i+1)%n])
			{
				ans = 0;
				break;
			}

		cout << (ans ? "TAK\n" : "NIE\n");
	}



	return 0;
}