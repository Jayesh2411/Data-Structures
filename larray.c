#include<stdio.h>


void traverse(int arr[],int n)	{
	int i;
	if(n == 1 )     {
                printf("\nArray Empty!\n");
               
        }
	else	{
		for(i=0;i<n;i++)	{
			printf("\n %d: %d",i,arr[i]);
		}
	}
}

void swap(int arr[],int j)	{
	int temp;
	temp = arr[j];
	arr[j] = arr[j+1];
	arr[j+1] = temp;
	
}

void sort(int arr[],int n)	{
	int i,j;
	for(i = 0;i < n; i++)	{
		for(j = 0;j < n-1-i; j++)	{
			if(arr[j] > arr[j+1])
				swap(arr,j);
			}
		}
}
void search(int arr[],int item, int n)	{

	int beg,mid,end,loc;
	beg = 0,end = n;
	mid = (beg + end)/2;
	loc = 0;
	sort(arr,n);
	while(beg  <= end && arr[mid] != item)	{
		if(item < arr[mid])	{
			end = mid-1;
			mid = (beg+end)/2;
			}
		else {
			beg = mid+1;
			mid = (beg+end)/2;
		}
	}
	
	if(item == arr[mid])	{
		printf("\nItem %d Found at location %d ",item,mid);
	}
	else
		printf("\nNot Found!");
}

int insert(int arr[], int key,int loc,int n)	{
	int i ,j;
	for(i = n; i >= loc; i--)	{
		arr[i+1] = arr[i];
	}
	n = n+1;
	arr[loc] = key;
	return n;
}

int delete(int arr[],int key,int n)	{
	int i,loc=0;
	int flag = 0;
	if(n == 1 )	{
		printf("\nArray Empty!\n");
		return n;
	}
	for(i = 0;i < n; i++)	{
		if(arr[i] == key)	{	
			loc = i;
			flag = 1;
		}
	}
	if(flag == 0)	{
		printf("\nNo such item exists!");
		return n;	
	}
	for(i = loc; i<n-1;i++)	{
		arr[i] = arr[i+1];
	}
	n = n-1;
	return n;
}
		
int delete_all(int arr[],int n)	{
	for(int i = 0;i<n;i++ )
		arr[i] = 0;
	n = 1;
	return n;
}
//Defining a linear array and operting various DS functions on it
int main()	{
	int n = 10, ch ,item ,loc = 0;
	int larr[]={10,23,54,21,14,6,4,29,33,44};
	do	{
		printf("\nEnter the operations to be performed:\n 1:Traverse 2:Sort 3:Search 4:Insert 5:Delete 6:Delete Entire Array \n Press 0 to quit\n");
		scanf("%d",&ch);
		switch(ch)	{
			case 1:
				traverse(larr,n);
				break;
			case 2:
				sort(larr,n);
				break;
			case 3:
				if(n == 1 )     {
        			        printf("\nArray Empty!\n");
               				 break;
       				 }		
				printf("\nEnter the query: ");
				scanf("%d",&item);
				search(larr,item,n);
				break;
			case 4:
				printf("\nEnter the query to insert at which location?:  ");
                                printf("\nItem: ");
				scanf("%d",&item);
				printf("\nLocation:");
				scanf("%d",&loc);
				n = insert(larr,item,loc,n);
				break;
			case 5:
				if(n == 1)	{
					printf("\nCan't delete a empty array, Can we?\n");
					break;
				}
				printf("\nEnter the query to delete: ");
                                scanf("%d",&item);
                                n = delete(larr,item,n);
                                break;
			case 6:
                                if(n == 1)      {
                                        printf("\nCan't delete a empty array, Can we?\n");
                                        break;
                                }
                                printf("\nDeleting entire array!\n ");
           
                                n = delete_all(larr,n);
                                break;

			case 0:
				printf("\nExiting!\n");
				break;	
			default:
				printf("\nTry Again!\n");	
			}
	}while(ch != 0);

}

