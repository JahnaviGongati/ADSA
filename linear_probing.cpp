#include<stdio.h>
void hash(int arr[], int M,int n)
{
	int i,j;
	int b[20];
	int val;
	for(i=0;i<M;i++)
	{
		b[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		j=0;
		while(j<M)
		{
		val=(arr[i]%M+j)%M;
		if(b[val]==-1) 
		{
		  b[val]=arr[i];
		  break;
		}
	     	j++;
		}
	}
	printf("The elements in the hash table\n");
	for(i=0;i<M;i++)
	{
		printf("%d ",b[i]);
	}
}
int main()
{
	int n,i,M=10;
	int arr[20];
	printf("Enter no.of elements:");
	scanf("%d",&n);
	for( i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	hash(arr,M,n);

}
