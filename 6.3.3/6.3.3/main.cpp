#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 100
char PreOrd[MAXN];
char InOrd[MAXN];
char tree[MAXN];
int NumNodes;

void constructTree(char* Pre, char* In, int n)
{
	char Pre_t_l[MAXN], Pre_t_r[MAXN], In_t_l[MAXN], In_t_r[MAXN];
	char t = Pre[0];
	char * ptr = strchr(In, t);
	int len_l = ptr - In;
	int len_r = strlen(In) - len_l - 1;
	if (len_l > 0)
	{
		memcpy(Pre_t_l, &Pre[1], len_l*sizeof(char)); 
		Pre_t_l[len_l] = 0;
		memcpy(In_t_l, In, len_l*sizeof(char));
		In_t_l[len_l] = 0;
		constructTree(Pre_t_l, In_t_l, 2 * n);
	}
	if (len_r > 0)
	{
		memcpy(Pre_t_r, Pre+1+len_l, len_r*sizeof(char));
		Pre_t_r[len_r] = 0;
		memcpy(In_t_r, ptr+1, len_r*sizeof(char));
		In_t_r[len_r] = 0;
		constructTree(Pre_t_r, In_t_r, 2*n+1);
	}
	tree[n] = t;
	return;
}

void PostOrder(int n)
{
	if (2 * n <= NumNodes) PostOrder(2 * n);
	if (2 * n + 1 <= NumNodes) PostOrder(2 * n + 1);
	if (tree[n])
		printf("%c", tree[n]);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%s", PreOrd); scanf("%s", InOrd);
	constructTree(PreOrd, InOrd, 1);
	NumNodes = 14;
	PostOrder(1);
	//system("pause");
	return 0;
}