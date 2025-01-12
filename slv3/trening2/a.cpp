#include <bits/stdc++.h>
using namespace std;

map<string, string> mp;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	mp["styczen"] = "I";
	mp["luty"] = "II";
	mp["marzec"] = "III";
	mp["kwiecien"] = "IV";
	mp["maj"] = "V";
	mp["czerwiec"] = "VI";
	mp["lipiec"] = "VII";
	mp["sierpien"] = "VIII";
	mp["wrzesien"] = "IX";
	mp["pazdziernik"] = "X";
	mp["listopad"] = "XI";
	mp["grudzien"] = "XII";
	
	string s; cin >> s;
	cout << mp[s] << "\n";
	
	return 0;
}
