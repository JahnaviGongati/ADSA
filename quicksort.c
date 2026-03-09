#include<stdio.h>
void quicksort(int arr[],int first,int last);
int main()
{
	int n,i;
	scanf("%d",&n);
    int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
void quicksort(int arr[],int first,int last)
{
	int i,j,p,temp;
	if(first<last)
	{
		p=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(arr[i]<=arr[p]&&i<last)
			{
				i++;
			}
			while(arr[j]>arr[p])
			{
				j--;
			}
			if(i<j)
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		temp=arr[j];
		arr[j]=arr[p];
		arr[p]=temp;
		quicksort(arr,first,j-1);
		quicksort(arr,j+1,last);		
	}
}
