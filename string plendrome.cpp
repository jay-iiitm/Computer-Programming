#include<stdio.h>
int main()
{
int n,i;
printf("enter size of array\n");
scanf("%d",&n);
char a[n];
char rev,t,b;
printf("enter elements\n");
for(i=0;i<n;i++)
scanf("%s",a[i]);
char big;
for(i=0;i<n;i++)
{
b=a[i];
rev=0;
while(b>0)
{
t=b%10;
rev=rev*10+t;
b=b/10;
}
if(a[i]==rev)
{printf("%d is palendrome\n",a[i]);
if(a[i]>big)
big=a[i];
}


}
printf("\nand the largest palendrone is=%s",big);
}
