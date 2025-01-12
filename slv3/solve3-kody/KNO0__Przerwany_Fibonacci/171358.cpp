#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int fibs(int n)
{
	arr.push_back(n);
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibs(n-1) + fibs(n-2);
}

int main()
{
	int n, k;
	cin >> n >> k;

	fibs(n);

	for (int i=0; i<k; i++)
		cout<<arr[i]<<"\n";

	return 0;
}