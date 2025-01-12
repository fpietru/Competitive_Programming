#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second

constexpr int MxN = 2022;
vector<pair<int, char>> G[MxN];
map<pii, bool> marked;
vector<pii> edges;
set<string> words, ans;
set<char> alf;
string curr_s;
int n, zaznaczone;

void dfs(int v, int p, string s)
{
	for (auto u : G[v])
		if (u.FR != p)
		{
			string n_word = s + u.SD;
			
			if ((int)n_word.size() >= (int)alf.size())
			{
				string tn_word = n_word;
				reverse(tn_word.begin(), tn_word.end()); 
				
				if (words.find(tn_word) == words.end() && words.find(n_word) == words.end())
					words.insert(n_word);
			}
			
			dfs(u.FR, v, n_word);
		}
}

void dfs2(int v, int p, int i, vector<pii>& seen)
{	
	if (seen.size() == curr_s.size())
	{
		for (auto e : seen)
		{
			if (marked[{e.FR, e.SD}] == 0)
			{
				zaznaczone++;
				marked[{e.FR, e.SD}] = 1;
			}
		}
		return;
	}

	for (auto u : G[v])
		if (u.FR != p)
			if (u.SD == curr_s[i])
			{
				seen.push_back({min(v, u.FR), max(v, u.FR)});
				dfs2(u.FR, v, i+1, seen); 
				seen.pop_back();
			}
}

bool checkszablon(string& s)
{
	curr_s = s;
	zaznaczone = 0;
	for (auto e : edges)
		marked[e] = 0;
	

	vector<pii> v;
	for (int i=1; i<=n; i++)
		dfs2(i, i, 0, v);

	return (zaznaczone == n-1);
}

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	else
		return a.size() > b.size();
}

void addword(string& s)
{
	ans.insert(s);
	reverse(s.begin(), s.end());
	ans.insert(s);
	words.erase(s);
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
		alf.insert(c);
		edges.push_back({min(a,b), max(a,b)});
	}
	
	for (int i=1; i<=n; i++)
		dfs(i, i, "");
	
	vector<string> kandydaci;
	for (auto p : words)
		kandydaci.push_back(p);
		
	sort(kandydaci.begin(), kandydaci.end(), cmp);

	
	
	for (auto k : kandydaci)
		if (words.find(k) != words.end())
		{
			if (checkszablon(k))
			{
				addword(k);
				
				for (int i=(int)k.size()/2 + (k.size() % 2 == 1); i<(int)k.size(); i++)
				{
					string pref = k.substr(0, i);
					string suff = "";
					for (int j=k.size()-1; j>=(int)k.size()-i; j--)
						suff += k[j];
					
					if (pref == suff)
					{
						addword(pref);
						addword(suff);
					}
				}
					
			}
		}
	
	cout << ans.size() << "\n";
	for (auto p : ans)
		cout << p << "\n";
	
	return 0;
}
