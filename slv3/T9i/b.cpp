#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

pii topair(string s)
{
	int h = (s[0]-'0')*10+(s[1]-'0');
	int m = (s[3]-'0')*10+(s[4]-'0');
	return {h, m};
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string a, b, c;
	cin >> a >> b >> c;

	pii A, B, C;

	A = topair(a);
	B = topair(b);
	C = topair(c);
	
	if (A < C && C < B)
		cout << "TAK\n";
	else
		cout << "NIE\n";

	return 0;
}