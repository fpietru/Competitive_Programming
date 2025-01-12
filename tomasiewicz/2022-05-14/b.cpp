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

/*
	Zadanie: https://codeforces.com/problemset/problem/1486/D
	
	1) binsearch po medianie [M]
	2) Sprawdzanie, czy istnieje fragment o długości >= k, który ma mediane = M
		a) zetykietować elementy
			1, gdy a[i] >= M
			-1, gdy a[i] < M
		b) na otrzymanym ciągu zrobić sumy prefiksowe
		c) teraz w forze idziemy początkiem [pocz], i końca [kon] szukamy jako min([1, 2, 3, ... kon) i jeśli p[pocz] - p[kon] > 0, zatem będzie ponad połowa 1, więc mediana w tym fragmencie jest na pewno >= M;
*/

constexpr int MxN = 2e5+5;
int a[MxN], p[MxN], mi[MxN];
int n, k;

bool check(int M)
{
	memset(p, 0, sizeof(0));
	for (int i=1; i<=n; i++)
		p[i] = p[i-1] + (a[i] >= M ? 1 : -1);
	
	for (int i=1; i<=n; i++)
		mi[i] = min(mi[i-1], p[i]);
	
	for (int i=1; i<=n; i++)
	{
		int j = i - k + 1;
		if (j < 1) continue;
		else if (p[i] - mi[j-1] > 0)
			return 1;
	}
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	
	int low = 1;
	int high = MxN;
	while (low < high)
	{
		int mid = (low + high) >> 1;
		if (check(mid) == 1)
			low = mid + 1;
		else high = mid;
	}
	
	cout << low - 1 << "\n";

    return 0;
}
