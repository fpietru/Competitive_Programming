#include <bits/stdc++.h>
using namespace std;

class Tree // Drzewo Licznikowe
{
private:
	int *tree, leaf_size;
public:
	Tree(int base) // Konstruktor, tworzymy i zapełniamy drzewo zerami
	{
		leaf_size = 1 << base;
		tree = new int[2*leaf_size];
		for (int i=0; i<2*leaf_size; i++)
			tree[i] = 0;
	}

	~Tree() // Destruktor, zwalnia pamięć
	{ delete[] tree; }

	void showtree() // Wyświetla wszytkie węzły drzewa
	{
		for (int i=1; i<2*leaf_size; i++)
		{
			if (ceil(log2(i)) == floor(log2(i)))
				cout << "\n";
			cout << tree[i] << " ";
		}
		cout << "\n";
	}

	void insert(int v, int q) // Dodaje element "v" w ilości "q"
	{
		v += leaf_size;

		while (v > 0)
		{
			tree[v] += q;
			v >>= 1;
		}
	}

	void del(int v) // Usuwa element "v"
	{ insert(v, -countequal(v)); }

	int getkth(int k) // Znajduje k-ty najmniejszy element
	{
		int v = 1;
		while (v < leaf_size)
		{
			v *= 2;
			if (k >= tree[v])
			{
				k -= tree[v];
				v++;
			}
		}
		return v - leaf_size;
	}

	int countequal(int v) // Zwraca ilość elementów równych danemu elementowi "v"
	{ return tree[v+leaf_size]; }

	int countsmaller(int v) // Zwraca ilość elementów mniejszych od "v"
	{
		v += leaf_size;
		int res = 0;

		while (v > 0)
		{
			if (v&1 == 1)
				res += tree[v-1];
			v >>= 1;
		}
		return res;
	}

	int countsmallerANDequal(int v) // Zwraca ilość elementów mniejszych-równych "v"
	{ return countsmaller(v) + countequal(v); }

	int countgreater(int v) // Zwraca ilość elementów większych od "v"
	{ return tree[1] - countsmallerANDequal(v); }

	int countgreaterANDequal(int v) // Zwraca ilość elementów większych-równych "v"
	{ return tree[1] - countsmaller(v); }

	int countinsegment(int a, int b) // Zwraca ilość elementów należących do przedziału [a,b]
	{ return countsmaller(b+1) - countsmaller(a); }

	int FRright(int v) // Znajduje perwszy na prawo element od "v"
	{ return getkth(countsmaller(v)+countequal(v)); }

	int FRleft(int v) // Znajduje perwszy na lewo element od "v"
	{ return getkth(countsmaller(v)-1); }

};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	Tree tree(5);
	string s; cin >> s;

	for (int i=0; i<s.size(); i++)
		tree.insert(s[i]-97, 1);

	tree.showtree();

	// printf("%d\n", tree.countequal('b'-97));
	// printf("%d\n", tree.countsmallerrr('h'-97));
	// printf("%d\n", tree.countinsegment('a'-97, 'f'-97));

	// printf("%c\n", tree.FRleft('f'-97)+97);
	// printf("%c\n", tree.getkth(3)+97);

	return 0;
}