/*
	Zadanie "Trójkąt" z VIII OIG
*/
#include <bits/stdc++.h>
#define FR first
#define SD second
using ll = long long;
using namespace std;

pair<int, int> p[3], vec[3];

ll iv(pair<int, int> A, pair<int, int> B)
{
	return ((ll)A.FR*B.SD - (ll)B.FR*A.SD);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i=0; i<3; i++)
		cin >> p[i].FR >> p[i].SD;

	for (int i=0; i<3; i++)
		vec[i] = {p[(i+1)%3].FR - p[i].FR, p[(i+1)%3].SD - p[i].SD};

	bool ans = 1;
	for (int i=0; i<3; i++)
	 	if (iv(vec[i], vec[(i+1)%3]) > 0)
	 	{
	 		ans = 0;
	 		break;
	 	}

	cout << (ans ? "ZGODNIE\n" : "PRZECIWNIE\n");

	return 0;
}