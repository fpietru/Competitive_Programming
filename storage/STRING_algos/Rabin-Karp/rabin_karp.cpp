/*
	Zliczanie liczby wystąpień wzorca w tekście
	Algorytm Rabina-Karpa
	https://cses.fi/problemset/task/1753/
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int m = 1e9+7;
constexpr int p = 31;
constexpr int MxN = 1e6;
int p_pow[MxN+10];
int h[MxN+10];

int Hash(int a, int b)
{
	return ((h[b] - ((ll)h[a-1] * p_pow[b-a+1])) % m + m) % m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	p_pow[0] = 1;
	for (int i=1; i<=MxN; i++)
		p_pow[i] = ((ll)p_pow[i-1] * p) % m;
	
	string text, pattern;
	cin >> text >> pattern;
	int ts = text.size();
	int ps = pattern.size();
	
	h[0] = 0;
	for (int i=1; i<=ts; i++)
		h[i] = ((ll)h[i-1] * p + (text[i-1]-'a'+1)) % m;

	int pattern_hash = 0;
	for (int i=1; i<=ps; i++)
		pattern_hash = ((ll)pattern_hash * p + (pattern[i-1]-'a'+1)) % m;
	
	int ans = 0;
	for (int i=1; i<=ts-ps+1; i++)
		if (Hash(i, i+ps-1) == pattern_hash)
			ans++;

	cout << ans << "\n";
	
	return 0;
}
