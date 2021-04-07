#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define TRUE 1
#define FALSE 0
#define MAX_TREE_SIZE 20

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
}TreeNode;

TreeNode n1 = {15, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {15, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

TreeNode m1 = {15, NULL, NULL};
TreeNode m2 = {4, &n1, NULL};
TreeNode m3 = {16, NULL, NULL};
TreeNode m7 = {28, NULL, NULL};
TreeNode m4 = {25, NULL, &m7};
TreeNode m5 = {15, &m3, &m4};
TreeNode m6 = {15, &m2, &m5};
TreeNode *root2 = &m6;

int get_nonleaf_count(TreeNode *t)
{
    int count = 0;
    if( !t )
		 return count;
	if( t->left != NULL || t->right != NULL)
		 count = 1 + get_nonleaf_count(t->left) + get_nonleaf_count(t->right);

    return count;
}
int get_twoleaf_count(TreeNode *t)
{
	int count = 0;
    if( !t )
		 return count;
	if( t->left != NULL && t->right != NULL)
		 count = 1 + get_twoleaf_count(t->left) + get_twoleaf_count(t->right);

    return count;
}
int equal(TreeNode *t1, TreeNode *t2)
{
	if ((t1 == NULL) && (t2 == NULL))
		return 1;
	else if ((t1 != NULL) && (t2 != NULL))
	{
		if(equal(t1->left, t2->left))
		{
			if(equal(t1->right, t2->right))
			{
				if(t1->data == t2->data)
					return 1;
			}
		}
	}
	return 0;
}
int get_oneleaf_count(TreeNode *t)
{
	int count = 0;
    if( !t )
		 return count;
	if( (t->left != NULL && t->right == NULL)||(t->left == NULL && t->right != NULL))
		 count = 1 + get_oneleaf_count(t->left) + get_oneleaf_count(t->right);

    return count;
}
int get_max(TreeNode *t)
{
	int value, left, right, max = 0;
	if (!t)
	{
		value = t->data;
		left = get_max(t->left);
		right = get_max(t->right);
		if (left < right)
			max = right;
		else
			max = left;
		if (value > max)
			max = value;
	}
	return max;
}
int get_min(TreeNode *t)
{
	int value, left, right, min = t->data;
	if (!t)
	{
		value = t->data;
		left = get_min(t->left);
		right = get_min(t->right);
		if (left > right)
			min = right;
		else
			min = left;
		if (value < min)
			min = value;
	}
	return min;
}
void node_increase(TreeNode *t)
{
	if (t)
	{
		t->data++;
		node_increase(t->left);
		node_increase(t->right);
	}
}
void preorder(TreeNode *t)
{
	if (t)
	{
		printf("%d", t->data);
		preorder(t->left);
		preorder(t->right);
	}
}
int search(TreeNode *root, int key, TreeNode *result[])
{
	int count = 0;
	if (root == NULL) return count;
	if (key == root->data)
	{
		result[count++] = root;
	}
	else if (key < root->data)
		return search(root->left, key, result);
	else
		return search(root->right, key, result);
}
TreeNode *copy(TreeNode *t)
{
	TreeNode *temp;
	if (t == NULL)
		return NULL;
		
	temp = (TreeNode*)malloc(sizeof(TreeNode));
	
	temp->left = copy(t->left);
	temp->right = copy(t->right);
	temp->data = t->data;
	
	return temp;
}
int main(void)
{
	TreeNode *result [MAX_TREE_SIZE];
	TreeNode *clone;
	int i, num;
	
	printf("트리 root중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root)); 
	printf("트리 root2중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2)); 
	
	printf("트리 root중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root)); 
	printf("트리 root2중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2)); 
	
	printf("트리 root중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
	printf("트리 root2중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));
	
	printf("트리 root중 가장 큰 수는 %d.\n", get_max(root));
	printf("트리 root2중 가장 큰 수는 %d.\n", get_max(root2));
	
	printf("트리 root중 가장 작은 수는 %d.\n", get_min(root));
	printf("트리 root2중 가장 작은 수는 %d.\n", get_min(root2));
	
	num = search(root, 15, result);
	for (i = 0; i < num; i++)
		printf("(0x%p, %d), ", result[i], result[i]->data);
	printf("\n");
	
	printf("%s\n", equal(root, root) ? "같다" : "다르다");
	printf("%s\n", equal(root2, root2) ? "같다" : "다르다");
	printf("%s\n", equal(root, root2) ? "같다" : "다르다");
	
	clone = copy(root);
	preorder(root);
	printf("\n");
	preorder(clone);
	printf("\n");
	 
}
