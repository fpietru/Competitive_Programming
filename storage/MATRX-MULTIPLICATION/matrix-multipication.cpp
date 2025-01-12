/*
	Potęgowanie macierzy
	Złożoność czasowa: O(n^3)
*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B)
{
	vector<vector<int>> C = {{0,0},{0,0}};
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			for (int k=0; k<2; k++)
				C[i][j] += A[i][k] * B[k][j];
	return C;
}

vector<vector<int>> getmatrix()
{
	int n, m; cin >> n >> m;
	vector<vector<int>> V(n, vector<int>(m));
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> V[i][j];
	return V;
}

void show(vector<vector<int>> V)
{
	for (int i=0; i<V.size(); i++)
	{
		for (int j=0; j<V[0].size(); j++)
			printf("%d ", V[i][j]);
		printf("\n");
	}
}

int main()
{
	vector<vector<int>> A = getmatrix();
	vector<vector<int>> B = getmatrix();
	vector<vector<int>> C = multiply(A,B);
	show(C);
	
	return 0;
}
