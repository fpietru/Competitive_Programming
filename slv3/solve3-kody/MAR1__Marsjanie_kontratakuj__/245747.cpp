#include <bits/stdc++.h>
using namespace std;

struct query { int st, ed, id; };
bool cmp(query a, query b) { return a.st < b.st; }
constexpr int MxA = 1e3+3, MxN = 1e6+6, MxQ = 1e5+5;
int A[MxA], t[MxN], ans[MxQ]; 
query q[MxQ];
int segans = 0;

void add(int x)
{
	segans += (A[x] == 0);
	A[x]++;
}

void del(int x)
{
	segans -= (A[x] == 1);
	A[x]--;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, k; cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> t[i];
	for (int i=0; i<k; i++)
	{
		int a, b; cin >> a >> b;
		q[i] = {b, a, i};
	}

	sort(q, q+k, cmp);

	int head = 0, tail = 0;
	for (int i=0; i<k; i++)
	{
		while (head < q[i].st) add(t[++head]);
		while (tail < q[i].ed) del(t[tail++]);
		ans[q[i].id] = segans;
	}

	for (int i=0; i<k; i++)
		cout << ans[i] << "\n";

	return 0;
}