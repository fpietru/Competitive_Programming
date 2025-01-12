/*
	Zadanie "Klient" z MPSŚPZ 2021 OPEN
*/
#include <bits/stdc++.h>
using namespace std;

int factor(int n)
{
	multiset<int> st;
	while (!(n&1))
		st.insert(2), n >>= 1;
	
	for (int i=3; i*i<=n; i+=2)
		while (n % i == 0)
		{
			st.insert(i);
			n /= i;
		}
	
	if (n > 2)
		st.insert(n);

	return (int)st.size();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	cout << factor(n) << "\n";
	
	return 0;
}