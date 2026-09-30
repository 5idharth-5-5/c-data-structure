#include<stdio.h>
int main()
{
int n,i;
int ft=0,st=1;
int new= ft + st;
printf("Enter the terms : ");
scanf("%d",&n);
printf("fibanacci series:%d ,%d ",ft,st);
for(i=0;i<=n;++i)
{
 printf("%d",new);
 new= ft + st;
 st= new;
 new = st;
 
 }
 return 0;
 }
