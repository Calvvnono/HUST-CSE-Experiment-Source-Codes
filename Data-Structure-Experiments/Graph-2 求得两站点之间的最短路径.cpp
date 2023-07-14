#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int INF = 1000000000;

typedef struct arc //作为邻接表头节点所指向的边
{   
    char name[20];          //存储指向的节点
    float dist;         
    struct arc *next;    
} arc;

typedef struct Head //作为邻接表头节点
{  
    char name[20]; //存储站点名称          
    arc * add;        
} Head;

Head heads[100];
int totalNumber = 0;

void addArc(char start[20], char end[20], float d) {
    int i = 0;
    while(i<=totalNumber && strcmp(heads[i].name, start)!=0)
        i ++;
    if(i == totalNumber+1) {
        totalNumber ++;
        strcpy(heads[totalNumber].name ,start);
        arc* addArc = (arc*)malloc(sizeof(arc));
        strcpy(addArc->name ,end);
        addArc->dist = d;
        addArc->next = NULL;
        heads[totalNumber].add = addArc;
    } else {
        arc* addArc = (arc*)malloc(sizeof(arc));
        strcpy(addArc->name ,end);
        addArc->next = heads[i].add;
        addArc->dist = d;
        heads[i].add = addArc;
    }
}

void fRead() {
    char tmp[20], name[20];
    float d;
    while(1) {
        scanf("%s", tmp);
        if(strcmp(tmp, "END!") == 0)   break;
        scanf("%s %f", name, &d);
        addArc(tmp, name, d);
        addArc(name, tmp, d);
    }
}

int findNode(char *name, int n) //在头节点数组中查找节点编号
{
    for (int i = 1; i <= n; i++)
    {
        if (strcmp(name, heads[i].name) == 0)
        {
            return i;
        }
    }
    return -1; //未找到节点
}

int prev[100]; //存储最短路径每个点的前继

void printPath(int start, int end)
{
    if (end == -1)
	    return;
    else
    {
        printPath(start, prev[end]);     // 递归实现倒序输出
        printf("%s ", heads[end].name);
    }
}

void Dijkstra(int start, int end, int n) 
{
	int vis[n+1];    //记录每个节点是否已被访问
	float dist[n+1]; //记录起点到每个节点的最短距离
    //初始化
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
        prev[i] = -1;
        vis[i] = 0;
    }
    dist[start] = 0;
    vis[start] = 1;
	for (arc* p = heads[start].add; p != NULL; p = p->next)
    {
    	if(p == NULL)	break;	
    	int idx = findNode(p->name, totalNumber);
		dist[idx] = p->dist;
		prev[idx] = start;
	}
	
    //循环n次
    for (int i = 1; i <= n; i++)
    {
        int u = -1;
        float minDist = INF;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && dist[j] < minDist)
            {
                u = j;
                minDist = dist[j];
            }
        }
        if (u == -1)
        {
            break;
        }
        vis[u] = 1;

        //更新
        for (arc *p = heads[u].add; p->next != NULL; p = p->next)
        {
        	if(p == NULL)	break;
            int v = findNode(p->name, n);
            if (!vis[v] && dist[u] + p->dist < dist[v])
            {
                dist[v] = dist[u] + p->dist;
                prev[v] = u;
            }
        }
    }

    //输出结果
    printPath(start, end);
    printf("%.2f\n", dist[end]);
}

int main(void)
{
	fRead();
	char start[20], end[20];
	scanf("%s %s", start, end);
	int s = findNode(start, totalNumber);
	int e = findNode(end, totalNumber);
	Dijkstra(s, e, totalNumber);
    return 0;
}

