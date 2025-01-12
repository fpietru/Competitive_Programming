/*
	Zadanie "Karty" z XXI OI, etap II
*/
#include <bits/stdc++.h>
using namespace std;

constexpr int base = (1<<18);
constexpr int MxN = 2e5+62155;
bool Tree[2*base][4];
int A[MxN], B[MxN];
int idx[2*base];

void merge(int v)
{
	int l = 2*v;
	int r = 2*v+1;
	
	Tree[v][0] = ((Tree[l][0] && Tree[r][0] && A[idx[l]] <= A[idx[r]]) ||
				  (Tree[l][0] && Tree[r][2] && A[idx[l]] <= B[idx[r]]) ||
				  (Tree[l][1] && Tree[r][0] && B[idx[l]] <= A[idx[r]]) ||
				  (Tree[l][1] && Tree[r][2] && B[idx[l]] <= B[idx[r]]));

	Tree[v][1] = ((Tree[l][0] && Tree[r][1] && A[idx[l]] <= A[idx[r]]) ||
				  (Tree[l][0] && Tree[r][3] && A[idx[l]] <= B[idx[r]]) ||
				  (Tree[l][1] && Tree[r][1] && B[idx[l]] <= A[idx[r]]) ||
				  (Tree[l][1] && Tree[r][3] && B[idx[l]] <= B[idx[r]]));
	
	Tree[v][2] = ((Tree[l][2] && Tree[r][2] && A[idx[l]] <= B[idx[r]]) ||
				  (Tree[l][2] && Tree[r][0] && A[idx[l]] <= A[idx[r]]) ||
	              (Tree[l][3] && Tree[r][2] && B[idx[l]] <= B[idx[r]]) ||
				  (Tree[l][3] && Tree[r][0] && B[idx[l]] <= A[idx[r]]));

	Tree[v][3] = ((Tree[l][3] && Tree[r][3] && B[idx[l]] <= B[idx[r]]) ||
				  (Tree[l][3] && Tree[r][1] && B[idx[l]] <= A[idx[r]]) ||
				  (Tree[l][2] && Tree[r][1] && A[idx[l]] <= A[idx[r]]) ||
				  (Tree[l][2] && Tree[r][3] && A[idx[l]] <= B[idx[r]]));
}

void mergeleafs(int v)
{
	int l = 2*v;
	int r = 2*v+1;
	
	Tree[v][0] = (A[idx[l]] <= A[idx[r]]);
	Tree[v][1] = (A[idx[l]] <= B[idx[r]]);
	Tree[v][2] = (B[idx[l]] <= A[idx[r]]);
	Tree[v][3] = (B[idx[l]] <= B[idx[r]]);
}

void setidx(int v, int lw, int rw)
{
	if (v % 2 == 0)
		idx[v] = rw;
	else
		idx[v] = lw;
	
	if (v >= base)
		return;
	
	int mid = (lw + rw) >> 1;
	setidx(2*v, lw, mid);
	setidx(2*v+1, mid+1, rw);
}

void update(int v)
{
	v += base;
	v /= 2;
	mergeleafs(v);
	
	while (v)
	{
		v /= 2;
		merge(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	memset(Tree, 1, sizeof(Tree));
	memset(A, 0x3f3f3f3f, sizeof(A));
	memset(B, 0x3f3f3f3f, sizeof(B));
	
	int n; cin >> n;
	for (int i=0; i<n; i++)
		cin >> A[i] >> B[i];
	
	setidx(1, 0, base-1);
	
	for (int i=base-1; i>=1; i--)
	{
		if (2*i >= base) mergeleafs(i);
		else merge(i);
	}
	
	int q; cin >> q;
	while (q--)
	{
		int a, b; cin >> a >> b;
		a--, b--;
		swap(A[a], A[b]);
		swap(B[a], B[b]);
		
		update(a);
		update(b);
		
		bool ans = 0;		
		for (int i=0; i<4; i++)
			ans |= Tree[1][i];
		
		cout << (ans ? "TAK\n" : "NIE\n");
	}

	return 0;
}
