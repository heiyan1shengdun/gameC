#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX 100 //顶点的最大数目 
#define isLetter(a)  ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z'))) //判断输入是否为字母 

// 邻接矩阵
typedef struct _graph
{
    char vexs[MAX];       // 顶点集合
    int vexnum;           // 顶点数
    int edgnum;           // 边数
    int matrix[MAX][MAX]; // 邻接矩阵
}Graph, *PGraph;
/*
 * 返回ch在matrix矩阵中的位置
 */
static int locate(Graph g, char ch)
{
    int i;
    for(i=0; i<g.vexnum; i++)
        if(g.vexs[i]==ch)
            return i;
    return -1;
}
/*
 * 读取一个输入字符
 */
static char input()
{
    char ch;
    do {
        ch = getchar();
    } while(!isLetter(ch));
    return ch;
}
/*
 * 创建图
 */
Graph* create_graph(char *vex)
{
    char c1, c2;
    int v, e;
    int i, p1, p2;
    Graph* pG;
    // 输入"顶点数"
    printf(" please input vertex number: ");
    scanf("%d", &v);
    //输入"边数" 
    printf(" please input edge number: ");
    scanf("%d", &e);
    //创建图 
    if ((pG=(Graph*)malloc(sizeof(Graph))) == NULL ) return NULL;
    //将矩阵值全部初始化为0 
    memset(pG, 0, sizeof(Graph));
    // 初始化"顶点数"和"边数"
    pG->vexnum = v;
    pG->edgnum = e;
    // 初始化"顶点"
    for (i = 0; i < pG->vexnum; i++)
    {
        printf("vertex(%d): ", i+1);
        pG->vexs[i] = input();
        vex[i] =  pG->vexs[i];
    }
    // 初始化"边"
    for (i = 0; i < pG->edgnum; i++)
    {
        // 读取边的起始顶点和结束顶点
        printf("edge(%d):", i+1);
        c1 = input();
        c2 = input();
        p1 = locate(*pG, c1);
        p2 = locate(*pG, c2);
        // 无输入的顶点 
        if (p1==-1 || p2==-1)
        {
            printf("input error\n");
            free(pG);
            return NULL;
        }
        pG->matrix[p1][p2]++;
    } 
    return pG;
}
/*
 * 打印图
 */
void print_graph(Graph G , char *vex)
{
    int i,j;
    printf("Martix Graph:\n");
    printf("  ");
    for (i = 0; i < G.vexnum; i++)
    {
    	printf("%c ", vex[i]);	
	}
	printf("\n");
    for (i = 0; i < G.vexnum; i++)
    {
    	printf("%c " , vex[i]);
        for (j = 0; j < G.vexnum; j++)
            printf("%d ", G.matrix[i][j]);
        printf("\n");
    }
}
int main()
{
    Graph* pG;
    char vex[MAX];
    pG = create_graph(vex);
    //存在错误输入 
    if(pG == NULL) 
	{
		return 0;
	}
    // 打印图
    print_graph(*pG,vex);
    getchar();
    return 0;
}
