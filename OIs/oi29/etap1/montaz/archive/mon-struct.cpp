#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second

struct task { int czas, deadl, id; };

bool cmp(task a, task b)
{
	if (a.deadl == b.deadl)
		return a.czas <= b.czas;
	return a.deadl < b.deadl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<task> tasks;
	for (int i=1; i<=n; i++)
	{
		int a, b; cin >> a >> b;
		tasks.push_back({a, b, i});
	}

	sort(tasks, tasks, cmp);

	ll C = 1;
	priority_queue<pair<int,pii>> qu;
	
	for (task t : tasks)
	{
		qu.push({t.czas, {t.id, C}});
		C += (ll)t.czas;

		if (C > (ll)(t.deadl - 1))
		{
			C -= (ll)qu.top().FR;
			qu.pop();
		}
	}

	cout << qu.size() << "\n";
/*	while (!qu.empty())
	{
		pii ans = qu.top().SD; qu.pop();
		cout << ans.FR + 1 << " " << ans.SD << "\n";
	}*/

/*	double memory = (double)(sizeof(order) + sizeof(p) + sizeof(d)) / (double)1048576.0;
	cout << memory << "\n";*/

	return 0;
}