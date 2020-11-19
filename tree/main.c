#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
}data_t;

struct node_st
{
	data_t data;
	struct node_st *left;
	struct node_st *right;
};

//插入
int tree_insert(struct node_st **root,const data_t *d)
{
	struct node_st *new = NULL;
	if(*root == NULL)
	{
		new = malloc(sizeof(*new));
		if(NULL == new)
			return -1;
		memcpy(&new->data,d,sizeof(data_t));
		new->left = new->right = NULL;
		*root = new;
		return 0;
	}
	if((*root)->data.id >= d->id)
		return tree_insert(&(*root)->left,d);
	else
		return tree_insert(&(*root)->right,d);
}
//遍历
void xian_travel(struct node_st *root)
{
	if(root == NULL)
		return ;
	else
	{
		printf("%d",root->data.id);
		xian_travel(root->left);
		xian_travel(root->right);
	}
}
void zhong_travel(struct node_st *root)
{
	if(root == NULL)
		return ;
	else
	{
		zhong_travel(root->left);
		printf("%d",root->data.id);
		zhong_travel(root->right);
	}
}
void hou_travel(struct node_st *root)
{
	if(root == NULL)
		return ;
	else
	{
		hou_travel(root->left);
		hou_travel(root->right);
		printf("%d",root->data.id);
	}
}
//释放destroy
void tree_destroy(struct node_st **root)
{
	if(*root == NULL)
		return ;
	tree_destroy(&(*root)->left);
	tree_destroy(&(*root)->right);
	printf("%d 将被销毁\n",(*root)->data.id);
	free(*root);
	*root = NULL;
}
//画树
void tree_show(struct node_st *root,int level)
{
	if(root == NULL)
		return ;
	tree_show(root->right,level+1);
	for(int i = 0;i < level;i++)
	{
		printf("    ");
	}
	printf("%d\n",root->data.id);
	tree_show(root->left,level+1);
}

int main(int argc,char *argv[])
{
	struct node_st *tree = NULL;
	data_t dt;

	if(argc < 2)
		return -1;
	for(int i = 0;argv[1][i];i++)
	{
		dt.id = argv[1][i] - '0';
		tree_insert(&tree,&dt);
	}
	tree_show(tree,0);
	printf("\n");
	printf("先序：");
	xian_travel(tree);
	printf("\n");
	printf("中序：");
	zhong_travel(tree);
	printf("\n");
	printf("后序：");
	hou_travel(tree);
	printf("\n");

	tree_destroy(&tree);
	
	return 0;
}
