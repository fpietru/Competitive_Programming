#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e5+55;
int A[MxN], B[MxN], S[MxN];
set<int> no9pos;

void update(bool mode, int pos, int val)
{
	if (!mode) A[pos] = val;
	else B[pos] = val;

	S[pos] = A[pos] + B[pos];
	
	if (S[pos] != 9) 
		no9pos.insert(pos);
	else
		no9pos.erase(pos);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;
	string a, b; cin >> a >> b;

	for (int i=1; i<n; i++) A[i] = a[i-1] - '0';
	for (int i=1; i<n; i++) B[i] = b[i-1] - '0';
	for (int i=1; i<n; i++)
	{
		S[i] = A[i] + B[i];

		if (S[i] != 9)
			no9pos.insert(i);
	}

	while (q--)
	{
		char op; cin >> op;
		int pos, val;
		if (op == 'W')
		{
			cin >> pos >> val;
			update(0, n-pos, val);
		}
		else if (op == 'Z')
		{
			cin >> pos >> val;
			update(1, n-pos, val);
		}
		else
		{
			cin >> pos;
			pos = n - pos;

			auto it = no9pos.upper_bound(pos);

			if (it == no9pos.end())
				cout << S[pos] % 10 << "\n";
			else
			{
				int ans = (S[pos] + (S[*it] >= 10)) % 10;
				cout << ans << "\n";
			}
		}
	}

	return 0;
}