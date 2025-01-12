#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b; cin >> a >> b;

	bool icecream = (a+b >= 15 && b >= 8);
	bool icemilk = (a+b >= 10 && b >= 3 && !icemilk);
	bool lactoice = (a+b >= 3 && !icemilk && !icecream);
	bool flavored = (!icecream && !icemilk && !lactoice);

	if (icecream)
	{
		cout << "1\n";
		return 0;
	} 

	if (icemilk)
	{
		cout << "2\n";
		return 0;
	} 

	if (lactoice)
	{
		cout << "3\n";
		return 0;
	} 

	if (flavored)
	{
		cout << "4\n";
		return 0;
	} 

	return 0;
}