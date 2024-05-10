#include<stdio.h>
#include<stdlib.h>



int main()
{
	int p_num,r_num;
	
	printf("Enter the number of processes :-");
	scanf("%d",&p_num);
	
	printf("Enter the number of resources :-");
	scanf("%d",&r_num);
	
	int Allocation[p_num][r_num];
	int Max[p_num][r_num];
	int Available[1][r_num];
	int Need[p_num][r_num];
	int flag[p_num];
	
	
	printf("\nEnter the entries of allocation table");
	printf("\nEnter the allocations of Process ");
	for(int i=0;i<p_num;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			scanf("%d",&Allocation[i][j]);
		}
		printf("\n");
	}
	
	printf("\nEnter the entries of Max table");
	printf("\nEnter the Max of Process ");
	for(int i=0;i<p_num;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			scanf("%d",&Max[i][j]);
		}
		printf("\n");
	}
	
	printf("\nEnter the entries of Available table");
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			scanf("%d",&Available[i][j]);
		}
		printf("\n");
	}
	
	printf("NEED TABLE\n");
	for(int i=0;i<p_num;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			Need[i][j]=(Max[i][j]-Allocation[i][j]);
			printf("%d",Need[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	
	
	int Request[0][r_num];
	int request_num=0;
	
	printf("\nFor which process do u want to make request :- ");
	scanf("%d",&request_num);
	
	printf("\nEnter the entries of Request");
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			scanf("%d",&Request[i][j]);
		}
		printf("\n");
	}
	
	printf("REQUEST TABLE\n");
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			printf("%d",Request[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	int count1=0;
	for(int j=0;j<r_num;j++)
	{
		if( Need[request_num-1][j] >= Request[0][j] )
		{
			count1++;
		}
	}
		
		
		
		if (count1 == r_num)
		{
			int count2=0;
			for(int j=0;j<r_num;j++)
			{
				if( Available[0][j] >= Request[0][j] )
				{
					count2++;
				}
			}
			if(count2 == r_num)
			{
				for(int j=0;j<r_num;j++)
				{
					Available[0][j] = Available[0][j] - Request[0][j];
					Allocation[request_num-1][j] = Allocation[request_num-1][j] + Request[0][j];
					Need[request_num-1][j] = Need[request_num-1][j] - Request[0][j] ;
				}
			}
			
		}
		
		
		
	printf("NEED TABLE\n");
	for(int i=0;i<p_num;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			Need[i][j]=(Max[i][j]-Allocation[i][j]);
			printf("%d",Need[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	
	printf("ALLOCATION TABLE\n");
	for(int i=0;i<p_num;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			printf("%d",Allocation[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	printf("AVAILABLE TABLE\n");
	for(int i=0;i<1;i++)
	{
		for(int j=0;j<r_num;j++)
		{
			printf("%d",Available[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	
	//int flag2[p_num];	
	printf("\nCURRENT AVAILABLE TABLE\n");
	for( int k=0;k<p_num;k++)
	{
		for( int i=0;i<p_num;i++)
		{
			if(flag[i]!=1)
			{
				int count=0;
				for( int j=0;j<r_num;j++)
				{
					if( Need[i][j] <= Available[0][j] )
					{
						count+=1;
					}
				}
				
				
				if(count == r_num)
				{
					flag[i]=1;
					for(int j=0;j<r_num;j++)
					{
						Available[0][j] = Available[0][j] + Allocation[i][j];
						printf("%d",Available[0][j]);
						printf("\t");
					}
					printf("\nSave Sequence id %d:",i);
					printf("\n");
				}
			}
		}
	}
	return 0;
		
}
