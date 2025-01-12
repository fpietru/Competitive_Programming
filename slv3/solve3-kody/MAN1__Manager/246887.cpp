#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 505;
constexpr int INF = 1e9+7;
int p[MxN];
int ans = 0;

int suma(int a, int b)
{
	return p[b] - p[a-1];
}

void dziel(int st, int ed)
{
	if (st == ed)
		return;
		
	// znaleźć poz środkową
	int mi = INF, pos;
	for (int i=st; i<=ed-1; i++)
	{
		// cout << "[" << st << " " << ed << "] " << i << " " << suma(st, i) << " " << suma(i+1, ed) << "\n";
		if (abs(suma(st, i) - suma(i+1, ed)) < mi)
			mi = abs(suma(st, i) - suma(i+1, ed)), pos = i;
	}
	
	ans += mi;
	
	dziel(st, pos);
	dziel(pos+1, ed);
}

void solve()
{
	string s; cin >> s;
	int n = s.size();
	for (int i=1; i<=n; i++)
		p[i] = p[i-1] + (s[i-1]-'a' + 1);
		
	/*for (int i=0; i<=n; i++)
		cout << p[i] << " ";
	cout << "\n"; */
	
	ans = 0;
	dziel(1, n);
	cout << ans << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--)
		solve();

    return 0;
}
