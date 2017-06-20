//
//  main.c
//  图
//
//  Created by Jason on 2017/6/8.
//  Copyright © 2017年 Jason. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//MARK:Boolean 是布尔类型，其实就是TRUE和FALSE
typedef enum  Boolean {
    FALSE,
    TRUE,
} Boolean;

typedef enum {
    ERROR,
    OK,
} Status;

//MARK:队列定义
typedef struct Queue {
    
} Queue;
void InitQueue(Queue *Q);
void EnQueue(Queue *Q, int value);
Boolean QueueEmpty(Queue Q);
void DeQueue(Queue *Q, int *value);

//MARK:以下是图的基本定义和实现
//顶点类型
typedef char VertexType;

//边上权类型
typedef int EdgeType;

//最大顶点数
#define MaxVEX 100

//65535代表∞
#define INFINITY 65535

#pragma mark - 邻接矩阵
//邻接矩阵
typedef struct MGraph {
    //顶点表
    VertexType vex[MaxVEX];
    //邻接矩阵，边表
    EdgeType arc[MaxVEX][MaxVEX];
    
    //图中当前的顶点数和边数
    int numVertexes, numEdges;
} MGraph;

//建立无向网图邻接矩阵表示 二维数据
void CreateMGraph(MGraph *G) {
    int i, j, k, w;
    printf("输入顶点数和边数:\n");
    
    //输入顶点数和边数
    int numVer = 0, numEdges = 0;
    scanf("%d,%d", &numVer, &numEdges);
    G->numVertexes = numVer;
    G->numEdges = numEdges;
    //读入顶点信息，建立顶点表
    for (i = 0; i < G->numVertexes; i++) {
        scanf("%c", &G->vex[i]);
    }
    
    for (i = 0; i < G->numVertexes; i++) {
        for (j = 0; j < G->numVertexes; j++) {
            //邻接矩阵初始化
            G->arc[i][j] = INFINITY;
        }
    }
    //读入numEdges条边， 建立邻接矩阵
    for (k = 0; k < G->numEdges; k++) {
        printf("输入边(vi, vj)上的下表i, 下标j和权w：\n");
        
        //输入边（vi,vj）上的权w
        scanf("%d,%d,%d", &i, &j, &w);
        G->arc[i][j] = w;
        //因为是无向图，矩阵对称
        G->arc[j][i] = G->arc[i][j];
    }
}

//MARK:“邻接矩阵”的深度优先遍历算法
//访问标示的数组
Boolean visited[MaxVEX];

/*邻接矩阵的优先深度递归算法*/
void DFS(MGraph G, int i) {
    int j;
    visited[i] = TRUE;
    
    //打印顶点
    printf("%c ", G.vex[i]);
    for (j = 0; j < G.numVertexes; j++) {
        if (G.arc[i][j] == 1 && visited[j] == FALSE) {
            //对访问的邻接顶点进行递归调用
            DFS(G, j);
        }
    }
}

/*邻接矩阵的深度遍历操作*/
void DFSTravers(MGraph G) {
    int i;
    //初始化所有顶点为访问状态
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE;
    }
    
    for (i = 0; i < G.numVertexes; i++) {
        //对未访问过的顶点调用DFS，若是连通图，只会调用一次
        if (visited[i] == FALSE) {
            DFS(G, i);
        }
    }
}


//MARK:“邻接矩阵”的广度遍历算法
void BFSTraverse(MGraph G) {
    int i, j;
    Queue Q;
    
    for (i = 0; i < G.numVertexes; i++) {
        visited[i] = FALSE;
    }
    
    //初始化一辅助用的队列
    InitQueue(&Q);
    //对每个顶点做循环
    for (i = 0; i < G.numVertexes; i++) {
        //若未访问过就处理
        if (visited[i] == FALSE) {
            //设置点钱顶点访问过
            visited[i] = TRUE;
            //打印
            printf("%c", G.vex[i]);
            //将点加入到队列中
            EnQueue(&Q, i);
            
            //若当前队列不为空
            while (QueueEmpty(Q) == TRUE) {
                //将队中元素出队列，赋值给i
                DeQueue(&Q, &i);
                for (j = 0; j < G.numVertexes; j++) {
                    //判断其他顶点若与当前顶点存在边且未访问过
                    if (G.arc[i][j] == 1 && visited[j] == FALSE) {
                        //将找到的此顶点标记为已访问
                        visited[j] = TRUE;
                        //打印
                        printf("%c", G.vex[j]);
                        //将找到的此顶点加入队列
                        EnQueue(&Q, j);
                    }
                }
            }
        }
    }
}


