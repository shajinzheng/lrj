#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXN 100
char PreOrd[MAXN];
char InOrd[MAXN];
char tree[MAXN];
int NumNodes;

void build(int n, char * s1, char * s2, char * s)
{
	if(n <= 0) return;
	int p = strchr(s2, s1[0]) - s2;
	build(p, s1+1, s2, s);
	build(n-p-1, s1+p+1, s2+p+1, s+p);
	s[n-1] = s1[0];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char s1[MAXN], s2[MAXN], ans[MAXN];
	while (scanf("%s%s", s1, s2) == 2)
	{
		int n = strlen(s1);
		build(n, s1, s2, ans);
		ans[n] = '\0';
		printf("%s\n", ans);
	}
}
//void constructTree(char* Pre, char* In, int n)
//{
//	NumNodes = (NumNodes > n) ? NumNodes : n;
//	char Pre_t_l[MAXN], Pre_t_r[MAXN], In_t_l[MAXN], In_t_r[MAXN];
//	char t = Pre[0];//the first element of pre-order is the root of the tree
//	char * ptr = strchr(In, t);//elements before the root of the tree in in-order
//	int len_l = ptr - In;
//	int len_r = strlen(In) - len_l - 1;
//	if (len_l > 0)
//	{
//		memcpy(Pre_t_l, &Pre[1], len_l*sizeof(char)); 
//		Pre_t_l[len_l] = 0;
//		memcpy(In_t_l, In, len_l*sizeof(char));
//		In_t_l[len_l] = 0;
//		constructTree(Pre_t_l, In_t_l, 2 * n);
//	}
//	if (len_r > 0)
//	{
//		memcpy(Pre_t_r, Pre+1+len_l, len_r*sizeof(char));
//		Pre_t_r[len_r] = 0;
//		memcpy(In_t_r, ptr+1, len_r*sizeof(char));
//		In_t_r[len_r] = 0;
//		constructTree(Pre_t_r, In_t_r, 2*n+1);
//	}
//	tree[n] = t;
//	return;
//}
//
//void PrintPostOrder(int n)
//{
//	if (2 * n <= NumNodes) PrintPostOrder(2 * n);
//	if (2 * n + 1 <= NumNodes) PrintPostOrder(2 * n + 1);
//	if (tree[n])
//		printf("%c", tree[n]);
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	while (scanf("%s%s", PreOrd, InOrd) == 2)
//	{
//		NumNodes = 0;
//		constructTree(PreOrd, InOrd, 1);
//		PrintPostOrder(1);
//		printf("\n");
//		memset(PreOrd, 0, strlen(PreOrd));
//		memset(InOrd, 0, strlen(InOrd));
//		memset(tree, 0, sizeof(tree));
//	}
//	return 0;
//}