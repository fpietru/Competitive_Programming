/*
	Zadanie "Różnica" z XVIII OI, etap II
	Złożoność: O(26*N)
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+99;
vector<int> pos[26];

int merge(int a, int b)
{
	int i=0, j=0;
	int ans = 0, sum = 0, pop_sum = 0, mini = INF;
	while (i < pos[a].size() && j < pos[b].size())
	{
		if (pos[a][i] < pos[b][j])
			sum++, i++;
		else
		{
			sum--, j++;
			mini = min(mini, pop_sum);
			pop_sum = sum;
		}
		ans = max(ans, sum - mini);
	}

	while (i < pos[a].size())
	{
		sum++, i++;
		ans = max(ans, sum - mini);
	}
	
	while (j < pos[b].size())
	{
		sum--, j++;
		mini = min(mini, pop_sum);
		pop_sum = sum;
		ans = max(ans, sum - mini);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string s; cin >> s;

	for (int i=0; i<n; i++)
		pos[s[i]-'a'].push_back(i);

	int best_ans = 0;
	for (int a=0; a<26; a++)
		for (int b=0; b<26; b++)
		{
			if (a == b || pos[a].size() == 0 || pos[b].size() == 0)
				continue;
		
			best_ans = max(best_ans, merge(a, b));
		}

	cout << best_ans << "\n";
	
	return 0;
}