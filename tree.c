#include<stdio.h>
#include<stdlib.h>

struct tree	{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* root = NULL;
struct tree* ptr = NULL;

void create()	{
	struct tree* node;
	node = (struct tree* )malloc (sizeof(struct tree));
	printf("Enter root data\n");
	scanf("%d",&node->data);
	node -> right = NULL;
	node -> left = NULL;
	root = node;
	ptr = root;
	
	ptr -> left = NULL;
	ptr -> right = NULL;
	
}

void insert()	{
	int key;
	struct tree* node;
	node = (struct tree*)malloc (sizeof(struct tree));
	
	printf("\nEnter the data:");
	scanf("%d",&key);
	
	node -> data = key;
	if(node -> data > ptr -> data )
	{
		ptr -> right = node;
		ptr = node;
	}
	else
	{
		ptr -> left = node;
		ptr = node;
	}
	ptr -> left = NULL;
	ptr -> right = NULL;
}

void display()	{
	struct tree* node;
	node = root;

	printf("\nRoot: %d",node->data);
	
	while(node != NULL)	{
		if(node -> right != NULL)
			printf("\n Right:%d ",node ->right-> data);
		else
			printf("\nNothing up here man!");
		node = node -> right;
	}	
	node = root;
	while(node != NULL)	{
		 if( node -> left != NULL)
                      printf("\nLeft: %d ",node -> left -> data);
		 else if (node -> right != NULL)
			printf("\nRight: %d ",node ->right -> data);
		else
			printf("\nNothing up here too man!");
		node = node -> left;
	}
}

int main()	{
	create();
	int i ;
	for(i = 0;i < 4; i++)	
		insert();
	display();
}
