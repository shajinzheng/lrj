#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100
int n, m;
int begin_i, begin_j;
int mat[MAXN][MAXN];
int vis[MAXN][MAXN];
int distance[MAXN][MAXN];
int last[MAXN][MAXN];
int queue[MAXN*MAXN+100];
int front = 0, rear = 0;

void bfs(int _i, int _j)
{
	queue[rear++] = _i * m + _j;
	distance[_i][_j] = 0;
	int i, j;
	while(front < rear)
	{
		i = queue[front] / m;
		j = queue[front] % m;
		vis[i][j] = 1;
		if ((i+1 < n)&&(vis[i+1][j] != 1)&&(mat[i+1][j] != 1)) 
		{
			queue[rear++] = (i + 1) * m + j;
			distance[i+1][j] = distance[i][j] + 1;
			last[i+1][j] = queue[front];
		}
		if ((i-1 >= 0)&&(vis[i-1][j] != 1)&&(mat[i-1][j] != 1)) 
		{
			queue[rear++] = (i - 1) * m + j;
			distance[i-1][j] = distance[i][j] + 1;
			last[i-1][j] = queue[front];
		} 
		if ((j+1 < m)&&(vis[i][j+1] != 1)&&(mat[i][j+1] != 1)) 
		{
			queue[rear++] = i * m + j + 1;
			distance[i][j+1] = distance[i][j] + 1;
			last[i][j+1] = queue[front];
		}
		if ((j-1 >= 0)&&(vis[i][j-1] != 1)&&(mat[i][j-1] != 1))
		{
			queue[rear++] = i * m + j - 1;
			distance[i][j-1] = distance[i][j] + 1;
			last[i][j-1] = queue[front];
		}
		front++;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(mat, 0, sizeof(mat));
		memset(vis, 0, sizeof(vis));
		memset(distance, 0, sizeof(distance));
		memset(last, 0, sizeof(last));
		int i, j;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &mat[i][j]);
		scanf("%d%d", &begin_i, &begin_j);
		bfs(begin_i - 1, begin_j - 1);
	}
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%4d ", distance[i][j]);
		printf("\n");
	}
}