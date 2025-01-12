/*
	Zadanie "Szatnia" z XIX OI, etap II
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e3+13;
constexpr int MxQ = 1e6+16;
constexpr int MxK = 1e5+15;
constexpr int INF = 1e9+7;

struct elem {int st, ed, val, id, t; };

int dp[MxK], ans[MxQ];
elem elementy[MxN+MxQ];

bool cmp(elem A, elem B)
{
	if (A.st == B.st)
		return A.t < B.t;
	return A.st < B.st;
}

void additem(int wartosc, int koniec)
{
	for (int i=MxK-1; i>=wartosc; i--)
		dp[i] = max(dp[i], min(dp[i-wartosc], koniec));
}

bool check(int wartosc, int koniec)
{
	return dp[wartosc] >= koniec;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i=0; i<n; i++)
	{
		int c, a, b; cin >> c >> a >> b;
		elementy[i] = {a, b, c, 0, 1};
	}
	int q; cin >> q;
	for (int i=0; i<q; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		elementy[i+n] = {a, a+c+1, b, i, 2};
	}

	sort(elementy, elementy+n+q, cmp);

	dp[0] = INF;
	for (int i=1; i<MxK; i++)
		dp[i] = -INF;

	for (int i=0; i<n+q; i++)
	{
		elem e = elementy[i];
		
		if (e.t == 1) additem(e.val, e.ed);
		else ans[e.id] = check(e.val, e.ed);
	}

	for (int i=0; i<q; i++)
		cout << (ans[i] ? "TAK\n" : "NIE\n");

	return 0;
}