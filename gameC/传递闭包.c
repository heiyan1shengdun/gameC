#include<stdio.h>
#include<stdlib.h>
void Warshall(int,int**);//�󴫵ݱհ����� 
void main()
{
    int i,j,num;
    FILE*p;
    p=fopen("graph.txt","r");
    if(p==NULL)
    {
        printf("����graph.txt������ͼ����Ӧ�ڽӾ���");
        exit(-1);
    }
    fscanf(p,"%d",&num);
    int **r=(int**)malloc(sizeof(int*)*(num+1));
    
    for(i=0;i<num+1;i++)
        r[i]=(int*)malloc(sizeof(int)*(num+1));
    for(i=1;i<num+1;i++)
        for(j=1;j<num+1;j++)
            fscanf(p,"%d",&r[i][j]);
    
    printf("�������Ϊ��%d\n",num);
    
    printf("�ڽӾ���Ϊ��\n");
    for(i=1;i<num+1;i++)
    {
        for(j=1;j<num+1;j++)
            printf(" %d  ",r[i][j]);
        printf("\n");
    }
    //����warshell���� 
    Warshall(num,r);
    printf("���ݱհ�Ϊ:\n");
    for(i=1;i<num+1;i++)
    {
        for(j=1;j<num+1;j++)
            printf(" %d  ",r[i][j]);
        printf("\n");
    }
 }
 
//warshall�㷨
void Warshall(int num,int**r)
{
    int i,j,k;
    int **temp=(int**)malloc(sizeof(int*)*(num+1));
    for(i=0;i<num+1;i++)
        temp[i]=(int*)malloc(sizeof(int)*(num+1));
    //���λ�ȡ������Ϊ�м��Ķ���
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
