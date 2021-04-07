// HW4_3
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define MAX_STRING 100

typedef struct {
     int id;
     char name[MAX_STRING];
	 char tel[MAX_STRING];
	 char dept[MAX_STRING];
} element;
typedef struct TreeNode {
	element data;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode * search(TreeNode * node, int key)  // 조금 고쳐야
{	// 코드   
	if (node == NULL) return NULL;
	if (key == node->data.id) return node;
	else if (key < node->data.id)
		return search(node->left, key);
	else
		return search(node->right, key);
}

TreeNode * new_node(element data)  // 조금 고쳐야
{	// 코드   
	TreeNode * temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode * min_value_node(TreeNode * node) // 그대로
{
	TreeNode * current = node;

	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;

	return current;
}
 
TreeNode * delete_node(TreeNode * node, int key) // 조금 고쳐야
{	// 코드  
	if (node == NULL) return node;
	
	if (key < node->data.id) node->left = delete_node(node->left, key);
	else if (key > node->data.id) node->right = delete_node(node->right, key);
	else
	{
		if (node->left == NULL)
		{
			TreeNode *temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL)
		{
			TreeNode *temp = node->left;
			free(node);
			return temp;
		}
		else
		{
			TreeNode *temp = min_value_node(node->right);
			node->data.id = temp->data.id;
			node->right = delete_node(node->right, temp->data.id);
		}
	}
	return node;
}

//한 학생 정보 출력
void print_data(element * e)
{
     printf("-----------------------------------\n");
     printf("학번: %d\n", e->id);
     printf("이름: %s\n", e->name);
	 printf("전화번호: %s\n", e->tel);
	 printf("학과: %s\n", e->dept);
}
TreeNode * insert_node(TreeNode * node, element data) // 조금 고쳐야
{	// 코드    
	if (node == NULL) return new_node(data);
	if (data.id < node->data.id)
		node->left = insert_node(node->left, data);
	else if (data.id > node->data.id)
		node->right = insert_node(node->right, data);
}

// 중위 순회
void inorder(TreeNode * root)  // 조금 고쳐야
{	// 코드     
	if (root)
	{
		inorder (root->left);
		printf("[%d] ", root->data.id);
		inorder(root->right);
	}
}

int get_node_count(TreeNode *node)
{
     int count = 0;
     if (node != NULL)
          count = 1 + get_node_count(node->left) + get_node_count(node->right);
     return count;
}
int main(void)
{
     TreeNode *root = NULL;
     TreeNode *node;
     element data;
     char choice;
     int id;
     char name[MAX_STRING];
     char tel[MAX_STRING];
	 char dept[MAX_STRING];

     printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount), q(uit):");
     scanf("%c", &choice);
     while (choice != 'q') {
          switch (choice) {
          case 'i':
               printf("학번 입력:");
               scanf("%d", &id);
               printf("이름 입력:");
               scanf("%s", name);;
			   printf("전화번호 입력:");
               scanf("%s", tel);;
			   printf("학과 입력:");
               scanf("%s", dept);;

               data.id = id;
               strcpy(data.name, name);
               strcpy(data.tel, tel);
               strcpy(data.dept, dept);

               root = insert_node(root, data);
               break;
          case 'p':
               printf("학생 정보 학번 순 출력\n");
               inorder(root);
               printf("\n");
               break;
          case 'd':
               printf("삭제할 학번 입력:");
               scanf("%d", &id);
               delete_node(root, id);
               break;
          case 's':  
               printf("탐색할 학번 입력:");
               scanf("%d", &id);

               node = search(root, id);
               if (node != NULL)
                    print_data(&(node->data));
               else
                    printf("id가 %d인 학생은 없읍니다.\n", id);
               break;
          
          case 'c':
               printf("현재 저장된 학생의 총 수는 %d\n", get_node_count(root));
               break;
          }

          while (getchar() != '\n'); // 버퍼 비움
          printf("Enter i(nsert), d(elete), s(earch), p(rint), c(ount), q(uit):");
          scanf("%c", &choice);
     	}
          
     }     

