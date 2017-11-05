#include<stdio.h>
#include<stdlib.h>
void Warshall(int,int**);//求传递闭包函数 
void main()
{
    int i,j,num;
    FILE*p;
    p=fopen("graph.txt","r");
    if(p==NULL)
    {
        printf("请在graph.txt中输入图所对应邻接矩阵");
        exit(-1);
    }
    fscanf(p,"%d",&num);
    int **r=(int**)malloc(sizeof(int*)*(num+1));
    
    for(i=0;i<num+1;i++)
        r[i]=(int*)malloc(sizeof(int)*(num+1));
    for(i=1;i<num+1;i++)
        for(j=1;j<num+1;j++)
            fscanf(p,"%d",&r[i][j]);
    
    printf("顶点个数为：%d\n",num);
    
    printf("邻接矩阵为：\n");
    for(i=1;i<num+1;i++)
    {
        for(j=1;j<num+1;j++)
            printf(" %d  ",r[i][j]);
        printf("\n");
    }
    //调用warshell函数 
    Warshall(num,r);
    printf("传递闭包为:\n");
    for(i=1;i<num+1;i++)
    {
        for(j=1;j<num+1;j++)
            printf(" %d  ",r[i][j]);
        printf("\n");
    }
 }
 
//warshall算法
void Warshall(int num,int**r)
{
    int i,j,k;
    int **temp=(int**)malloc(sizeof(int*)*(num+1));
    for(i=0;i<num+1;i++)
        temp[i]=(int*)malloc(sizeof(int)*(num+1));
    //依次获取可以作为中间点的顶点
    for(k=1;k<=num;k++)
    {
       for(i=1;i<=num;i++)
       {
            for(j=1;j<=num;j++)
            {
                temp[i][j]=(r[i][j])||(r[i][k]&r[k][j]);
            }
        }
        for(i=1;i<=num;i++)
            for(j=1;j<=num;j++)
                r[i][j]=temp[i][j];
    }
}
