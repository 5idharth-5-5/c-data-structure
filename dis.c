#include<stdio.h>
#define MAX 20
int parent[MAX];
int rank[MAX];
void create(int n)
{
int i;
for(i=0;i<n;i++)
{
parent[i]=i;
rank[i]=0;
}
printf("disjoint sets created successfully\n");
}
int find(int x)
{
if (parent[x]!=x)
parent[x]=find(parent[x]);
return parent[x];
}
void Union(int x,int y)
{
int rootx=find(x);
int rooty=find(y);
if(rootx==rooty)
{
printf("both elments belong to the same set\n");
return;
}
if(rank[rootx]<rank[rooty])
{
parent[rootx]=rooty;
}
else if (rank[rootx]>rank[rooty])
{
parent[rooty]=rootx;
}
else
{
parent[rooty]=rootx;
rank[rootx]++;
}
printf("union operation completed successfully\n");
}
void display(int n)
{
int i;
printf("\nelement\tparent\trepresentative\n");
for(i=0;i<n;i++)
{
printf("%d\t%d\t%d\n",i,parent[i],find(i));
}
}
int main()
{
int n,choice,x,y;
printf("enter the number of elments:");
scanf("%d",&n);
if(n<=0||n>MAX)
{
printf("invalid number of elements:\n");
return 0;
}
do
{
printf("\n----Disjoint Set ADT----\n");
printf("1.create\n");
printf("2.union\n");
printf("3.find\n");
printf("4.display\n");
printf("5.exit\n");
printf("enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
create(n);
break;
case 2:
printf("enter two elements:");
scanf("%d %d",&x,&y);
if(x>=0&&x<n&&y>=0&&y<n)
Union(x,y);
else
printf("invalid elements\n");
break;
case 3:
printf("enter element to find:");
scanf("%d",&x);
if(x>=0&&x<n)
printf("representative of %d is %d\n",x,find(x));
else
printf("invalid element\n");
break;
case 4:
display(n);
break;
case 5:
printf("exiting program..\n");
break;
default:
printf("invalid choice!");
}
}
while(choice!=5);
return 0;
}
