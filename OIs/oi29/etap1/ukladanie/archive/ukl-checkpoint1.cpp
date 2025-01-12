/*
	Zadanie "Układanie Kart" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak
	Rozwiązanie Brutalne
*/
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

constexpr int MxF = 3628800;
int dp[MxF+10];
int n, MOD;

int F(int x)
{
	int res = 1;
	for (int i=1; i<=x; i++)
		res *= i;
	return res;
}

int getid(string P)
{
	int n = P.size();
	if (n == 1)
		return 0;
	int cs = 0;
	for (char p : P)
		if (p < P[0])
			cs++;

	return cs*F(n-1) + getid(P.substr(1, n-1));
}

int Func(string s)
{
	bool sorted = 1;
	for (int i=0; i<(int)s.size()-1; i++)
		if (s[i] > s[i+1])
		{
			sorted = 0;
			break;
		}

	if (sorted)
		return 0;

	int idx = getid(s);

	if (dp[idx] > 0)
		return dp[idx];

	char lookfor;
	if (s[0] == 'a') lookfor = 'a'+(n-1);
	else lookfor = s[0] - 1;

	int i;
	for (i=1; i<s.size(); i++)
		if (s[i] == lookfor)
			break;
	
	string ns = s;
	ns[0] = lookfor;
	for (int j=1; j<=i; j++)
		ns[j] = s[j-1];

	dp[idx] = (i + Func(ns)) % MOD;

	return dp[idx];
}

int main()
{
	auto start_time = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> MOD;

	string s = "";
	for (int i=0; i<n; i++)
		s += 'a'+i;

	dp[0] = 0;

	int ans = 0;
	while (next_permutation(s.begin(), s.end()))
	{
		int idx = getid(s);
		if (dp[idx] != 0)
			ans += dp[idx];
		else
			ans += Func(s);
	}
	
	cout << ans << "\n";

	auto end_time = chrono::high_resolution_clock::now();
	auto total_time = end_time - start_time;
	cout << total_time / chrono::milliseconds(1) << "\n";

	return 0;
}
