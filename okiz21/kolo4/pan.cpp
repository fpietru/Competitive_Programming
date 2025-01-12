#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	queue<string> qu;
	for (int i=0; i<n; i++)
	{
		string op; cin >> op;
		if (op == "nowy")
		{
			string name; cin >> name;
			qu.push(name);
		}
		if (op == "zawolaj")
		{
			cout << qu.front() << "\n";
			qu.pop();
		}
		if (op == "ile")
		{
			cout << qu.size() << "\n";
		}
	}
	
	return 0;
}