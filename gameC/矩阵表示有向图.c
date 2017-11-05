#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAX 100 //����������Ŀ 
#define isLetter(a)  ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z'))) //�ж������Ƿ�Ϊ��ĸ 

// �ڽӾ���
typedef struct _graph
{
    char vexs[MAX];       // ���㼯��
    int vexnum;           // ������
    int edgnum;           // ����
    int matrix[MAX][MAX]; // �ڽӾ���
}Graph, *PGraph;
/*
 * ����ch��matrix�����е�λ��
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
 * ��ȡһ�������ַ�
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
 * ����ͼ
 */
Graph* create_graph(char *vex)
{
    char c1, c2;
    int v, e;
    int i, p1, p2;
    Graph* pG;
    // ����"������"
    printf(" please input vertex number: ");
    scanf("%d", &v);
    //����"����" 
    printf(" please input edge number: ");
    scanf("%d", &e);
    //����ͼ 
    if ((pG=(Graph*)malloc(sizeof(Graph))) == NULL ) return NULL;
    //������ֵȫ����ʼ��Ϊ0 
    memset(pG, 0, sizeof(Graph));
    // ��ʼ��"������"��"����"
    pG->vexnum = v;
    pG->edgnum = e;
    // ��ʼ��"����"
    for (i = 0; i < pG->vexnum; i++)
    {
        printf("vertex(%d): ", i+1);
        pG->vexs[i] = input();
        vex[i] =  pG->vexs[i];
    }
    // ��ʼ��"��"
    for (i = 0; i < pG->edgnum; i++)
    {
        // ��ȡ�ߵ���ʼ����ͽ�������
        printf("edge(%d):", i+1);
        c1 = input();
        c2 = input();
        p1 = locate(*pG, c1);
        p2 = locate(*pG, c2);
        // ������Ķ��� 
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
 * ��ӡͼ
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
    //���ڴ������� 
    if(pG == NULL) 
	{
		return 0;
	}
    // ��ӡͼ
    print_graph(*pG,vex);
    getchar();
    return 0;
}
