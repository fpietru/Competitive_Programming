#include <bits/stdc++.h>
using namespace std;

constexpr int MxN = 1e6+6
struct Punkt
{
	int x, y, t, id;
};
vector<Punkt> Punkty;
vector<int> Graf[MxN];
int activeY[MxN];
int activeX[MxN];

bool cmp(Punkt A, Punkt B)
{
	if (A.x == B.x)
		return A.y >= B.y;
		
	return A.x < B.x;
}

void stworzGraf()
{
	int n = Punkty.size();
	for (int i=0; i<n; i++)
	{
		int j = i-1;
		Punkt P = Punkty[i];
		
		
		
		
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int W, H, n; cin >> W >> H >> n;
	for (int i=1; i<=n; i++)
	{
		Punkt A, B, C, D;
		cin >> A.x >> A.y >> B.x >> B.y;
		if (A.x > B.x)
			swap(A, B);
			
		A.id = B.id = i;
		
		// A jest lewym górnym rogiem, B prawym dolnym
		if (A.y > B.y)
		{
			A.t = 1, B.t = 4;
			C = {A.x, B.y, 2, i};
			D = {B.x, A.y, 3, i};
		}
		else // na odwrót
		{
			A.t = 2, B.t = 3;
			C = {A.x, B.y, 1, i};
			D = {B.x, A.y, 4, i};
		}
		Punkty.push_back(A);
		Punkty.push_back(B);
		Punkty.push_back(C);
		Punkty.push_back(D);
	}

	sort(Punkty.begin(), Punkty.end(), cmp);
	
	//for (auto P : Punkty)
	//	cout << "(" << P.x << "," << P.y << ") " << P.id << " " << P.t << "\n";	
	
	stworzGraf();
	
	return 0;
}
