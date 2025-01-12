#include <bits/stdc++.h>
using namespace std;
using ll = long long;	

constexpr int MxN = 5e5+15;
int p[MxN];

int getsum(int a, int b)
{
	return p[b] - p[a-1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string s; cin >> s;
	
	int n = s.size();
	
	p[0] = 0;
	for (int i=1; i<=n; i++)
		p[i] = p[i-1] + (s[i-1] == 'I');
		
	//for (int i=0; i<=n; i++)
	//	cout << p[i] << " ";
	//cout << "\n";
	
	ll ans = 0;
	for (int i=0; i<n; i++)
		if (s[i] == 'O')
			ans += getsum(i+1, n);
			
	cout << ans << "\n";
	
	return 0;
}
