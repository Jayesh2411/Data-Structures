#include<stdio.h>
#include<stdlib.h>

struct doublel {
	int data;
	struct doublel *prev,*next;
};


struct doublel *head=NULL;

void create(int val)	{
	printf("Creating Head Node!\n");
	struct doublel *temp;
	temp=(struct doublel*)malloc(sizeof(struct doublel));
	temp->data=val;
	temp->prev=NULL;
	temp->next=NULL;
	head=temp;
	return;
}

void insert(int val)	{
	struct doublel *temp=head,*p;
	if(head==NULL){
		create(val);
		return;
	}
	else{	
		while(temp->next!=NULL)
			temp=temp->next;
		p=(struct doublel*)malloc(sizeof(struct doublel));
		p->data=val;
		p->next=NULL;
		temp->next=p;
		p->prev=temp;
	}
	return;
}
void display(struct doublel *t)	{
	
	if(!t)
		return;
	printf("\n%d",t->data);
	display(t->next);
}
	
int main()	{
	int val,i=10;
	while(i<=100)	{
		insert(i);
		i=i+10;
		printf("%d Inserted\n",i);
	}
	printf("Data Inserted!\n");
	printf("\nData:");
	display(head);
}
