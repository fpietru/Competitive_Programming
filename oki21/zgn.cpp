/*
	Zadanie "Zgniłe jabłko" z OKI
*/
#include <bits/stdc++.h>
using namespace std;

int modulo(string s, int a)
{
	int res = 0;
	for (int i=0; i<s.size(); i++)
		res = (res*10 + s[i]-'0') % a;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s, k;
	cin >> s >> k;

	int r = modulo(k, s.size());

	reverse(s.begin(), s.begin()+r);
	reverse(s.begin()+r, s.end());
	reverse(s.begin(), s.end());
	
	cout << s << "\n";

	return 0;
}