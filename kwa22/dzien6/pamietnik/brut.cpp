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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string p, s; cin >> p >> s;
	
	int n = p.size();
	int m = s.size();
	
	int best_ans = 1e9+7;
	
	for (int i=0; i<=m-n; i++)
	{
		// deb(i);
		int curr_ans = 0;
		for (int j=0; j<n; j++)
		{
			if (s[i+j] != p[j])
				curr_ans++;
			// deb(p[j], s[i+j], curr_ans);
		}
		best_ans = min(best_ans, curr_ans); 
	}
	
	cout << best_ans << "\n";

    return 0;
}
