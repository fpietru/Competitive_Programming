#include <bits/stdc++.h>
using namespace std;

constexpr int base = (1<<20);
int Tree[2*base];

void add(int v, int val)
{
	v += base;

	while (v)
	{
		Tree[v] += val;
		v >>= 1;
	}
}

int kty(int k)
{
	int v = 1;
	while (v < base)
	{
		int L = 2*v;
		int R = 2*v+1;
	
		deb(v, k);
		if (k <= Tree[L])
			v = L;
		else
		{
			v = R;
			k -= Tree[L];
		}
	}
	return v - base;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	/*
		0 1 2 3 ... base-1 = zakres elementów
		
		add = dodaje/usuwa element (zależy od podania krotności)
		kty = znajduje k-ty najmniejszy element
	*/

    return 0;
}
