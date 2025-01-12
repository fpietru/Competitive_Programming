#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b;
	char o;
	cin >> a >> o >> b;
	if (o == '+')
		cout << a + b << "\n";
	else
		cout << a - b << "\n";
	
	return 0;
}