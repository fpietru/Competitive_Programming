#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << "[ ";
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
    cout << " ]\n";
}

constexpr int MxN = 5e5+5;
int P[MxN];
int B[MxN];
bool used[MxN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i=1; i<=n; i++)
		cin >> P[i];
	for (int i=1; i<=n; i++)
		cin >> B[i];
		
	if (n > 8)
	{
		ll ans = 0LL;
		for (int i=1, j=n; i<=n; i++, j--)
			ans += (ll)(B[i] - P[j]);
			
		cout << ans << "\n";
		for (int i=1; i<=n; i++)
			cout << i << " ";
		cout << "\n";
		
		return 0;
	}	
		
	vector<int> perm;
	for (int i=1; i<=n; i++)
		perm.push_back(i);
	
	ll best_ans = 1e18+9;
	vector<int> kolejnosc;
	
	do {
		ll ans = 0LL;
		memset(used, 0, sizeof(used));
		for (int i=1; i<=n; i++)
		{
			int who = -1;
			int dst = 1e9+7;
			for (int j=1; j<=n; j++)
			{
				if (used[j] == 0 && abs(B[perm[i-1]] - P[j]) < dst)
				{
					dst = abs(B[perm[i-1]] - P[j]);
					who = j;
				}
			}
			
			used[who] = 1;
			ans += (ll)dst;
		}
		
		if (ans < best_ans)
		{
			best_ans = ans;
			kolejnosc = perm;
		}
		
	} while (next_permutation(perm.begin(), perm.end()));

	cout << best_ans << "\n";
	for (auto p : kolejnosc)
		cout << p << " ";
	cout << "\n";

    return 0;
}
















