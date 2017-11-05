#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEXT_NUM 20//最大边数 
typedef int InfoType;
typedef char VertextType;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *nextArc;
    InfoType *info;
}ArcNode;

typedef struct VNode
{
    VertextType data;
    ArcNode *firstArc;
}VNode, AdjList[MAX_VERTEXT_NUM];

typedef struct
{
    AdjList verTices;
    int vexNum;
    int arcNum;
    int kind;
}ALGraph;

void CreateGraph(ALGraph *G);
void DisplayGraph(ALGraph *G);
int main()
{
    ALGraph *Graph = (ALGraph *)malloc(sizeof(ALGraph));
    CreateGraph(Graph);
    DisplayGraph(Graph);
    return 0;
}
void CreateGraph(ALGraph *G)
{
    int i,j,k;
    ArcNode *arcNode;
    printf("请输入顶点数：");
    scanf("%d",&G->vexNum);
    printf("请输入弧数：");
    scanf("%d",&G->arcNum);
    //建立顶点表
    for (i = 0; i < G->vexNum; i++)
    {
        printf("请输入编号为%d的顶点:", i);
        fflush(stdin);//刷新缓冲区
        G->verTices[i].data = getchar();
        G->verTices[i].firstArc = NULL;
    }
    //建立边表
    for (k = 0; k < G->arcNum; k++)
    {
        printf("请输入（vi-vj）的顶点对序号");
        scanf("%d%d", &i, &j);
        arcNode = (ArcNode *)malloc(sizeof(ArcNode));
        arcNode->adjvex = j;
        arcNode->nextArc = G->verTices[i].firstArc;//插入表头
        G->verTices[i].firstArc = arcNode;
        arcNode = (ArcNode *)malloc(sizeof(ArcNode));
        arcNode->adjvex = i;
        arcNode->nextArc = G->verTices[j].firstArc;//插入表头
        G->verTices[j].firstArc = arcNode;
    }
}
void DisplayGraph(ALGraph *G)
{
    int i;
    for (i = 0; i < G->vexNum; i++)
    {
        printf("%c->", G->verTices[i].data);
        while (G->verTices[i].firstArc != NULL)
        {
        	printf("%c->", G->verTices[G->verTices[i].firstArc->adjvex].data);
            G->verTices[i].firstArc = G->verTices[i].firstArc->nextArc;
        }
        printf("\n");
    }
}
