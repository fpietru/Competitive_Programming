/*
	Zadanie "Zagadka" z MPSŚPZ 2021 OPEN
*/
#include <bits/stdc++.h>
using namespace std;
#define FR first
#define SD second

// Wczytywanie
vector<vector<int>> getM()
{
	vector<vector<int>> res(4, vector<int>(4,0));
	for (int i=0; i<4; i++)
	{
		string s; cin >> s;
		for (int j=0; j<4; j++)
			res[i][j] = (s[j] == '#');
	}
	return res;
}

// Wypisywanie
void showM(vector<vector<int>> v)
{
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<4; j++)
			cout << (v[i][j] ? "#" : "+");
		cout << "\n";
	}
	cout << "\n";
}

// Koniunkcja
vector<vector<int>> ANDgate(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> res(4, vector<int>(4,0));
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			if (A[i][j] && B[i][j])
				res[i][j] = 1;
	return res;
}

// Alternatywa
vector<vector<int>> ORgate(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> res(4, vector<int>(4,0));
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			if (A[i][j] || B[i][j])
				res[i][j] = 1;
	return res;
}

// Różnica: aby ANS[i][j] = 1, to A[i][j] = 1 && B[i][j] = 0 
vector<vector<int>> DIFFgate(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> res(4, vector<int>(4,0));
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			if (A[i][j] && !B[i][j])
				res[i][j] = 1;
	return res;
}

// XOR
vector<vector<int>> XORgate(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> res(4, vector<int>(4,0));
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			if ((A[i][j] && !B[i][j]) || (!A[i][j] && B[i][j]))
				res[i][j] = 1;
	return res;
}

// Przesunięcie cykliczne o jeden w prawo
void PUSHgate(vector<vector<int>> &v)
{
	vector<vector<int>> p(4, vector<int>(4,0));
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			p[i][j] = v[i][(4+j-1)%4];

	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			v[i][j] = p[i][j];
}

// Rotacja o 90 stopni przeciwnie z ruchem wskazówk zegara
void ROTgate(vector<vector<int>> &v)
{
	vector<vector<int>> p(4, vector<int>(4,0));
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			p[3-j][i] = v[i][j];

	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			v[i][j] = p[i][j];
}

// Rotacja "Ramki" o 90 stopni przeciwnie, i "Wnętrza" zgodnie z ruchem wskazówek zegara 
void DROTgate(vector<vector<int>> &v)
{
	vector<vector<int>> p(4, vector<int>(4,0));
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
		{
			if (i == 0 || i == 3 || j == 0 || j == 3)
				p[3-j][i] = v[i][j];
			else
				p[i][j] = v[3-j][i];

		}

	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			v[i][j] = p[i][j];
}

// Podział na dwie macieże: 1 trafia do A, jeśli liczba rozpatrzonych jedynek jest parzysta, inaczej do B
pair<vector<vector<int>>, vector<vector<int>>> DIVgate(vector<vector<int>> v)
{
	vector<vector<int>> A(4, vector<int>(4,0));
	vector<vector<int>> B(4, vector<int>(4,0));
	int countpops = 0;
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			if (v[i][j])
			{
				if (countpops % 2 == 0)
					A[i][j] = 1;
				else B[i][j] = 1;
				countpops++;
			}
	return {A, B};
}

// Wymiana macierzy
void SWITCHgate(vector<vector<int>> &A, vector<vector<int>> &B)
{
	vector<vector<int>> C(4, vector<int>(4,0));
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			C[i][j] = A[i][j];

	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			A[i][j] = B[i][j];

	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			B[i][j] = C[i][j];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	vector<vector<int>> A = getM();
	vector<vector<int>> B = getM();
	vector<vector<int>> C = getM();
	vector<vector<int>> D = getM();
	vector<vector<int>> E = getM();
	vector<vector<int>> p1, p2, p3;

	A = DIFFgate(A, B);
	p1 = DIVgate(A).FR;
	p2 = DIVgate(A).SD;
	DROTgate(p1);
	PUSHgate(p2);
	A = ORgate(p1, p2);
	showM(A);

	PUSHgate(B);
	ROTgate(C);
	p1 = ANDgate(B, C);
	DROTgate(D);
	p3 = XORgate(D, E);
	SWITCHgate(p1, p3);
	showM(DIFFgate(p2, p1));
	
	showM(DIVgate(p3).FR);
	showM(DIVgate(p3).SD);

	return 0;
}