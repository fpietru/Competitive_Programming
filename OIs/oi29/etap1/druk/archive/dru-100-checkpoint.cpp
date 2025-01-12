/*
	Wersja z overlapami
*/
#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

constexpr int MxN = 1e3+13;
char T[MxN][MxN];
int A[MxN][MxN];
int psum[2][MxN];
int Next[MxN];
map<int, set<string>, greater<int>> Group;

void show(string s, int n, int m)
{
	cout << s.size() << " " << s << "\n";
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			int c = A[i][j];
			if (c == 1) cout << "\033[34m";
			else if (c == 2) cout << "\033[33m";
			else if (c == 3) cout << "\033[31m";
			cout << c;
			if (c != 0) cout << "\033[0m";
		}
		cout << "\n";
	}
	cout << "\n";
}

// szybciej
int Per(string s)
{
	int n = s.size();
	for (int p = 1; p <= n; p++)
	{
		int i = p;
		string candidate = s.substr(0, p);
		for (; i<n; i+=p)
			if (s.substr(i, p) != candidate)
				break;
		if (i == n)
			return p;
	}
	return -1;
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
		string res = S.substr(0, Next[j]);
		Group[Per(res)].insert(res);
		j = Next[j];
	}
}

// Przyspieszyć
void Naive(string s, string pat, int mode)
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
			psum[mode][i]++;
			psum[mode][i+j]--;
		}
	}
}

bool check(string s, int n, int m)
{	
	memset(A, 0, sizeof(A));

	// dla wierszy
	for (int i=0; i<n; i++)
	{
		string row = "";
		for (int j=0; j<m; j++)
			row += T[i][j];
		
		Naive(row, s, 0);

		int sum = 0;
		for (int j=0; j<m; j++)
		{
			sum += psum[0][j];
			A[i][j] += sum;
		}
	}

	// dla kolumn
	for (int j=0; j<m; j++)
	{
		string col = "";
		for (int i=0; i<n; i++)
			col += T[i][j];

		Naive(col, s, 1);

		int sum = 0;
		for (int i=0; i<n; i++)
		{
			sum += psum[1][i];
			A[i][j] += sum;
		}
	}
	
	// show(s, n, m);

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (A[i][j] == 0)
				return 0;

	return 1;
}

bool cmp(string a, string b)
{
	return a.size() > b.size();
}

vector<int> divs(int x)
{
	vector<int> res;
	for (int i=1; i*i<=x; i++)
		if (x % i == 0)
		{
			if (x / i == i)
				res.push_back(i);
			else
			{
				res.push_back(i);
				res.push_back(x/i);
			}
		}
	return res;
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

/*	for (auto g : Group)
	{
		cout << "P = " << g.FR << "\n";
		for (string p : g.SD)
			cout << p << "\n"; 
	}
*/
	vector<int> ans;
	vector<string> used;
	for (auto g : Group)
	{
		int P = g.FR;
		vector<string> candidates;
		for (string p : g.SD)
		{
			if (P == 1 && n % p.size() != 0 && m % p.size() != 0)
				continue;

			candidates.push_back(p);
		}

		sort(candidates.begin(), candidates.end(), cmp);

		// Przyspieszyć
		bool flag = 1;
		for (string u : used)
		{
			string sC = candidates.back();
			string pf = u.substr(0, sC.size()); 
			if (sC == pf)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			continue;

		int i = 0;
		while (i < candidates.size() && check(candidates[i], n, m) == 0)
			i++;

		if (i == candidates.size())
			continue;

		vector<bool> valid(candidates[0].size() + 1);
		
		if (P == 1)
		{
			for (int d : divs(n)) valid[d] = 1;
			for (int d : divs(m)) valid[d] = 1;
		}
		else
			for (int d : divs(candidates[i].size()))
				valid[d] = 1;
		
		if (P > 1)
		{
			string sC = candidates.back();
			if (valid[sC.size()] == 1)
				used.push_back(sC);
		}

		while (i < candidates.size())
		{
			// cout << check(candidates[i], n, m) << "\n";
			if (valid[candidates[i].size()] == 1)
				ans.push_back(candidates[i].size());
			i++;
		}
	}

	sort(ans.begin(), ans.end());
	
	cout << ans.size() << "\n";
	for (int p : ans)
		cout << p << " ";
	cout << "\n";
	
	return 0;
}