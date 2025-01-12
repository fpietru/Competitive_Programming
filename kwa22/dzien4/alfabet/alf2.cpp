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

constexpr int MxN = 505;
constexpr int MxL = 2e4+4; 
constexpr int m = 1e9+7, p = 31;
int h[MxN][MxL];
ll p_pow[MxL+10];
string s[MxN];
bool logic[MxN];
bool tozero[MxN];

int Hash(int a, int b, int i)
{
	return ((h[i][b] - ((ll)h[i][a-1] * p_pow[b-a+1])) % m + m) % m;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	p_pow[0] = 1;
	for (int i=1; i<=MxL; i++)
		p_pow[i] = ((ll)p_pow[i-1] * p) % m;
	
	int n, l; cin >> n >> l;
	
	if (n == 1)
	{
		cout << "1 1\n";
		return 0;
	}
	
	for (int i=1; i<=n; i++)
	{
		cin >> s[i];
		h[i][0] = 0;
		for (int j=1; j<=l; j++)
			h[i][j] = ((ll)h[i][j-1] * p + (s[i][j-1]-'a'+1)) % m;	
	}
	
	int Rend = -1;
	int Lstart = -1;
	
	// max pref
	int low = 1;
	int high = l;
	
	while (low < high)
	{
		int mid = (low + high) >> 1;
		set<int> st;
		for (int i=1; i<=n; i++)
			st.insert(Hash(1, mid, i));
		
		if ((int)st.size() == 1)
			low = mid+1;
		else
			high = mid;
	}
	
	Lstart = low;
	
	// max suff
	low = 0;
	high = l;
	
	while (low < high)
	{
		int mid = (low + high) >> 1;
		set<int> st;
		for (int i=1; i<=n; i++)
			st.insert(Hash(l-mid+1, l, i));
		
		if ((int)st.size() == 1)
			low = mid+1;
		else
			high = mid;
	}

	Rend = l-low+1;
	
	memset(logic, 1, sizeof(logic));
	
	for (int i=Lstart; i<=Rend; i++)
	{
		memset(tozero, 1, sizeof(tozero));
		for (char c='a'; c <= 'z'; c++)
		{
			vector<int> pos;
			for (int j=1; j<=n; j++)
			{
				if (s[j][i-1] == c)
					pos.push_back(j);
			}
			
			if ((int)pos.size() > 1)
			{
				for (auto k : pos)
					tozero[k] = 0;
			}
		}
		
		for (int j=1; j<=n; j++)
			if (tozero[j])
				logic[j] &= 0;
		
		int countones = 0;
		for (int j=1; j<=n; j++)
			countones += logic[j];
			
		if (countones == 0)
		{
			cout << i << " " << i << "\n";
			return 0;
		}
		else if (countones == 1)
		{
			cout << Lstart << " " << i << "\n";
			return 0;
		}
	}
	
	cout << Lstart << " " << Rend << "\n";

    return 0;
}











