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

ll ways[100], dp[22];

/*
	ways[x] = ile jest takich uporządkowanych par (a, b), gdzie 0 <= a,b <= 9 oraz a+b = x
				x+1, dla 0 <= x <= 9
				19-x, dla 10 <= x <= 18
				0, dla 19 <= x <= +INF

	dp[x] = na ile sposobów można utworzyć liczbę x-cyfrową, zgodnie z poleceniem
*/

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i=0; i<=9; i++)
		for (int j=0; j<=9; j++)
			ways[i+j]++;			

	string s; cin >> s;
	s = "00" + s; // przesunięcie, żeby było łatwiej w przejściach
	dp[1] = 1LL; // bo ostatecznym wynikiem będzie 1 * ways[s[i]]
	
	for (int i=2; i<(int)s.size(); i++)
		dp[i] = dp[i-1] * ways[s[i]-'0'] + (s[i-1] != '0' ? dp[i-2] * ways[(s[i-1]-'0')*10 + (s[i]-'0')] : 0);
	
	cout << dp[s.size()-1] << "\n";
 
    return 0;
}
