#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <ctime>
#include <fstream>
using namespace std;

void writeTest()
{
	time_t t0 = clock();
	FILE *f;
	//	fopen_s(&f,"cstdio.out", "w");
	f = fopen("cstdio.out", "w");
	ofstream::sync_with_stdio(false);
	ofstream fout("fsteam.out");
	for (int i = 0; i < 1000000; i++)
	{
		fprintf(f, "%d ", i);
	}
	fclose(f);
	time_t t1 = clock();
	for (int i = 0; i < 1000000; i++)
	{
		fout << i << " ";
	}
	fout.close();
	time_t t2 = clock();
	printf("write:c %ldms,c++ %ldms\n", t1 - t0, t2 - t1);
}

void readTest()
{
	time_t t0 = clock();
	FILE *f;
	//	fopen_s(&f,"cstdio.out", "w");
	f = fopen("cstdio.out", "r");
	ifstream::sync_with_stdio(false);
	ifstream fout("fsteam.out");
	int j;
	for (int i = 0; i < 1000000; i++)
	{
		fscanf(f, "%d ", &j);
	}
	fclose(f);
	time_t t1 = clock();
	for (int i = 0; i < 1000000; i++)
	{
		fout >> j;
		j++;
	}
	fout.close();
	time_t t2 = clock();
	printf("read:c %ldms,c++ %ldms\n", t1 - t0, t2 - t1);
}

int main(int argc, char* argv[])
{
	writeTest();
	readTest();
	getchar();
	return 0;
}