#pragma mark - 图的最小生成树
//MARK:普里姆算法(Prim)
/* Prim算法生成最小生成树 */
void MiniSpanTree_Prim(MGraph G) {
    int min, i, j, k;
    
    //保存相关顶点下标
    int adjvex[MaxVEX];
    //保存相关顶点间边的权值
    int lowcost[MaxVEX];
    //初始化第一个权值为0，即v0加入生成树，
    // lowcost的值为0，在这里就是此下标的顶点已经加入生成树
    lowcost[0] = 0;
    // 初始化第一个顶点小标为0
    adjvex[0] = 0;
    //循环除下标为0外的全部顶点
    for (i = 1; i < G.numVertexes; i++) {
        //将v0顶点与之有边的权值存入数据
        lowcost[i] = G.arc[0][i];
        adjvex[i] = 0;
    }
    
    for (i = 1; i < G.numVertexes; i++) {
        //初始化最小权值∞
        //通常设置为不可能的大数字入65535
        min = INFINITY;
        j = 1; k = 0;
        while (j < G.numVertexes) {
            //如果权值部位0且权值小于min
            if (lowcost[j] != 0 && lowcost[j] < min) {
                //则让当前权值成为最小值
                min = lowcost[j];
                //将当前最小值的下标存入k
                k = j;
            }
            j++;
        }
        //打印当前顶点边中权值最小边
        printf("%d, %d", adjvex[k], k);
        //将当前顶点的权值设置为0，表示此顶点已经完成任务
        lowcost[k] = 0;
        //循环所有顶点
        for (j = 1; j < G.numVertexes; j++) {
            //若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {
                //将较小权值存入lowcost
                lowcost[j] = G.arc[k][j];
                //将下标为k的顶点存入adjvex
                adjvex[j] = k;
            }
            
        }
    }
}

//MARK:克鲁斯卡尔算法 Kruskal
typedef struct Edge {
    int begin;
    int end;
    int weight;
} Edge;

//Kruskal算法最小生成树
#define MAXEDGE 15
#define MAXVEX 9

//查找连线顶点的尾部下标
int Find(int *parent, int f) {
    while (parent[f] > 0) {
        f = parent[f];
    }
    return f;
}

