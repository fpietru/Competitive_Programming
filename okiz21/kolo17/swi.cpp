/*
	Zadanie "Światłowód"
*/
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define FR first
#define SD second
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 1e5+5;
pii a[MxN];
int n;

bool check(int i)
{
	int klamcy = 0;
	if (a[i] == make_pair(0,1))
		klamcy++;
	
	if (i != n)
	{
		if (a[i+1] == make_pair(1,1) || a[i+1] == make_pair(0,0))
			return 0;
		if (a[i+1] == make_pair(1,0))
			klamcy++;
		for (int j=i+2; j<=n; j++)
		{
			if (a[j] == make_pair(0,1) || a[j] == make_pair(1,0))
				return 0;
			if (a[j] == make_pair(1,1))
				klamcy++;
		}
	}
	
	if (i != 1)
	{
		if (a[i-1] == make_pair(1,1) || a[i-1] == make_pair(0,0))
			return 0;
		if (a[i-1] == make_pair(1,0))
			klamcy++;
		for (int j=i-2; j>=1; j--)
		{
			if (a[j] == make_pair(0,1) || a[j] == make_pair(1,0))
				return 0;
			if (a[j] == make_pair(1,1))
				klamcy++;
		}
	}
		
	if (2*klamcy != n)
		return 0;
	
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i].FR;
	for (int i=1; i<=n; i++)
		cin >> a[i].SD;

	for (int i=1; i<=n; i++)
		if ((a[i] == make_pair(1,0) || a[i] == make_pair(0,1)) && check(i))
		{
			cout << i << "\n";
			return 0;
		}

	cout << "OGNIA\n"; // xddd
    return 0;
}
