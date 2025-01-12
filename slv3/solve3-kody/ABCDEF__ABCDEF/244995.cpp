#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FR first
#define SD second

constexpr int MxN = 105;
constexpr int INF = 1e9+7;
vector<int> v1, v2;
int s[MxN];
ll ans;

int main()
{
	// ios_base::sync_with_stdio(0);
	// cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> s[i];	
	
	for (int a=1; a<=n; a++)
		for (int b=1; b<=n; b++)
			for (int c=1; c<=n; c++)
			{
				int x = s[a]*s[b] + s[c];
				v1.push_back(x);
			}
	
	for (int d=1; d<=n; d++)
		for (int e=1; e<=n; e++)
			for (int f=1; f<=n; f++)
			{
				int x = s[d]*s[f] + s[d]*s[e];
				v2.push_back(x);
			}
				
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	v1.push_back(-INF);
	v2.push_back(INF);
	
/*	ll ans = 0LL;
	for (auto p : mp1)
	{
		cout << p.FR << ": " << p.SD << " " << mp2[p.FR] << "\n";
		ans += p.SD * mp2[p.FR];
	}
	
	cout << ans << "\n"; */
	
	int i = 0;
	int j = 0;
	int ile1 = 0;
	int ile2 = 0;
	int akt = -1;
	while (i < (int)v1.size()-1 && j < (int)v2.size()-1)
	{	
		if (akt == -1 || (v1[i+1] != akt && v2[j+1] != akt))
		{
			// cout << akt << ": " << ile1 << " " << ile2 << "\n"; 
			akt = min(v1[i+1], v2[j+1]);
			ans += (ll)ile1 * ile2;
			ile1 = ile2 = 0;
		}
		
		while (v1[i+1] == akt)
		{
			ile1++;
			i++;
		}
		
		while (v2[j+1] == akt)
		{
			ile2++;
			j++;
		}
	}
	
	cout << ans << "\n";
	
    return 0;
}
