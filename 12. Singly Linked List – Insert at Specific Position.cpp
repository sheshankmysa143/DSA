#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;};
int main()
{
	struct node*temp=NULL;
	struct node*head=NULL;
	int i,value,n,pos;
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
	//insertion 
	printf("enter position\n");
	scanf("%d",&pos);
	printf("enter the value which should be inserted\n");
	scanf("%d",&value);
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
	newnode->next=NULL;
	if(pos<1 || pos>n+1){
		printf("invalid\n");
		return 1;
	}
	if(pos==1){
		newnode->next=head;
		head=newnode;
	}
	else{
		temp=head;
		for(i=0;i<pos-1;i++){
			temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
		}
		temp=head;
	while(temp!=NULL){
		printf("%d ->",temp->data);
		temp=temp->next;
	}
		printf("NULL");
}
