#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

 	int a, b, c; cin >> a >> b >> c;


 	if (c % 2 == 0)
 	{
 		a = abs(a);
 		b = abs(b);
 		if (a > b) cout << ">\n";
 		else if (a < b) cout << "<\n";
 		else cout << "=\n";
 	}
 	else
 	{
 	 	if (a > b) cout << ">\n";
 		else if (a < b) cout << "<\n";
 		else cout << "=\n";	
 	}
	
	return 0;
}