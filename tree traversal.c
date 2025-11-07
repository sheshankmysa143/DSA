#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *right,*left;
};
struct node*create(){
	int x;
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));

	printf("enter the data");
	scanf("%d",&x);
	if(x==-1){
		return 0;
	}
		newnode->data=x;
	
	printf("enter left node");
	newnode->left=create();
	printf("enter right node");
	newnode->right=create();
	return newnode;
	
}
void preorder(struct node*root){
	if(root==0){
		return ;
	}
	printf("%d",root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(struct node*root){
	if(root==0){
		return ;
	}
		inorder(root->left);
	printf("%d",root->data);

	inorder(root->right);
}
void postorder(struct node*root){
	if(root==0){
		return ;
	}
		postorder(root->left);
		postorder(root->right);
	printf("%d",root->data);

	
}
int main()
{
	struct node*root;
	root=0;
	root=create();
	printf("preorder");
	preorder(root);
	printf("inorder");
	inorder(root);
	printf("post order");
	postorder(root);
	
}
