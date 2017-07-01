#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *curr=NULL;


void create(int val) {
	struct node *temp;
	temp=(struct node* )malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	head=curr=temp;

}
void insert(int val,char place) {
	struct node *temp;
	if(head ==NULL) 
		create(val);
	else	{
		temp=(struct node* )malloc(sizeof(struct node));
		temp->data=val;
		if(place == 'e')	{
			temp->next=NULL;
			curr->next=temp;
			curr=temp;	
		}
		else if(place == 's')	{
			temp->next=head;
			head=temp;	
			curr->next=NULL;
		}	
	}
}
void delete(int val) {
		struct node *temp=head,*prev=NULL;
		if(temp == NULL)
			return;
		else	{
			while(temp != NULL)	{
				if(temp->data == val)	{
					prev->next=temp->next;
					free(temp);
				}
				prev=temp;				
				temp=temp->next;
			}
		}
		return;
}

void display() {
	struct node *temp=head;
	if(temp == NULL)	{
		printf("\nEmpty !");
		return;
	}
	int i=0;
	while(temp != NULL)	{
		printf("\n%d: %d",++i,temp->data);
		temp=temp->next;
	}
	return;
	
}
void search(int val) {
	struct node *temp=head;
	if(temp == NULL) {
		printf("\nEmpty");
		return;
	}
	int flag = 0;
	while(temp != NULL)	{
		if(val == temp->data)
			flag=1;
		temp=temp->next;
	}
	if(flag == 1)
		printf("\n%d Found!",val);
	else
		printf("\n%d Not Found!",val);
} 
void insertloc(int val,int loc)	{
	struct node *temp=head,*post;
	
		while(temp != NULL)	{
			if(loc == temp->data)	{
				struct node *temp1=(struct node* )malloc(sizeof(struct node));
				temp1->data=val;
				temp->next=temp1;
				temp1->next=post;
				break;
			}
			temp= temp->next;
			post=temp->next;
		}
	
	return;
}
void removeduplicates()	{
	
	struct node *temp=head;
	if(temp == NULL)
		return;
	int i=0,j=0;
	int *visited=(int* )calloc(1000,sizeof(int));

	while(temp != NULL)	{
		visited[i++]=temp->data;
		temp=temp->next;
	}
	free(head);
	head=NULL;
	int *merged=(int* )calloc(1000,sizeof(int));	
	int k,flag=0,a=0,prev=0;
	for(j=0;j<i;j++)	{
		flag =0;
		while(visited[j] == prev)
			j++;
		for(k=0;k<i;k++)	{
			if(visited[j] == visited[k] )	{
				if(flag != 1)	
				{		
					merged[a++]=visited[j];			
					flag=1;
				}
				prev=visited[j];
			}
		}
	}
	for(j=0;j<a;j++)
		insert(merged[j],'e');
}
				
int main()
{
	
	int val,i=10;
	
	val=10;
	while(i<1000) {
		insert(val,'s');
		i=i+10;
	}
	val = 100;
	i=10;
	while(i<1000) {
		insert(i,'e');
		i=i+10;
	}
	printf("\nPrinting list:");
	display();
	printf("\nRemoving Duplicates");
	removeduplicates();
	printf("\nAfter removing duplicates Printing list:");
	display();	
	printf("\nEnter element to search:");
	scanf("%d",&val);
	search(val);
	printf("\nEnter element to delete:");
	scanf("%d",&val);
	delete(val);
	printf("\nAdd at front?");
	scanf("%d",&val);
	insert(val,'s');
	printf("\nAdd at end?");
	scanf("%d",&val);
	insert(val,'e');
	int loc;	
	printf("\nAdd at location?");
	scanf("%d %d",&loc,&val);
	insertloc(val,loc);
	printf("\nPrinting list:");
	display();
	return 0;
}





