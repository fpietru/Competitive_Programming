#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int MxN = 1e6+16;
int a[MxN];

ll f_cel(int st, int ed)
{
	vector<int> v;
	for (int i=st; i<=ed; i++)
		v.push_back(a[i]);

	sort(v.begin(), v.end());

	int mediana;
	if (v.size() % 2 != 0)
		mediana = 2*v[v.size()/2];
	else
		mediana = v[(v.size()-1)/2] + v[((v.size()-1)/2) + 1];

	return (ll)(ed-st+1) + (ll)mediana;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	
	ll val_mx = -1;
	ll cnt_mx = 0;

	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++)
		{
			ll cel = f_cel(i, j); 

			if (cel > val_mx)
			{
				val_mx = cel;
				cnt_mx = 1;
			}
			else if (cel == val_mx)
				cnt_mx++;
		}

	cout << val_mx << " " << cnt_mx << "\n";

	return 0;
}