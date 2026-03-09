#include<stdio.h>
void mergesort(int arr[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}
void merge(int arr[],int low,int mid,int high){
	int i,j,k=0;
	int b[10];
	i=low;
	j=mid+1;
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			b[k]=arr[i];
			i++;
		}
		else{
			b[k]=arr[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=arr[i];
		i++;
		k++;
	}
	while(j<=high)
	{
		b[k]=arr[j];
		j++;
		k++;
	}
	for(i=low,k=0;i<=high;i++,k++)
	{
		arr[i]=b[k];
	}
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