void MiniSpanTree_Kruskal(MGraph G) {
    int i, n, m;
    //定义边集数组
    Edge edges[MAXEDGE];
    //定义一数组用来判断边与边是否形成环路
    int parent[MAXVEX];
    //此处省略邻接矩阵G转化为边集数组edges
    //并按权由小到大排序的代码
    for (i = 0; i < G.numVertexes; i++) {
        //初始化数组值为0
        parent[i] = 0;
    }
    
    //循环每一条边
    for (i = 0; i < G.numVertexes; i++) {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);
        //假如n与m不等，说明此边没有与现有生成树形成环路
        if (n != m) {
            //将此边的结尾顶点放入下标为起点的parent中
            //表示此顶点已经在生成树集合中
            parent[n] = m;
            printf("(%d, %d) %d", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

#pragma mark - 最短路径
//MARK: 迪杰斯特拉算法 (Di-jkstra)
typedef int Patharc[MAXVEX]; //用于存储最短路径下标的数组
typedef int ShortPathTable[MAXVEX]; //用于存储到各点最短路径的权值和
/* Di-jkstra 算法，求有向网图G的v0到奇鱼顶点v最短路径P[v]
   及带权长度D[v]
 
   P[v]的值为前驱顶点下标，D[v]表示v0到v的最短路径长度和
 */
void ShortestPath_Dijkstra(MGraph G,
                           int v0,
                           Patharc *P,
                           ShortPathTable *D) {
    int v, w, k = 0, min;
    // final[w] = 1表示求得顶点V0至Vw的最短路径
    int final[MAXVEX];
    //初始化数据
    for (v = 0; v < G.numVertexes; v++) {
        //全部顶点初始化为未知最短路径状态
        final[v] = 0;
        //将与v0点有连线的顶点加上权值
        (*D)[v] = G.arc[v0][v];
        //初始化路径数组P为-1
        (*P)[v] = -1;
    }
    
    /* v0至v0路径为0 */
    (*D)[v0] = 0;
    //v0值v0不需要求路径
    final[v0] = 1;
    //开始主循环，每次求得v0到某个v顶点的最短路径
    for (v = 1; v < G.numVertexes; v++) {
        //当前所知离v0顶点的最近距离
        min = INFINITY;
        //寻找离v0最近的顶点
        for (w = 0; w < G.numVertexes; w++) {
            if (!final[w] && (*D)[w] < min) {
                k = w;
                // w顶点离v0顶点更近
                min = (*D)[w];
            }
        }
        
        //将目前找到的最近的顶点位置为1
        final[k] = 1;
        //修正当前最短路径及距离
        for (w = 0; w < G.numVertexes; w++) {
            //如果经过v顶点的路径比现在这条路径的长度短的话
            if (!final[w] && (min + G.arc[k][w] < (*D)[w])) {
                //说明找到了更短的路径，修改D[w]和P[w]
                //修改当前路径长度
                (*D)[w] = min + G.arc[k][w];
                (*P)[w] = k;
            }
        }
    }
}

//MARK:弗洛伊德算法 Floyd
typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortsPathTable[MAXVEX][MAXVEX];
/* Floyd算法，求网图G中各顶点v到其余顶点w最短路径P[v][w]
   及带权长度D[v][w]
 */
void ShortestPath_Floyd(MGraph G,
                        Pathmatirx *P,
                        ShortsPathTable *D) {
    int v, w, k;
    //初始化D\P
    for (v = 0; v < G.numVertexes; v++) {
        for (w = 0; w <G.numVertexes; ++w) {
            //D[v][w]值即为对应点间的权值
            (*D)[v][w] = G.arc[v][w];
            //初始化P
            (*P)[v][w] = w;
        }
    }
    
    for (k = 0; k < G.numVertexes; ++k) {
        for (v = 0; v < G.numVertexes; ++v) {
            for (w = 0; w < G.numVertexes; ++w) {
                if ((*D)[v][w] > (*D)[v][k] + (*D)[k][w]) {
                    //如果经过下标为k顶点路径比原两点间领更短
                    //将当前两点间权值设为更小的一个
                    (*D)[v][w] = (*D)[v][k] + (*D)[k][w];
                    (*P)[v][w] = (*P)[v][k];
                }
            }
        }
    }
}


//==============以下是图的链式存储结构===============
#pragma mark - 邻接表
//边表结点
typedef struct EdgeNode {
    //邻接点域，存储改顶点对应的下标
    int adjvex;
    //用于存储权值，对于非网图可以不需要
    EdgeType weight;
    
    //链域，指向下一个邻接点
    struct EdgeNode *next;
} EdgeNode;

//顶点表结点
typedef struct VertxNode {
    //顶点入度
    int in;
    //顶点域，存储顶点信息
    VertexType data;
    //边表头指针
    EdgeNode *firstEdage;
} VertexNode, AdjList[MaxVEX];

typedef struct {
    AdjList adjList;
    //图中当前顶点数和边数
    int numVertexes, numEdges;
} GraphAdjList;

///建立图的邻接表结构
void CreateALGraph(GraphAdjList *G) {
    int i, j, k;
    EdgeNode *e;
    printf("输入顶点数和边数:\n");
    int numVertexes = 0, numEdges = 0;
    //输入顶点数和边数
    scanf("%d,%d", &numVertexes, &numEdges);
    G->numVertexes = numVertexes;
    G->numEdges = numEdges;
    
    //读入顶点信息，建立顶点表
    for (i = 0; i < G->numVertexes; i++) {
        //输入顶点信息
        scanf("%c", &G->adjList[i].data);
        //将边表置为空表
        G->adjList[i].firstEdage = NULL;
    }
    
    //建立边表
    for (k = 0; k < G->numEdges; k++) {
        printf("输入边（vi,vj）上的顶点序号:\n");
        //输入边（vi,vj）上的顶点序号
        scanf("%d,%d", &i, &j);
        /*
         * 结点插入采用：头插法
         */
        //向内存申请空间
        //生成边表结点
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        //邻接序号为j
        e->adjvex = j;
        //将e指针指向单钱顶点指向的结点
        e->next = G->adjList[i].firstEdage;
        //将当前顶点的指针指向e
        G->adjList[i].firstEdage = e;
        
        //向内存申请空间
        //生成边表结点
        e = (EdgeNode *)malloc(sizeof(EdgeNode));
        //邻接序号为i
        e->adjvex = i;
        //将e指针指向单钱顶点指向的结点
        e->next = G->adjList[j].firstEdage;
        //将当前顶点的指针指向e
        G->adjList[j].firstEdage = e;
    }
}

//MARK:邻接表结构的深度遍历
void DFS_GL(GraphAdjList GL, int i) {
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%c ", GL.adjList[i].data);
    
    p = GL.adjList[i].firstEdage;
    while (p) {
        if (visited[p->adjvex] == FALSE) {
            DFS_GL(GL, p->adjvex);
        }
        p = p->next;
    }
}

void DFSTraverse_GL(GraphAdjList GL) {
    int i;
    for (i = 0; i < GL.numVertexes; i++) {
        visited[i] = FALSE;
    }
    
    for (i = 0; i < GL.numVertexes; i++) {
        if (visited[i] == FALSE) {
            //对未访问过的顶点调用DFS，若是连通图，只会调用一次
            DFS_GL(GL, i);
        }
    }
}

//MARK:“邻接表”的广度优先遍历算法
void BGSTraverse(GraphAdjList GL) {
    int i;
    EdgeNode *p;
    Queue Q;
    
    for (i = 0; i < GL.numVertexes; i++) {
        visited[i] = FALSE;
    }
    
    InitQueue(&Q);
    for (i = 0; i < GL.numVertexes; i++) {
        if (visited[i] == FALSE) {
            visited[i] = TRUE;
            //打印
            printf("%c", GL.adjList[i].data);
            EnQueue(&Q, i);
            
            while (QueueEmpty(Q) == FALSE) {
                DeQueue(&Q, &i);
                //找到当前顶点编标链表的头指针
                p = GL.adjList[i].firstEdage;
                while (p) {
                    //若此顶顶啊未访问过
                    if (visited[p->adjvex] == FALSE) {
                        visited[p->adjvex] = TRUE;
                        printf("%c", GL.adjList[p->adjvex].data);
                        //将此顶点加入队列
                        EnQueue(&Q, p->adjvex);
                    }
                    //指针指向下一个邻接点
                    p = p->next;
                }
            }
        }
    }
}

//MARK: 拓扑排序 针对AOV活动关联网
/* 拓扑排序，若GL无回路，则输出拓扑排序序列并
   返回OK，若有回路返回ERROR
> 算法的时间复杂度：O(n+e)
> 应用：主要解决一个工程是否能顺利进行的问题
 */
Status TopologicalSort(GraphAdjList GL) {
    EdgeNode *e;
    int i, k, gettop;
    //用于栈指针下标
    int top = 0;
    
    //用于统计输出顶点的个数
    int count = 0;
    
    //建栈存储入度为0的顶点
    int *stack;
    stack = (int *)malloc(GL.numVertexes * sizeof(int));
    for (i = 0; i < GL.numVertexes; i++) {
        if (GL.adjList[i].in == 0) {
            //将入度为0的顶点入栈
            stack[top++] = i;
        }
    }
    
    while (top != 0) {
        //出栈
        gettop = stack[top--];
        //打印
        printf("%d -> ", GL.adjList[gettop].data);
        //统计输出顶点数
        count++;
        //对此顶点弧表遍历
        for (e = GL.adjList[gettop].firstEdage; e; e = e->next) {
            k = e->adjvex;
            //将k号顶点邻接点的入度-1
            if ((--GL.adjList[k].in) == 0) {
                //若为0则入栈，以便于下次循环输出
                stack[++top] = k;
            }
        }
    }
    //如果count小于顶点数，说明存在环
    if (count < GL.numVertexes) {
        return ERROR;
    } else
        return OK;
}

#pragma mark - 关键路径
/* 拓扑排序，用于关键路径计算 */
int *etv, *ltv; //事件最早发生时间和最晚发生时间数组
int *stack2; //用于存储拓扑排序的栈
int top2; //用于stack2的指针
Status TopologicalSortForKeyPath(GraphAdjList GL) {
    EdgeNode *e;
    int i, k, gettop;
    int top = 0;
    int count = 0;
    int *stack;
    stack = (int *)malloc(GL.numVertexes * sizeof(int));
    for (i = 0; i < GL.numVertexes; i++) {
        if (0 == GL.adjList[i].in) {
            stack[top++] = i;
        }
    }
    
    //初始化为0
    top2 = 0;
    //事件最早发生时间
    etv = (int *)malloc(GL.numVertexes * sizeof(int));
    for (i = 0; i < GL.numVertexes; i++) {
        //初始化为0
        etv[i] = 0;
    }
    //初始化
    stack2 = (int *)malloc(GL.numVertexes * sizeof(int));
    while (top != 0) {
        gettop = stack[top--];
        count++;
        //将弹出的顶点序号压入拓扑序列的栈
        stack2[top2++] = gettop;
        for (e = GL.adjList[gettop].firstEdage; e; e = e->next) {
            k = e->adjvex; // 顶点下标
            if (--GL.adjList[k].in == 0) {
                stack[++top] = k;
            }
            
            //求各顶点事件最早发生时间值
            if ((etv[gettop] + e->weight) > etv[k]) {
                etv[k] = etv[gettop] + e->weight;
            }
        }
    }
    
    if (count < GL.numVertexes) {
        return ERROR;
    } else
        return OK;
}

//MARK:求关键路径，GL为有向图，输出GL的各项关键活动
/*
 时间复杂度分析：拓扑排序是O(n+e)
 
 */
void CriticalPath(GraphAdjList GL) {
    EdgeNode *e;
    int i, gettop, k, j;
    //声明活动最早发生时间和最迟发生时间变量
    int ete, lte;
    //求拓扑排序，计算数据etv和stack2的值
    TopologicalSortForKeyPath(GL);
    //事件最晚发生时间
    ltv = (int *)malloc(GL.numVertexes * sizeof(int));
    for (i = 0; i < GL.numVertexes; i++) {
        //初始化
        ltv[i] = etv[GL.numVertexes - 1];
    }
    
    //计算 ltv
    while (top2 != 0) {
        //将拓扑序列出栈，后进先出
        gettop = stack2[top2--];
        for (e = GL.adjList[gettop].firstEdage; e; e = e->next) {
            //求各顶点事件的最迟发生时间ltv值
            k = e->adjvex;
            //求各顶点事件的最晚发生时间ltv
            if (ltv[k] - e->weight < ltv[gettop]) {
                ltv[gettop] = ltv[k] - e->weight;
            }
        }
    }
    
    //求 ete, lte和关键活动
    for (j = 0; j < GL.numVertexes; j++) {
        for (e = GL.adjList[j].firstEdage; e; e = e->next) {
            k = e->adjvex;
            //活动最早发生时间
            ete = etv[j];
            //活动最迟发生时间
            lte = ltv[k] - e->weight;
            //两者相等即在关键路径上
            if (ete == lte) {
                printf("<%d, %d> length: %d, ", GL.adjList[j].data, GL.adjList[k].data, e->weight);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    //初始化邻接矩阵
    MGraph *G = (MGraph *)malloc(sizeof(MGraph));
    CreateMGraph(G);
    DFSTravers(*G);
    free(G);
    
    //初始化邻接表
    GraphAdjList *GL = (GraphAdjList *)malloc(sizeof(GraphAdjList));
    CreateALGraph(GL);
    DFSTraverse_GL(*GL);
    free(GL);
    printf("Hello, World!\n");
    return 0;
}
