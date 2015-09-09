/*********************
Heap Sort
*********************/

#include <stdio.h>

void max_heapify(int a[],int n,int i)
{
	int temp,l=i;
	if(2*i+1 < n && a[2*i+1] > a[i])
		l=2*i+1;
	if(2*i+2 < n && a[2*i+2] > a[l])
		l=2*i+2;
	if(l!=i)
	{
		temp=a[i];
		a[i]=a[l];
		a[l]=temp;
		max_heapify(a,n,l);
	}
}

void build_max_heap(int a[],int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
	{
		max_heapify(a,n,i);
	}

}

void heap_sort(int a[],int n)
{
	int i,temp;
	build_max_heap(a,n);
	for(i=n-1;i>=1;i--)
	{
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		max_heapify(a,i,0);
	}
}

void display(int a[],int n)
{
	int i;
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d   ", a[i]);
}

int main()
{
	freopen("input.txt","r",stdin);
	int a[100000],n=0;
	while(scanf("%d",&a[n++])==1);
	n--;
	display(a,n);
	build_max_heap(a,n);
	display(a,n);
	heap_sort(a,n);
	display(a,n);
	return 0;
}
