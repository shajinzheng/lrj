#include <queue>
#include <cstdio>
using namespace std;

queue <int> q;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) q.push(i+1);
	while (!q.empty())
	{
		printf("%d ", q.front());
		q.pop();
		if (!q.empty())
		{
			q.push(q.front());
			q.pop();
		}
	}
	system("pause");
}