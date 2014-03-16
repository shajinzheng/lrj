#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 256+1
#define MAXM 20
#define LOCAL
int tree[MAXN];
char tempt[MAXM];
char value[MAXM];
int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // LOCAL
	while(scanf("%s", tempt) == 1)
	{
		int num = 0, j, flag = 1;
		memset(tree, 0, sizeof(tree));
		while (strlen(tempt) != 2)//可以用strcmp,比较数组'\0'结束符前面的字符串是否相等
		{
			char * ptr = strchr(tempt, ','), * ptr1 = strchr(tempt, ')');
			memset(value, 0, sizeof(value));
			int i, idx = 1;
			for (i = 1; i + tempt < ptr; i++)
				value[i-1] = *(tempt + i);
			value[i] = 0;
			for (i = 1; i + ptr < ptr1; i++)
			{
				if (*(i + ptr) == 'L')
					idx = idx * 2;
				else if(*(i + ptr) == 'R')
					idx = idx * 2 + 1;
			}
			num = (num > idx)?num:idx;
			tree[idx] = atoi(value);
			scanf("%s", tempt);
		}
		for (j = 1; j <= num; j++)
		{
			if (tree[j] != 0)
			{
				if(j == 1)
				{
					if(tree[1] == 0)
					{
						flag = 0;
						break;
					}
				}
				else if (tree[j/2] == 0)
				{
					flag = 0;
					break;
				}
			}
		}
		if (flag)
		{
			int i;
			for (i = 1; i <= num; i++)
			{
				if (tree[i] != 0)
					printf("%d ", tree[i]);
			}
		}
		else
			printf("-1");
		printf("\n");
	}
	return 0;
}