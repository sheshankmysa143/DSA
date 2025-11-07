#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
int main()
{
	struct node*temp=NULL;
	struct node*head=NULL;
	int i,value,n;
	printf("enter the size of linked list\n");
	scanf("%d",&n);
	printf("enter elements\n");
	for(i=0;i<n;i++){
			struct node*newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&value);
	
		newnode->data=value;
		newnode->next=NULL;
		if(head==NULL){
			head=newnode;
			temp=head;
		}
		else{
			temp->next=newnode;
			temp=temp->next;
		}
		
	}
	temp=head;
	while(temp!=NULL){
		printf("%d ->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
	
}
