#include <iostream>
using namespace std;

typedef struct graph
{
    int vexnum;   // 顶点数
    int **matrix; // 邻接矩阵
}Graph;


void floyd(Graph &G, int **path, int **dist)
{
    //对权重矩阵和前驱矩阵初始化
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            dist[i][j] = G.matrix[i][j];   
            path[i][j] = j;
        }
    }

    // 计算最短路径
    for (int k = 0; k < G.vexnum; k++)
    {
        for (int i = 0; i < G.vexnum; i++)
        {
            for (int j = 0; j < G.vexnum; j++)
            {
                //计算前驱结点
                if(k == 0) {
                    if(i == j || G.matrix[i][j] == INF) path[i][j] = INF;
                    else path[i][j] = i;
                }
                else {
                    if(dist[i][j] > dist[i][k] + dist[k][j]) path[i][j] = path[k][j];
                }

                // 如果经过下标为k顶点路径比原两点间路径更短，则更新dist[i][j]
                int tmp = (dist[i][k]==INF || dist[k][j]==INF) ? INF : (dist[i][k] + dist[k][j]);
                if (dist[i][j] > tmp)
                {
                    dist[i][j] = tmp;
                }
            }
        }
    }
}
void printAllPath(int **path, int i, int j) {
    if(i == j) printf("%d ", i + 1);
    else {
        printAllPath(path, i, path[i][j]);
        printf("%d ", j + 1);
    }
}