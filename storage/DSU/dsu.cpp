/*
	Implementacja DSU ze skracaniem scieżek i łączeniem "mały do dużego"
	Złożoność Czasowa: O(odwrotna_funkcja_akermana(n) [prawie O(1)]) (ale wtedy, kiedy są 2 optymalizacje)
	Źródło: https://cp-algorithms.com/data_structures/disjoint_set_union.html#toc-tgt-2
*/
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int parent;
	int set_size;
};

const int MxN = 1e3+3;
node arr[MxN];

void make_set(int v)
{
	arr[v].parent = v;
	arr[v].set_size = 1;
}

int find_set(int v)
{
	if (arr[v].parent == v)
		return v;
	return arr[v].parent = find_set(arr[v].parent);
}

void union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if (a != b)
	{
		if (arr[a].set_size < arr[b].set_size)
			swap(a, b);
		arr[b].parent = a;
		arr[a].set_size += arr[b].set_size;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	return 0;
}
