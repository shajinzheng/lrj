#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 50
#define LOCAL
int src[MAXN];
int dst[MAXN];
int stack[MAXN];
int len, ptr_stack, ptr_s;

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while(scanf("%d", &len) == 1)
	{
		memset(stack, 0, sizeof(stack));
		int i, flag = 1;
		ptr_s = 0, ptr_stack = -1;
		for (i = 0; i < len; i++)
		{
			scanf("%d", &dst[i]);
			src[i] = i + 1;
		}
		for (i = 0; i < len; i++)
		{
			if ((ptr_stack >= 0)&&(dst[i] == stack[ptr_stack]))
			{
				ptr_stack--;
				continue;
			}
			else if (dst[i] == src[ptr_s])
			{
				ptr_s++;
				continue;
			}
			else if ((ptr_s < len)&&(dst[i] > src[ptr_s]))//dst[i] > src[ptr_s]这个是不可以少的，如果少了的话，结果是对的，不过是歪打正着
			{
				while(dst[i] > src[ptr_s]) 
					stack[++ptr_stack] = src[ptr_s++];
				if (dst[i] == src[ptr_s])
				{
					ptr_s++;
					continue;
				}
				else
				{
					flag = 0;
					break;
				}
			}
			else
			{
				flag = 0;
				break;
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}

}