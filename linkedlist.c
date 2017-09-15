#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	struct node *next;
};

struct node *head=NULL;
struct node *tail=NULL;


void create(int val) {
	struct node *temp;
	temp=(struct node* )malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	head=tail=temp;

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
			tail->next=temp;
			tail=temp;	
		}
		else if(place == 's')	{
			temp->next=head;
			head=temp;	
		}	
	}
}

struct node* reverse(struct node *head)	{
	struct node *newnode=NULL;
	tail=head;
	while(head){
		struct node *next=head->next;
		head->next = newnode;
		newnode = head;
		head=next;
	}
	return newnode;
}

void deleteElement(int val,struct node *head) {
		static struct node *prev=NULL;
		if(head == NULL)
			return;
		if(head->data == val){
			prev->next=head->next;
			free(head);
			head=prev;
		}		
		else	{
			prev=head;
			deleteElement(val,head->next);	
		}
		
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
	struct node *temp=head;
	
		while(temp != NULL)	{
			if(loc == temp->data)	{
				struct node *temp1=(struct node* )malloc(sizeof(struct node));
				temp1->data=val;
				temp1->next=temp->next;
				temp->next=temp1;
				break;
			}
			temp= temp->next;
			
		}
	
	return;
}
void removeduplicates()	{
	
	struct node *temp=head,*prev;
	
	if(temp == NULL)
		return;
	set<int > s;
	for(temp=head;temp!=NULL;temp=temp->next){
		if(s.find(temp->data) == s.end())
			s.insert(temp->data);
		else{
			prev->next=temp->next;
			free(temp);
			temp=prev;
		}
		prev=temp;
	}
		
}
				
int main()
{
	
	int val,i=10;
	
	val=10;
	while(i<1000) {
		insert(val*i,'s');
		i=i+10;
	}
	val = 100;
	i=10;
	while(i<1000) {
		insert(i,'e');
		i=i+10;
	}
	head=reverse(head);

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
	deleteElement(val,head);

	printf("\nAdd at front?");
	scanf("%d",&val);
	insert(val,'s');
	display();

	printf("\nAdd at end?");
	scanf("%d",&val);
	insert(val,'e');
	display();

	int loc;	
	printf("\nAdd at location?");
	scanf("%d %d",&loc,&val);
	insertloc(val,loc);

	printf("\nPrinting list:");
	display();

	return 0;
}




