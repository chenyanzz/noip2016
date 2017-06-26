#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

class Vertex
{
public:
	int id;
	int WatchTime;
	int cPlayer = 0;
	vector<Vertex*> lineTo;
	bool visited = false;
};

class Player
{
public:
	int id;
	int nowTime = 0;
	Vertex* nowPoint;
	Vertex* endPoint;
	bool arrived = false;
	int move;//+1 || -1
};

Vertex* vertex;
Player* player;
//节点数
int n;
//玩家数
int m;

// 深度优先搜索
// 返回 bool 能否找到当前节点的下一个未检索节点
bool DFS(Vertex* v)
{
	//操作节点


	//记录找过标志
	v->visited = true;

	//寻找line行有没有没检索到的
	for (int i = 0; i < v->lineTo.size(); i++)
	{
		if (!v->lineTo[i]->visited)
		{
			//如果有 检索那一行 判断是否有节点--无节点 继续检索当前节点
			if (DFS(v->lineTo[i]))
			{
				//返回--有节点
				return true;
			}
		}
	}
	//当前节点找不到未检索过的节点
	return false;
}

void moveOnce()
{
	for(int i=1;i<=n;i++)
	{
		Player &p = player[i];
		if (p.arrived)continue;
		if(p.nowPoint->WatchTime == p.nowTime)
		{
			p.nowPoint->cPlayer++;
		}
		if(p.nowPoint==p.endPoint)
		{
			p.arrived = true;
			return;
		}
		p.nowPoint += p.move;
		p.nowTime++;
	}
}

int main(int argc, char* argv[])
{
	time_t start = clock();
//	ifstream fin("running.in");
//	ofstream fout("running.out");
	FILE* fin = fopen("running.in","r");
	FILE* fout = fopen("running.out", "w");
//	fin >> n >> m;
	fscanf(fin, "%d%d", &n, &m);
	vertex = new Vertex[n];
	player = new Player[m];
	//[1] --> 第一个
	vertex--;
	player--;
	for (int i = 0; i < n - 1; i++)
	{
		//相连的两个节点
		int u, v;
//		fin >> u >> v;
		fscanf(fin, "%d%d", &u, &v);
		vertex[u].lineTo.push_back(vertex + v);
		vertex[v].lineTo.push_back(vertex + n);
	}
	for (int i = 1; i <= n; i++)
	{
		int wt;
//		fin >> wt;
		fscanf(fin, "%d", &wt);
		vertex[i].WatchTime = wt;
		vertex[i].id = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int np, ep;
//		fin >> np >> ep;
		fscanf(fin, "%d%d", &np, &ep);
		player[i].nowPoint = &vertex[np];
		player[i].endPoint = &vertex[ep];
		player[i].id = i;
	}
	printf("read file:%dms", clock() - start);
	start = clock();
	switch (n % 10)
	{
	case 1: //所有人的起点等于自己的终点
	case 2: //每个结点出现观察员的时间为0
		for (int i = 1; i <= m; i++)
		{
			if (player[i].nowPoint->WatchTime==0)
			{
				player[i].nowPoint->cPlayer++;
			}
		}
		break;
	case 4: //图为一条链 1-2-3-4...n
	{
		//O(n2)太慢了
		int maxtime = 0;
		for (int i = 1; i <= n; i++)
		{
			maxtime = max(abs(player[i].endPoint - player[i].nowPoint), maxtime);
			player[i].move = player[i].endPoint >= player[i].nowPoint ? 1 : -1;
		}
		for (int i = 0; i < n; i++)
		{
			moveOnce();
		}
	}
		/*for (int i = 1; i <= m; i++)
		{
			int dist = abs(player[i].nowPoint - player[i].endPoint);
			do
			{
				if (player[i].nowPoint->WatchTime == dist)
				{
					player[i].nowPoint->cPlayer++;
				}
				if (player[i].endPoint>player[i].nowPoint)
				{
					player->nowPoint++;
				}else if (player[i].endPoint<player[i].nowPoint)
				{
					player->nowPoint--;
				}
			} while (player[i].nowPoint != player[i].endPoint);
		}
		break;*/
	case 5: //所有人起点为1
		break;
	case 6: //所有人终点为1
		break;
	default:
		break;
	}
	printf("do running:%dms", clock() - start);
	start = clock();
	for (int i = 1; i <= n; i++)
	{
//		fout << vertex[i].cPlayer << " ";
		fprintf(fout, "%d ", vertex[i].cPlayer);
	}
	printf("write file:%dms", clock() - start);
	
//	fin.close();
//	fout.close();
	getchar();
	return 0;
}