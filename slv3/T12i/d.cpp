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

string solve()
{
	int k; cin >> k;
	string s; cin >> s;
	
	int n = s.size();
	
	int liczbab = 0;
	for (int i=0; i<n; i++)
		if (s[i] == 'b')
			liczbab++;

	if (k >= n)
		return "";

	if (liczbab <= k)
	{
		for (int i=0; i<n; i++)
			if (s[i] == 'b')
			{
				s[i] = '#';
				k--;
			}
	} 
	
	int pocz = -1;
	int seg = 0;
	for (int i=0; i<n; i++)
	{
		if (s[i] == 'b')
		{
			if (pocz == -1)
				pocz = i;
			seg++;
		}
		else 
		{
			// deb(i, seg, pocz);
			if (seg > 0)
			{
				if (k >= seg)
				{
					k -= seg;
					for (int j=pocz; j<=i-1; j++)
						s[j] = 'a';
				}
				else
				{
					for (int j=pocz; j<=i-1; j++)
						if (k > 0)
						{
							s[j] = 'a';
							k--;
						}
				}
			}
			seg = 0;
			pocz = -1;
		}
	}
	
	if (seg > 0)
	{
		if (k >= seg)
		{
			k -= seg;
			for (int j=pocz; j<n; j++)
				s[j] = '#';
		}
		else
		{
			for (int j=pocz; j<n; j++)
				if (k > 0)
				{
					s[j] = 'a';
					k--;
				}
		}
	}
	
	for (int i=0; i<n; i++)
		if (k > 0 && s[i] != '#')
		{
			s[i] = '#';
			k--;
		}
	
	string ans = "";
	for (int i=0; i<n; i++)
		if (s[i] != '#')
			ans += s[i];
	
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
		cout << solve() << "\n";

    return 0;
}
