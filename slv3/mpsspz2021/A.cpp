/*
	Zadanie "Akordy" z MPSŚPZ 2021 OPEN
*/
#include <bits/stdc++.h>
using namespace std;

int modadd(int x, int k) {
	return (x+k)%12;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<string> alph = {"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};
	vector<int> v(3);
	for (int i=0; i<3; i++)
	{
		string s; cin >> s;
		auto it = find(alph.begin(), alph.end(), s);
		v[i] = (int)(it - alph.begin());
	}

	sort(v.begin(), v.end());

	do
	{	
		if (modadd(v[0], 4) == v[1] && modadd(v[0], 7) == v[2])
		{
			cout << "Akord " << alph[v[0]] << "\n";
			return 0;
		}
		if (modadd(v[0], 3) == v[1] && modadd(v[0], 7) == v[2])
		{
			cout << "Akord " << alph[v[0]] << "m\n";
			return 0;
		}
	}
	while (next_permutation(v.begin(), v.end()));
	
	cout << "Brak\n";

	return 0;
}