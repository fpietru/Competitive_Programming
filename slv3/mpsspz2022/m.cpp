#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
#define FR first
#define SD second // debugging /*
template <typename T> struct tag:reference_wrapper <T>{ using reference_wrapper <T>::reference_wrapper; };
template <typename T1, typename T2> static inline tag <ostream> operator<<(tag <ostream> os, pair<T1, T2> const& p){ return os.get()<<"{"<<p.first<<", "<<p.second<<"}", os;}
template <typename Other> static inline tag <ostream> operator<<(tag <ostream> os, Other const& o){ os.get()<<o; return os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, vector <T> const& v){ os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
template <typename T> static inline tag <ostream> operator <<(tag <ostream> os, set <T> const& s){ vector <T> v; for (auto i: s) v.push_back(i); os.get()<<"["; for (int i=0; i<v.size(); i++) if (i!=v.size()-1) os.get()<<v[i]<<", "; else os.get()<<v[i]; return os.get()<<"]", os; }
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
	cout << "[ " << vars << " = "; string delim = "";
	(..., (cout << delim << values, delim = ", "));
	cout << " ]\n";
}
/**/


constexpr int MxN = 1e4+4;
vector<vector<int>> cykle;
int idziedo[MxN];
bool vis[MxN];
bool wolny[MxN];
vector<int> wolne;
vector<pii> ans;

void napraw(vector<int> &cykl)
{
	int k = cykl.size();
	for (int i=0; i<k-1; i++)
	{
		ans.push_back({wolne[0], cykl[i]});
		swap(idziedo[wolne[0]], idziedo[cykl[i]]);
	}
	ans.push_back({wolne[1], cykl[k-1]});
	swap(idziedo[wolne[1]], idziedo[cykl[k-1]]);
	
	ans.push_back({wolne[0], cykl[k-1]});
	swap(idziedo[wolne[0]], idziedo[cykl[k-1]]);

	ans.push_back({wolne[1], cykl[0]});
	swap(idziedo[wolne[1]], idziedo[cykl[0]]);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(wolny, 1, sizeof(wolny));

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		idziedo[i] = x;
	}
	int m; cin >> m;
	for (int i=1; i<=m; i++)
	{
		int a, b; cin >> a >> b;
		wolny[a] = wolny[b] = 0;
	}
	for (int i=1; i<=n; i++)
		if (wolny[i])
			wolne.push_back(i);
	
	for (int i=1; i<=n; i++)
		if (vis[i] == 0)
		{
			vector<int> cykl;
			int v = idziedo[i];
			do
			{
				cykl.push_back(v);
				vis[v] = 1;
				v = idziedo[v];
			}
			while (vis[v] != 1);
			if (cykl.size() > 1)
				cykle.push_back(cykl);
		}
	
	for (auto cykl : cykle)
		napraw(cykl);
	
	if (wolne[0] != idziedo[wolne[0]])
	{
		ans.push_back({wolne[0], wolne[1]});
		swap(idziedo[wolne[0]], idziedo[wolne[1]]);
	}
	
	cout << ans.size() << "\n";
	for (auto p : ans)
		cout << p.FR << " " << p.SD << "\n";
	
	return 0;
}
