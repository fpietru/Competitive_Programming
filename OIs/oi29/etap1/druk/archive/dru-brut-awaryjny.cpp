/*
	Wersja Awaryjna, 0.01% błędu, brut
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e3+13;
char T[MxN][MxN];
int P[2][MxN][MxN];
int psum[MxN];
int Next[MxN];
bool vis[MxN][MxN];
set<string> st;

void show(string s, int n, int m, int mode)
{
	cout << s.size() << " " << s << "\n";
	if (mode == 1)
	{
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				int c = P[0][i][j] + P[1][i][j];
				if (c == 1)
					cout << "\033[34m";
				else if (c == 2)
					cout << "\033[33m";
				else if (c == 3)
					cout << "\033[31m";

				cout << c;

				if (c != 0)
					cout << "\033[0m";
			}
			cout << "\n";
		}
	}
	else
	{
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				if (P[0][i][j] != 0)
					cout << "\033[31m" << P[0][i][j] << "\033[0m";
				else cout << P[0][i][j];
			}
			cout << "\n";
		}
		cout << "&\n";
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<m; j++)
			{
				if (P[1][i][j] != 0)
					cout << "\033[31m" << P[1][i][j] << "\033[0m";
				else cout << P[1][i][j];
			}
			cout << "\n";
		}
	}
	cout << "\n";
}

void prefsufs(string S)
{
    Next[0] = -1;
    int i = 0, j = -1;
    int len = S.size();
    while(i < len)
    {
        if(j == -1 || S[i] == S[j])
            Next[++i] = ++j;
        else
            j = Next[j];
	}

	j = S.size();
	while (Next[j])
	{
		st.insert(S.substr(0, Next[j]));
		j = Next[j];
	}
}

void Naive(string s, string pat)
{
	memset(psum, 0, sizeof(psum));
	int N = s.size();
	int M = pat.size();
	for (int i=0; i<=N-M; i++)
	{
		int j = 0;
		int cnt = 0;
		for (j=0; j<M; j++)
			if (s[i+j] != pat[j])
				break;

		if (j == M)
		{
			psum[i]++;
			psum[i+j]--;
			
			i += M-1;
		}
	}
}

bool check(string s, int n, int m)
{	
	// dla wierszy
	for (int i=0; i<n; i++)
	{
		string row = "";
		for (int j=0; j<m; j++)
			row += T[i][j];
		
		Naive(row, s);

		int sum = 0;
		for (int j=0; j<m; j++)
		{
			sum += psum[j];
			P[0][i][j] = sum;
		}
	}

	// dla kolumn
	for (int j=0; j<m; j++)
	{
		string col = "";
		for (int i=0; i<n; i++)
			col += T[i][j];

		Naive(col, s);

		int sum = 0;
		for (int i=0; i<n; i++)
		{
			sum += psum[i];
			P[1][i][j] = sum;
		}
	}


	int blue = 0, yellow = 0, white = 0;

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
		{
			int cell = P[0][i][j] + P[1][i][j];
			if (cell == 0) white++;
			else if (cell == 1) blue++;
			else if (cell == 2) yellow++;
		}

	memset(vis, 0, sizeof(vis));

	int sz = s.size();
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
		{
			int cell = P[0][i][j] + P[1][i][j];
			if (cell == 2)
			{
				int goR = 1;
				while (j+goR < m && goR < sz && P[0][i][j+goR] + P[1][i][j+goR] == 2)
					goR++;

				int goD = 1;
				while (i+goD < n && goD < sz && P[0][i+goD][j] + P[1][i+goD][j] == 2)
					goD++;

				if (goR == sz)
				{
					yellow -= sz;
					for (int k=0; k<sz; k++)
						vis[i][j+k] = 1;
				}
				else if (goD == sz)
				{
					yellow -= sz;
					for (int k=0; k<sz; k++)
						vis[i+k][j] = 1;
				}
			}
		}

/*	show(s, n, m, 1);
	cout << "B:" << blue << " Y:" << yellow << " W:" << white << "\n";
*/
	if (white > 0 && abs(yellow-white) > yellow / 2)
		return 0;

	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i=0; i<n; i++)
	{
		string s; cin >> s;
		for (int j=0; j<m; j++)
			T[i][j] = s[j];
	}

	string s1 = "", s2 = "", s3 = "", s4 = "";
	for (int i=0; i<m; i++) s1 += T[0][i]; s1 += "#";
	for (int i=0; i<m; i++) s1 += T[n-1][i];

	for (int i=0; i<n; i++) s2 += T[i][0]; s2 += "#";
	for (int i=0; i<n; i++) s2 += T[i][m-1];

	for (int i=0; i<m; i++) s3 += T[0][i]; s3 += "#";
	for (int i=0; i<n; i++) s3 += T[i][m-1];

	for (int i=0; i<n; i++) s4 += T[i][0]; s4 += "#";
	for (int i=0; i<m; i++) s4 += T[n-1][i];

	prefsufs(s1);
	prefsufs(s2);
	prefsufs(s3);
	prefsufs(s4);

	vector<int> ans;

	for (string p : st)
		if (check(p, n, m) == 1)
			ans.push_back(p.size());

	sort(ans.begin(), ans.end());
	
	cout << ans.size() << "\n";
	for (int p : ans)
		cout << p << " ";
	cout << "\n";
	
	return 0;
}