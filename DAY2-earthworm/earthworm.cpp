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
#define  p  (double)u / (double)v

FILE *fin, *fout;

multiset<int, greater<int>> length;

inline int originalLength(int len, int time)
{
	return len += time * q;
}

//inline void grow()
//{
//	for (auto it = length.begin(); it != length.end(); it++)
//	{
//		*const_cast<int*>(&*it) += q;
//	}
//}

int main()
{
	time_t t0 = clock();
	fin = fopen("earthworm.in", "r");
	fout = fopen("earthworm.out", "w");
	fscanf(fin, "%d%d%d%d%d%d", &n, &m, &q, &u, &v, &t);

	for (int i = 0; i < n; i++)
	{
		int len;
		fscanf(fin, "%d", &len);
		length.insert(len);
	}
	auto itt = length.begin();
//	for (int j = 1; j <= (n + 0); j++)
//	{
//		if (j % t == 0)
//		{
//			printf("%d ", originalLength(*itt, 0));
//		}
//		itt++;
//	}
//	printf("\n");
	for (int i = 1; i <= m; i++)
	{
		//////////////////////////////////////////////////////////////////////////
		auto itmax = length.begin();
		int olen = originalLength(*itmax, i-1);
		length.erase(length.begin());
		int len1 = olen * p;
		int len2 = olen - len1;
		len1 -= i * q;
		len2 -= i * q;
		length.insert(len1);
		length.insert(len2);
		//////////////////////////////////////////////////////////////////////////
		if (i % t == 0)
		{
			fprintf(fout, "%d ", olen);
		}
		//////////////////////////////////////////////////////////////////////////
//		auto it = length.begin();
//		for (int j = 1; j <= (n + i); j++)
//		{
//			if (j % t == 0)
//			{
//				printf("%d ", originalLength(*it, i));
//			}
//			it++;
//		}
//		printf("\n");
	}
	fprintf(fout, "\n");

	auto it = length.begin();
	for (int i = 1; i <= (n + m); i++)
	{
		if (i % t == 0)
		{
			fprintf(fout, "%d ", originalLength(*it, m));
		}
		it++;
	}
	fclose(fin);
	fclose(fout);
	printf("%dms", clock() - t0);
}
