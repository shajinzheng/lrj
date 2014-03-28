#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 100
int n, m, t;//n - number of variables; m - number of inequations
int G[MAXN][MAXN];
int vis[MAXN*MAXN];
int result[MAXN*MAXN];
char s[MAXN];

bool dfs(int i)
{
	vis[i] = -1;
	int j;
	for (j = 0; j < n; j++) if (G[i][j])
	{
		if (vis[j] < 0) return false;
		if (!vis[j] && !dfs(j)) return false;
	}
	vis[i] = 1;
	result[--t] = i;
	return true;
}

bool toposort()
{
	int i;
	for (i = 0; i < n; i++) if (!vis[i])
		if (!dfs(i)) return false;
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(vis, 0, sizeof(vis));
		memset(result, 0, sizeof(result));
		memset(G, 0, sizeof(G));
		int i;
		t = n;
		for (i = 0; i < m; i++)
		{
			scanf("%s", s);
			G[s[0] - 'a'][s[2] - 'a'] = 1;
		}
		if(!toposort()) return 0;
		for (i = 0; i < n; i++)
		{
			printf("%c", 'a'+result[i]);
			if (i != n - 1)
				printf(" < ");
		}
	}
	return 0;
}