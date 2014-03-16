#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LOCAL

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	int D, I;
	while (scanf("%d%d", &D, &I) == 2)
	{
		int d, k = 1;
		for (d = 0; d < D-1; d++)
		{
			if (I % 2)
			{
				k = 2 * k;
				I = (I + 1)/2;
			}
			else
			{
				k = 2 * k + 1;
				I = I / 2;
			}
		}
		printf("%d\n", k);
	}
}