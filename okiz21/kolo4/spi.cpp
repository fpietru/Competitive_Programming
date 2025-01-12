/*
	Zadanie "Śpiew" z OIG, etap I
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string s; cin >> s;

	int seg = 0, ans = 0;
	for (int i=0; i<n; i++)
	{
		if (s[i] == 'Z')
			seg++;
		else
		{
			ans += ceil((double)seg / 3);
			seg = 0;
		}
	}

	ans += ceil((double)seg / 3);
	cout << ans << "\n";
	
	return 0;
}