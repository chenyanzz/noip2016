#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

bool isFaceOut[100001];
string names[100001];
int t1()
{
	time_t start = clock();
	//读取数据
	int n, m;
	ifstream fin("toy.in");
//	ofstream fout("t1.out");
	//      人数 指令数
	fin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		//逆时针第i个
		fin >> isFaceOut[i] >> names[i];
	}

	//当前哪个人
	int nowPos = 1;
	for (int i = 0; i < m; i++)
	{
		//		cout << names[nowPos] << endl;
		bool isPassRight;
		int move;
		fin >> isPassRight >> move;
		//执行一条指向指令
		//外 左-》+
		if ((!isPassRight) == isFaceOut[nowPos])
		{
			nowPos += move;
			if (nowPos > n)
				nowPos -= n;
		}
		else
		{
			nowPos -= move;
			if (nowPos <= 0)
				nowPos += n;
		}
//		fout << nowPos <<endl;
	}
	cout << names[nowPos] << endl;
	cout << clock() - start << "ms";
	getchar();
	return 0;
}




///////////////////////// 下面是网上的改的 /////////////////////////////////////////////////

#include<iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <ctime>
using namespace std;
int n, m;//小人的个数和指令条数 
int cnt;
int start;
bool k[100001];
string ppl[100001];

int t2()
{
	time_t start_t = clock();
	ifstream fin("toy.in");
	ofstream fout("t2.out");
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		fin >> k[i] >> ppl[i];
	}
	bool con;
	int step;
	start = 1;
	for (int i = 1; i <= m; i++)
	{
		fin >> con >> step;
		int step0 = step % n;
		if ((con + k[start]) % 2 == 0)//顺时针 
		{
			start -= step0;
			if (start <= 0)start += n;
		}
		else
		{
			start += step0;
			if (start > n)start -= n;
		}
		fout << start<<endl;
	}
	cout << ppl[start];
	cout << clock() - start_t << "ms";
	getchar();
	return 0;
}
int main(int argc,char* argv[])
{
	t1();
	t2();
}