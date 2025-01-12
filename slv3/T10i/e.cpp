#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int base = (1<<17);
pii T1[2*base], T2[2*base];

void add1(int v, int x)
{
	v += base;
	T1[v].FR += x;
	T1[v].SD = v-base;
	v /= 2;
	while (v)
	{
		if (T1[2*v].FR <= T1[2*v+1].FR)
			T1[v] = T1[2*v];
		else
			T1[v] = T1[2*v+1];

		v /= 2;
	}
}

void add2(int v, int x)
{
	v += base;
	T2[v].FR += x;
	T2[v].SD = v-base;
	v /= 2;
	while (v)
	{
		if (T2[2*v].FR >= T2[2*v+1].FR)
			T2[v] = T2[2*v];
		else
			T2[v] = T2[2*v+1];

		v /= 2;
	}
}

pii getMax(int a, int b)
{
	int val = 0;
	int pos = -1;
	a += base - 1;
	b += base + 1;
	while (a / 2 != b / 2)
	{
		if (a % 2 == 0 && T2[a+1].FR >= val)
		{
			val = T2[a+1].FR;
			pos = T2[a+1].SD;
		}
		
		if (b % 2 == 1 && T2[b-1].FR >= val)
		{
			val = T2[b-1].FR;
			pos = T2[b-1].SD;
		}

		a /= 2;
		b /= 2;
	}
	return make_pair(val, pos);
}

pii getMin(int a, int b)
{
	int val = 1e9+7;
	int pos = -1;
	a += base - 1;
	b += base + 1;
	while (a / 2 != b / 2)
	{
		if (a % 2 == 0 && T1[a+1].FR <= val)
		{
			val = T1[a+1].FR;
			pos = T1[a+1].SD;
		}
		
		if (b % 2 == 1 && T1[b-1].FR <= val)
		{
			val = T1[b-1].FR;
			pos = T1[b-1].SD;
		}

		a /= 2;
		b /= 2;
	}
	return make_pair(val, pos);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		add1(i, x);
		add2(i, x);
	}

	vector<pii> ans;

	while (k--)
	{
		pii Mx = getMax(1, n);
		pii Mi = getMin(1, n);

		if (Mx > Mi)
		{
/*			cout << " ==" << Mx.FR << " " << Mi.FR << "\n";

			diff = min(diff, Mx.FR - Mi.FR);*/
			add1(Mx.SD, -1);
			add2(Mx.SD, -1);
			add1(Mi.SD, 1);
			add2(Mi.SD, 1);

			ans.push_back({Mx.SD, Mi.SD});
		}
	}

	int diff = getMax(1, n).FR - getMin(1, n).FR;

	cout << diff << " " << ans.size() << "\n";
	for (auto p : ans)
		cout << p.FR << " " << p.SD << "\n";
	
	return 0;
}