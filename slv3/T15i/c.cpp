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

constexpr int MxN = 2e5+5;
string s[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> biore;
	for (int i=1; i<=n; i++)
	{
		cin >> s[i];
		biore.push_back(i);
	}
	
	for (int i=0; i<m; i++)
	{
		vector<int> nowe_biore;
		for (auto p : biore)
			if (s[p][i] == '1')
				nowe_biore.push_back(p);
		
		if ((int)nowe_biore.size() >= k)
			biore = nowe_biore;

		if ((int)biore.size() == k)
			break;
	}
	
	for (int i=0; i<k; i++)
		cout << biore[i] << " ";
	cout << "\n";

    return 0;
}
