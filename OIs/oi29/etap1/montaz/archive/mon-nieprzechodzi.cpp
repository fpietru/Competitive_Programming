#include <bits/stdc++.h>
using namespace std;

struct film
{
	int czas;
	int deadl;
	int id;
};

bool cmp(film a, film b)
{
	if (a.deadl == b.deadl)
		return a.czas < b.czas;
	return a.deadl < b.deadl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<film> filmy;
	for (int i=1; i<=n; i++)
	{
		int t, d; cin >> t >> d;
		if (t <= d)
			filmy.push_back({t, d, i}); 
	}

	sort(filmy.begin(), filmy.end(), cmp);

/*	for (film f : filmy)
		cout << f.id << " " << f.deadl << " " << f.czas << "\n";*/

	int curr_dzien = 1;
	vector<pair<int, int>> ans;
	for (film f : filmy)
		if (curr_dzien + f.czas - 1 <= f.deadl)  /*dzięki -1 mon1.in przechodzi*/ 
		{
			ans.push_back({f.id, curr_dzien});
			curr_dzien += f.czas;
		}

	cout << ans.size() << "\n";
/*	for (pair<int, int> p : ans)
		cout << p.first << " " << p.second << "\n";
*/
	return 0;
}
