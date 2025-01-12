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

constexpr int MxN = 505;
constexpr int INF = 1e9;
int a[MxN];
bool jd[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
	{
		int x; cin >> x;
		a[x]++;
	}
	
	vector<int> bierki;
	bierki.push_back(-INF);
	for (int i=1; i<=500; i++)
		if (a[i] > 0) bierki.push_back(i);
	
	int m = bierki.size();
	
	int ans = 0;
	
	for (int i=1; i<=m-2; i++)
	{
		int low = i+2;
		int high = m;
		while (low < high)
		{
			int mid = (low + high) >> 1;
			if (2*bierki[i] >= bierki[mid])
				low = mid + 1;
			else high = mid;
		}
		low--;
		
		int ile = 0;
		for (int k=1; k<=low; k++)
			ile += a[bierki[k]];
		
		ans = max(ans, ile);
	}

	cout << ans << "\n";

    return 0;
}
