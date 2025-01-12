#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 5e5+10;
constexpr int MxB = 22;
string w[MxN];
int l[MxN];
int dp[(1<<MxB)+10];
int id[26];
bool vis[26];

string show(int x)
{
	string res = "";
	while (x)
	{
		res += to_string(x&1);
		x >>= 1;
	}
	reverse(res.begin(), res.end());
	return res;
}

int flip(int x, int k) {
	return (~x)&((1<<k)-1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	memset(id, -1, sizeof(id));
	memset(dp, -1, sizeof(dp));
	
	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> w[i];
		for (int j=0; j<(int)w[i].size(); j++)
			vis[w[i][j]-'a'] = 1;
	}
	
	int licznik = 0;
	for (int i=0; i<26; i++)
		if (vis[i])
			id[i] = licznik++;
	
	for (int i=1; i<=n; i++)	
		for (int j=0; j<(int)w[i].size(); j++)
			l[i] |= (1<<(id[w[i][j]-'a']));
	
	for (int i=1; i<=n; i++)
		dp[l[i]] = i;
	
	for (int maska=1; maska<(1<<MxB); maska++)
		if (dp[maska] != -1)
			for (int i=0; i<MxB; i++)
				if ((maska & (1 << i)) == 0)
					dp[maska | (1 << i)] = dp[maska];

	for (int i=1; i<=n; i++)
	{
		if (int ans = dp[flip(l[i], MxB)]; ans != -1)
			cout << w[ans] << "\n";
		else
			cout << "NIE\n";
	}
	
    return 0;
}
