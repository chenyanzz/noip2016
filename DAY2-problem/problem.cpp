#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;
char yh[2001][2001];
bool is0[2001][2001];
int m, n, k, t;
FILE* fin,*fout;
inline int Get_Int() {
	int num = 0, bj = 1;
	char x = fgetc(fin);
	while (x<'0' || x>'9') {
		if (x == '-')bj = -1;
		x = fgetc(fin);
	}
	while (x >= '0'&&x <= '9') {
		num = num * 10 + x - '0';
		x = fgetc(fin);
	}
	return num*bj;
}

void initYh()
{
	for (int i = 0; i <= 2000; i++)
	{
		yh[i][0] = yh[i][i] = 1 % k;
		for (int j = 1; j < i; j++)
		{
			yh[i][j] = (yh[i - 1][j - 1] + yh[i - 1][j]) % k;
			is0[i][j] = yh[i][j] == 0;
		}
	}
}

int main(int argc, char* argv[])
{
	time_t t0 = clock();
	fin = fopen("problem.in", "r");
	fout = fopen("problem.out", "w");
	t = Get_Int();
	k = Get_Int();
	//初始化余数杨辉三角
	initYh();
	//每一组数据
	for (int r = 0; r < t; r++)
	{
		int count = 0;
		n = Get_Int();
		m = Get_Int();
		//一组数据的每一个值
		for (int i = 0; i <= n; i++)
		{
			int nj = min(i, m);
			for (int j = 0; j <= nj; j++)
			{
				count+= is0[i][j];
			}
		}
		fprintf(fout, "%d\n", count);
	}
	fclose(fin);
	fclose(fout);
	printf("%dms", clock() - t0);
	getchar();
	return 0;
}
