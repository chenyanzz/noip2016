#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>
#include <ctime>
#include <functional>
#include <algorithm>
using namespace std;
int m, //秒
    n, //只
    q, //长度增加
    u, //p=u/v
    v, //p=u/v
    t; //输出（只数为t整倍数）

FILE *fin, *fout;

int length[7100001];
int cutlen[7100001];

inline int* maxlen(int time)
{
	int* max = length;
	for (int i = 0; i < n + time; i++)
	{
		if (*max < length[i])
		{
			max = length + i;
		}
	}
	return max;
}

inline int originalLength(int len, int time)
{
	return len += time * q;
}

int cmp(const void* a, const void* b)
{
	return (*(int *)b - *(int *)a); //实现的是降序排序
}

int main()
{
	time_t t0 = clock();
	fin = fopen("earthworm.in", "r");
	fout = fopen("earthworm.out", "w");
	fscanf(fin, "%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);
	const int p = (double)u / (double)v;
	int len;
	for (int i = 0; i < n; i++)
	{
		fscanf(fin, "%d", &len);
		length[i] = len;
	}
	int *max, olen, len1, len2;
	for (int i = 0; i < m; i++)
	{
		max = maxlen(i);
		olen = originalLength(*max, i);
		len1 = olen * p;
		len2 = olen - len1;
		len1 -= i * q;
		len1 -= q;
		len2 -= i * q;
		len2 -= q;

		*max = len1;
		length[n + i] = len2;

		cutlen[i] = olen;
	}
	for (int i = 0; i < m; i += t)
	{
		if ((i + 1) % t == 0)
		{
			fprintf(fout, "%d ", cutlen[i]);
		}
	}
	fprintf(fout, "\n");

	qsort(length, n + m, sizeof(int), cmp);

	for (int i = 0; i < (n + m); i++)
	{
		if ((i + 1) % t == 0)
		{
			fprintf(fout, "%d ", originalLength(length[i], m));
		}
	}
	fclose(fin);
	fclose(fout);
	printf("%dms", clock() - t0);
	getchar();
}
