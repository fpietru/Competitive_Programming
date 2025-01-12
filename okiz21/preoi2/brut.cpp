/*
	Brut do Szablonu Bajtogrodu
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 2022;
vector<pair<int, char>> G[MxN];
bool vis[MxN];
vector<pii> edges;
set<string> words;
map<pii, bool> mp;
string curr_s;
int n;

void bfs(int st)
{
	queue<pair<int, string>> Q;
	Q.push({st, ""});
	vis[st] = 1;
	
	while (!Q.empty())
	{
		int v = Q.front().FR;
		string w = Q.front().SD;
		Q.pop();
		
		for (auto u : G[v])
			if (!vis[u.FR])
			{
				vis[u.FR] = 1;
				
				string n_word = w + u.SD; 
			
				words.insert(n_word);
				
				Q.push({u.FR, n_word});
			}
	}
}

void dfs(int v, int p, int i, vector<pii> seen, int from)
{	
	if (seen.size() == curr_s.size())
	{
		//cout << "start: " << from << "\n";
		for (auto e : seen)
		{
			//cout << e.FR << " " << e.SD << "\n";
			mp[{e.FR, e.SD}] = 1;
			mp[{e.SD, e.FR}] = 1;
		}
		//cout << "end: " << v << "\n";
		return;
	}

	for (auto u : G[v])
		if (u.FR != p)
		{
			if (u.SD == curr_s[i])
			{
				//cout << v << " " << u.FR << " " << u.SD << " " << curr_s[i] << "\n";
				seen.push_back({v, u.FR});
				dfs(u.FR, v, i+1, seen, v); 
				seen.pop_back();
			}
		}
}

bool checkszablon(string s)
{
	curr_s = s;
	for (auto e : edges)
	{
		mp[{e.FR, e.SD}] = 0;
		mp[{e.SD, e.FR}] = 0;
	}

	vector<pii> v;
	for (int i=1; i<=n; i++)
	{
		dfs(i, i, 0, v, i);
	}

	for (auto e : edges)
	{
		//cout << e.FR << " " << e.SD << " "  << mp[e] << "\n";
		if (mp[e] == 0)
			return 0;
	}	
		
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i=1; i<=n-1; i++)
	{
		int a, b; char c;
		cin >> a >> b >> c;
		G[a].push_back({b, c});
		G[b].push_back({a, c});
		edges.push_back({a,b});
	}
	
	for (int i=1; i<=n; i++)
	{
		memset(vis, 0, sizeof(vis));
		bfs(i);
	}
	
	vector<string> ans;
	for (auto p : words)
		if (checkszablon(p))
			ans.push_back(p);
			
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto p : ans)
		cout << p << "\n";

	
	return 0;
}
