#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
int main()
{
	int i,n,value;
	struct node*head=NULL;
	struct node*temp=NULL;
	printf("enter the size");
	scanf("%d",&n);
	printf("enter elements");
	for(i=0;i<n;i++){
		struct node*newnode=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&value);
		newnode->data=value;
		newnode->next=NULL;
		if(head==NULL){
			head=newnode;
			head=temp;
			
		}
		else{
			head=temp;
			temp->next=newnode;
			temp=temp->next;
		}
		
	}
	temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
}
