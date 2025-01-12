/*
	Zadanie "Jednorożce" z OKI
*/
#include <stdio.h>

int main()
{
	int n, c, ans = 0;
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &c);
		ans ^= c;
	}
	printf("%d\n", ans);

	return 0;
}
