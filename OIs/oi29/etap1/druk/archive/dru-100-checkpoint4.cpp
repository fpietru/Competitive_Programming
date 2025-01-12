/*
	Zadanie "Druk" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak
*/
#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

constexpr int MxN = 1e3+13;
char T[MxN][MxN];
int A[MxN][MxN];
int psum[2][MxN];
map<int, set<string>, greater<int>> Group;
int n, m;

vector<int> gen_lps(string &s)
{
	int N = s.size();
	vector<int> lps(N, 0);
	for (int i=1; i<N; i++)
	{
		int j = lps[i-1];
		while (j > 0 && s[i] != s[j])
			j = lps[j-1];
		if (s[i] == s[j])
			j++;
		lps[i] = j;
	}
	return lps;
}

int Per(string &s)
{
	int res = 0;
	int N = s.size();
	for (int k=1; k<=N; k++)
	{
		int i = k;
		string candidate = s.substr(0, k);
		for (; i<N; i+=k)
			if (s.substr(i, k) != candidate)
				break;
		if (i == N)
		{
			res = k;
			break;
		}
	}
	return res;
}

void group_it(string &s)
{
	vector<int> lps = gen_lps(s);

	int i = s.size()-1;
	while (lps[i])
	{
		string res = s.substr(0, lps[i]);
		int P = Per(res);
		if (P != 1 || (n % res.size() == 0 || m % res.size() == 0))
			Group[P].insert(res);
		
		i = lps[i] - 1;
	}
}

void KMP(string &a, string &b, int mode)
{
	memset(psum, 0, sizeof(psum));
	vector<int> lps = gen_lps(b);
	int N = a.size();
	int M = b.size();
	int i = 0, j = 0;
	while (i < N)
	{
		if (b[j] == a[i])
			j++, i++;

		if (j == M)
		{
			psum[mode][i-j]++;
			psum[mode][i]--;
			j = lps[j-1];
		}
		else if (i < N && b[j] != a[i])
		{
			if (j != 0)
				j = lps[j-1];
			else
				i++;
		}
	}
}

bool check(string &s)
{	
	memset(A, 0, sizeof(A));

	for (int i=0; i<n; i++)
	{
		string row = "";
		for (int j=0; j<m; j++)
			row += T[i][j];
		
		if (s.size() <= row.size())
			KMP(row, s, 0);

		int sum = 0;
		for (int j=0; j<m; j++)
		{
			sum += psum[0][j];
			A[i][j] += sum;
		}
	}

	for (int j=0; j<m; j++)
	{
		string col = "";
		for (int i=0; i<n; i++)
			col += T[i][j];

		if (s.size() <= col.size())
			KMP(col, s, 1);

		int sum = 0;
		for (int i=0; i<n; i++)
		{
			sum += psum[1][i];
			A[i][j] += sum;
		}
	}

	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			if (A[i][j] == 0)
				return 0;

	return 1;
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

	cin >> n >> m;
	for (int i=0; i<n; i++)
	{
		string s; cin >> s;
		for (int j=0; j<m; j++)
			T[i][j] = s[j];
	}

	string s1 = "", s2 = "", s3 = "", s4 = "";
	for (int i=0; i<m; i++) s1 += T[0][i];
	s1 += "#";
	for (int i=0; i<m; i++) s1 += T[n-1][i];

	for (int i=0; i<n; i++) s2 += T[i][0];
	s2 += "#";
	for (int i=0; i<n; i++) s2 += T[i][m-1];

	for (int i=0; i<m; i++) s3 += T[0][i];
	s3 += "#";
	for (int i=0; i<n; i++) s3 += T[i][m-1];

	for (int i=0; i<n; i++) s4 += T[i][0];
	s4 += "#";
	for (int i=0; i<m; i++) s4 += T[n-1][i];

	group_it(s1);
	group_it(s2);
	group_it(s3);
	group_it(s4);

	vector<int> ans;
	vector<string> used;
	for (auto g : Group)
	{
		int P = g.FR;
		vector<string> candidates;
		vector<pair<string, int>> starters;
		int i = 0;
		for (string p : g.SD)
		{
			candidates.push_back(p);
			if (n % p.size() == 0 || m % p.size() == 0)
				starters.push_back({p, i});
			i++;
		}

		// Przyspieszyć
		bool flag = 1;
		for (string u : used)
		{
			string sC = candidates.front();
			string pf = u.substr(0, sC.size()); 
			if (sC == pf)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 0)
			continue;

		i = starters.size()-1;
		while (i >= 0 && check(starters[i].FR) == 0)
			i--;

		if (i == -1)
			continue;

		i = starters[i].SD;

		if (P == 1)
			for (int j=i; j>=0; j--)
				ans.push_back(candidates[j].size());
		else
		{
			vector<bool> valid(candidates[i].size() + 1, 0);
			for (int d : divs(candidates[i].size()))
				valid[d] = 1;
			
			string sC = candidates.front();
			if (valid[sC.size()] == 1)
				used.push_back(sC);
			
			while (i >= 0)
			{
				if (valid[candidates[i].size()] == 1)
					ans.push_back(candidates[i].size());
				i--;
			}
		}
	}

	sort(ans.begin(), ans.end());
	
	cout << ans.size() << "\n";
	for (int p : ans)
		cout << p << " ";
	cout << "\n";
	
	return 0;
}