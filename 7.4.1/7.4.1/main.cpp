#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 100
int n;
int result[MAXN];
int times = 0;

int IsOk(int i)
{
	int j;
	int row = result[i] / n, col = result[i] % n;
	int delta = row - col;
	int sum = row + col;
	for (j = 0; j < i; j++)
	{
		int _row = result[j] / n, _col = result[j] % n;
		int _delta = _row - _col;
		int _sum = _row + _col;
		if ((row == _row)||(col == _col)||(delta == _delta)||(sum == _sum))
			return 0;
	}
	return 1;
}

void backtracking(int level)
{
	int i;
	for (i = 0; i < n; i++)
	{
		result[level] = level * n + i;
		if (IsOk(level))
		{
			if (level == n - 1)
			{
				times++;
				printf("%d\n", times);
				int m;
				for (m = 0; m < n; m++)
					printf("%d  %d\n", result[m] / n, result[m] % n);
				printf("\n");
				return;
			}
			else
				backtracking(level + 1);
		}
	}
	return;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%d", &n) == 1)
	{
		memset(result, 0, sizeof(result));
		backtracking(0);
		//printf("%d", times);
	}
	return 0;
}