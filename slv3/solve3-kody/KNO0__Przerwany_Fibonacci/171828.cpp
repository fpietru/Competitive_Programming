#include <bits/stdc++.h>
using namespace std;


vector<int> steps;

int fibs(int n)
{
	steps.push_back(n);

	if (n > 1)
		return (fibs(n-1)+fibs(n-2));
	else if (n == 1)
		return 1;
	else
		return 0;
}

int main()
{
	int n, k; cin >> n >> k;
	int nth = fibs(n);

	for (int i=0; i<k; i++)
		cout<<steps[i]<<"\n";

	return 0;
}