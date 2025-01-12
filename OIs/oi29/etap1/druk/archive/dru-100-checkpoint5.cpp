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
int psum[MxN];
map<int, set<string>, greater<int>> Group;
int n, m;

void show(string &s)
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

vector<int> KMP(string &a, string &b)
{
	vector<int> res;
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
			res.push_back(i-j);
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
	return res;
}

void group_it(string &a, string &b)
{
	string s = a;
	s += "#";
	for (char c : b)
		s += c;

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

bool check(string &s)
{	
	memset(A, 0, sizeof(A));

	for (int i=0; i<n; i++)
	{
		string row = "";
		for (int j=0; j<m; j++)
			row += T[i][j];
		
		memset(psum, 0, sizeof(psum));
		
		for (int p : KMP(row, s))
		{
			psum[p]++;
			psum[p+s.size()]--;
		}

		int sum = 0;
		for (int j=0; j<m; j++)
		{
			sum += psum[j];
			A[i][j] += sum;
		}
	}

	for (int j=0; j<m; j++)
	{
		string col = "";
		for (int i=0; i<n; i++)
			col += T[i][j];

		memset(psum, 0, sizeof(psum));

		for (int p : KMP(col, s))
		{
			psum[p]++;
			psum[p+s.size()]--;
		}

		int sum = 0;
		for (int i=0; i<n; i++)
		{
			sum += psum[i];
			A[i][j] += sum;
		}
	}

	// show(s);

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

	string row1 = "", row2 = "";
	string col1 = "", col2 = "";

	for (int i=0; i<m; i++) row1 += T[0][i];
	for (int i=0; i<m; i++) row2 += T[n-1][i];
	for (int i=0; i<n; i++) col1 += T[i][0];
	for (int i=0; i<n; i++) col2 += T[i][m-1];

	group_it(row1, row2);
	group_it(col1, col2);
	group_it(row1, col2);
	group_it(col1, row2);

/*	for (auto g : Group)
	{
		cout << "P = " << g.FR << "\n";
		for (string p : g.SD)
			cout << p << "\n"; 
	}*/

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

			if (p.size() == P)
			{
				bool f1 = KMP(row1, p).size() * p.size() <= m;
				bool f2 = KMP(row2, p).size() * p.size() <= m;
				bool f3 = KMP(col1, p).size() * p.size() <= n; 
				bool f4 = KMP(col2, p).size() * p.size() <= n;
	
				// cout << p.size() << " " << KMP(row1, p).size() * p.size() << "\n";

				if ((n % p.size() == 0 && (f1 && f2)) || (m % p.size() == 0) && (f3 && f4))
					starters.push_back({p, i});
			}
			else if (n % p.size() == 0 || m % p.size() == 0)
				starters.push_back({p, i});

			i++;
		}

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