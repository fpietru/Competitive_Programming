/*
	Kolejka Monotoniczna - przykład użycia
	Zadanie:
		Mamy ciąg n-elementowy.
		Dla każdego przedziału długości k, chcemy znać minimalny element, który się w nim zwiera.
		
		Przykład1:
		5 3
		5 3 6 7 1
		Wynik:
		3 3 6 1
		
		Przykład2:
		4 4
		7 2 5 3
		Wynik:
		2
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 1e6+6;
int a[MxN];
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	/*
		.FR = wartość elementu
		.SD = indeks elementu
	*/

	deque<pii> Q;
	for (int i=1; i<=n; i++)
	{
		if (!Q.empty() && Q.front().SD <= i - k)
			Q.pop_front();
	
		while (!Q.empty() && Q.back().FR >= a[i])
			Q.pop_back();
		
		Q.push_back({a[i], i});
		
		if (i >= k)
			ans.push_back(Q.front().FR);
	}
	
	for (auto p : ans)
		cout << p << " ";
	cout << "\n";

    return 0;
}
