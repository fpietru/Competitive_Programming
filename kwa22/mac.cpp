#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k, l;
	cin >> n >> m >> k >> l;
	vector<vector<int>> row(n+1);	
			
	for (int i=1; i<=n; i++)
	{
		deque<pii> Q;
		for (int j=1; j<=m; j++)
		{
			int x; cin >> x;
		
			if (!Q.empty() && Q.front().SD <= j - l)
				Q.pop_front();
		
			while (!Q.empty() && Q.back().FR >= x)
				Q.pop_back();
			
			Q.push_back({x, j});
			
			if (j >= l)
				row[i].push_back(Q.front().FR);
		}
	}

	vector<vector<int>> ans(n-k+1, vector<int>(m-l+1));

	for (int j=0; j<m-l+1; j++)
	{
		int posy = 0;
		deque<pii> Q;
		for (int i=1; i<=n; i++)
		{
			if (!Q.empty() && Q.front().SD <= i - k)
				Q.pop_front();
		
			while (!Q.empty() && Q.back().FR >= row[i][j])
				Q.pop_back();
			
			Q.push_back({row[i][j], i});
			
			if (i >= k)
				ans[posy++][j] = Q.front().FR;
		}
	}
	
	for (int i=0; i<n-k+1; i++)
	{
		for (int j=0; j<m-l+1; j++)
			cout << ans[i][j] << " ";
		cout << "\n";
	}

    return 0;
}
