/*
	Zadanie "Sklepy" z OKI
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct sklep
{
	int cena;
	int prawy;
	int lewy;
};

const int MxN = 5e5+55;
vector<int> G[MxN];
sklep arr[MxN];
int W[MxN]; //stopień wchodzący wierzchołków
ll ans = 0; //wynik

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n; cin >> n;
	for (int i=0; i<n; i++) cin >> arr[i].cena;
	for (int i=0; i<n-1; i++) cin >> arr[i].prawy;
	for (int i=1; i<n; i++) cin >> arr[i].lewy;

	for (int i=0; i<n-1; i++)
	{	
		sklep A = arr[i];
		sklep B = arr[i+1];
		if (A.prawy <= B.lewy)
		{
			W[i+1]++;
			ans += (ll)A.prawy;
			G[i].push_back(i+1);
		}
		else
		{
			W[i]++;
			ans += (ll)B.lewy;
			G[i+1].push_back(i);
		}
	}

	vector<int> sorted;
	queue<int> qu;

	for (int i=0; i<n; i++)
		if (W[i] == 0)
			qu.push(i);

	while (!qu.empty())
	{
		int v = qu.front();
		qu.pop();

		sorted.push_back(v);

		for (auto u : G[v])
		{
			W[u]--;
			if (W[u] == 0)
				qu.push(u);
		}
	}

	for (auto a : sorted)
		ans += (ll)arr[a].cena;

	cout << ans << "\n";

	for (auto a : sorted)
		cout << a + 1 << " ";
	cout << "\n";

	return 0;
}