#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	vector<int> a(4);
	for (int i=0; i<4; i++)
		cin >> a[i];
		
	bool flag = 0;
	for (int i=0; i<3; i++)
		if (a[i] == a[i+1])
			flag = 1;

	cout << (flag ? "TAK\n" : "NIE\n");
	
	return 0;
}
