#include <bits/stdc++.h>
using namespace std;

struct node
{
	node* Lson;
	node* Rson;
	int val;
};

bool find(int x, node* pos)
{
	if (pos == NULL)
		return 0;
	if (pos->val == x)
		return 1;

	if (pos->val > x)
		return find(x, pos->Lson);
	else return find(x, pos->Rson);
}

void add(int x, node* pos)
{
	if (pos->val > x)
	{
		if (pos->Lson == NULL)
		{
			pos->Lson = new node;
			pos->Lson->val = x;
		}
		else add(x, pos->Lson);
	}
	else
	{
		if (pos->Rson == NULL)
		{
			pos->Rson = new node;
			pos->Rson->val = x;
		}
		else add(x, pos->Rson);	
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	node* root = new node;
	int n, q, x; cin >> n >> q;
	for (int i=0; i<n; i++)
		cin >> x, add(x, root);
	while (q--)
	{
		cin >> x;
		cout << (find(x, root) ? "TAK\n" : "NIE\n");
	}

	/*
		Przykładowy input:
		4 5
		1 2 3 4
		1
		3
		5
		2
		100

		output:
		TAK
		TAK
		NIE
		TAK
		NIE
	*/

	return 0;
}