#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+6;
int p[MxN], ok[MxN];

void gen()
{
	for (int i=0; i*i<=MxN; i++)
		for (int j=0; j*j+i*i<=MxN; j++)
			ok[i*i+j*j] = 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	gen();
	for (int i=1; i<=MxN; i++)
		p[i] = p[i-1] + ok[i];

	int q; cin >> q;
	while (q--)
	{
		int a, b; cin >> a >> b;
		cout << p[b] - p[a-1] << "\n";
	}

	return 0;
}