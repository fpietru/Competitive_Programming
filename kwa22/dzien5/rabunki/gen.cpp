#include <bits/stdc++.h>
using namespace std;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

int rand(int a, int b)
{
	return a + rand() % (b-a+1);
}

map<int, bool> used;

int main(int argc, char* argv[])
{
	srand(atoi(argv[1]));
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n = rand(1, 8);
	cout << n << "\n";

	vector<int> vec[2];
		
	for (int j=0; j<2; j++)
	{
		for (int i=1; i<=n; i++)
		{
			int r = rand(0, 25);
			while (used[r] == 1)
				r = rand(0, 25);
			vec[j].push_back(r);
			used[r] = 1;
		}
		
		sort(vec[j].begin(), vec[j].end());
	}
	
	for (int i=0; i<2; i++)
	{
		for (auto p : vec[i])
			cout << p << " ";
		cout << "\n";	
	}
	
    return 0;
}
