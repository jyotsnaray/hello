//Bankers algorithm

#include<stdio.h>
#include<stdlib.h>

main()
{
int proc,instance,max[100][100],allocate[100][100],need[100][100];
int avail[10],work[10],completed[10];
int i,j;
int count1=0,count2=0,k=0;
printf("\nEnter the number of processes : ");
scanf("%d",&proc);
printf("\nEnter the number of instances for the process : ");
scanf("%d",&instance);

printf("\nEnter the max sequence for each process : ");
for(i=0;i<proc;i++)
{
printf("P[%d]",i);
for(j=0;j<instance;j++)
{
scanf("%d",&max[i][j]);
}
}

printf("\n\nEnter the allocate sequence for each process : ");
for(i=0;i<proc;i++)
{
printf("P[%d]",i);
for(j=0;j<instance;j++)
{
scanf("%d",&allocate[i][j]);
}
}

printf("\n\nEnter available sequence for each instance : \n");
for(j=0;j<instance;j++)
{
scanf("%d",&avail[j]);
}

printf("Enter the need sequence for each process : ");
for(i=0;i<proc;i++)
{
printf("P[%d]",i);
for(j=0;j<instance;j++)
{
scanf("%d",&need[i][j]);
}
}

while(count1!=proc)
{
count2=count1;
for(i=0;i<proc;i++)
{
for(j=0;j<instance;j++)
{
if(need[i][j]<=avail[j]) k++;
}
if(k==instance&&completed[i]==0)
{
printf("P[%d]",i);
completed[i]=1;
for(j=0;j<instance;j++)
avail[j]+=allocate[i][j];
count1++;
}
k=0;
}
if(count1==count2)
{
printf("\nThis system is not safe\n");
printf("Deadlock has occured\n");
exit(1);
}
}
printf("\nThis system is safe\n");
}

