#include<stdio.h>


struct BST{
	int val;
	struct BST *lchild;
	struct BST *rchild;
};



void preorder(struct BST* tree)
{
	if(tree == NULL)
		return;

	printf("%d",tree->val);
	preorder(tree->lchild);
	preorder(tree->rchild);
}



void inorder(struct BST* tree)
{
	if(tree == NULL)
		return;

	inorder(tree->lchild);
	printf("%d",tree->val);
	inorder(tree->rchild);
}


void postorder(struct BST* tree)
{
	if(tree = NULL)
		return;
	postorder(tree->lchild);
	postorder(tree->rchild);
	printf("%d",tree->val);
}


int main(int argc,char** argv)
{





	return 0;
}



