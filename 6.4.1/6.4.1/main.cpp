#include <stdlib.h>
#include <stdio.h>
#include <string>
#define MAXN 100
int n;
int mat[MAXN][MAXN];
int vis[MAXN][MAXN];
int num;

void dfs(int i, int j)
{
	if (mat[i][j] == 0) return;
	if (vis[i][j] == 1) return;
	vis[i][j] = 1;
	if ((i + 1 <= 7)&&(j + 1 <= 7)) dfs(i+1, j+1);
	if ((i + 1 <= 7)&&(j - 1 >= 0)) dfs(i+1, j-1);
	if ((i - 1 >= 0)&&(j + 1 <= 7)) dfs(i-1, j+1);
	if ((i - 1 >= 0)&&(j - 1 >= 0)) dfs(i-1, j-1);
	if (i + 1 <= 7) dfs(i+1, j);
	if (i - 1 >= 0) dfs(i-1, j);
	if (j + 1 <= 7) dfs(i, j+1);
	if (j - 1 >= 0) dfs(i, j-1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%d", &n) == 1)
	{
		num = 0;
		int i, j;
		for (i = 0; i < n; i++)
				scanf("%d%d%d%d%d%d", &mat[i][0], &mat[i][1], &mat[i][2], &mat[i][3], &mat[i][4], &mat[i][5]);
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if ((mat[i][j] == 1)&&(vis[i][j] == 0))
				{
					dfs(i, j);
					num++;
				}
			}
		}
		printf("%d", num);
	}

}