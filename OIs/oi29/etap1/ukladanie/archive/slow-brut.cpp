/*
	Zadanie "Układanie Kart" z XXIX OI, etap I
	Autor rozwiązania: Franek Pietrusiak
	Rozwiązanie Brutalne
*/
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

map<string, int> mp;
int n, MOD;

int Func(string s)
{
	int total_cost = 0;
	string unchanged = s;
	while (!is_sorted(s.begin(), s.end()))
	{
		char lookfor;
		if (s[0] == 'a') lookfor = 'a'+(n-1);
		else lookfor = s[0] - 1;

		int i;
		for (i=1; i<s.size(); i++)
			if (s[i] == lookfor)
				break;
		
		rotate(s.begin(), s.begin()+i, s.begin()+i+1);
		total_cost = (total_cost + i) % MOD;

		if (mp[s] > 0)
		{
			total_cost = (total_cost + mp[s]) % MOD;
			break;
		}
	}

	mp[unchanged] = total_cost % MOD;
	return total_cost;
}

int main()
{
	// auto start_time = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> MOD;

	string s = "";
	for (int i=0; i<n; i++)
		s += 'a'+i;

	int total_cost = 0;
	do {
		total_cost += Func(s);
	} while (next_permutation(s.begin(), s.end()));
	
	cout << total_cost << "\n";

/*	auto end_time = chrono::high_resolution_clock::now();
	auto total_time = end_time - start_time;
	cout << total_time / chrono::milliseconds(1) << "\n";*/

	return 0;
}
