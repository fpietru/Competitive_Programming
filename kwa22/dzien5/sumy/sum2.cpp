#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 3e5+5;
unordered_map<int, int> mp;
int a[MxN];

int main()
{
	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
 
    sort(a, a + n, greater<int>());
 
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i]] < 1)
            continue;
 
        int curr = 1;
        while (curr <= a[i])
            curr <<= 1;

        if (mp[curr - a[i]])
        {
            if (curr - a[i] == a[i] and mp[a[i]] == 1)
                continue;
 
            ans++;
 
            mp[curr - a[i]]--;
            mp[a[i]]--;
        }
    }
    
    cout << ans << "\n";
	
    return 0;
}
