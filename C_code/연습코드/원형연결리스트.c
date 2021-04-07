#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
}ListNode;
// 출력
void print_list (ListNode *head)
{
	ListNode *p = head->link;
	if (head->link == head)
	{
		printf("%d->", head->data);
		printf("\n");
	}
	else
	{
		do
		{
			printf("%d->", p->data);
			p = p->link;
		} while (p != head);
		printf("%d->", p->data);
		printf("\n");
	}

} 
// 삽입 
ListNode* insert_first (ListNode *head, element data)
{
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->link = node;
	}
	else
	{
		node->link = head->link;
		head->link = node;
	}
	return head;
}
ListNode* insert_last (ListNode *head, element data)
{
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL)
	{
		head = node;
		node->link = node;
	}
	else
	{
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
// 삭제 
ListNode* delete_first (ListNode *head)
{
	ListNode *temp;
	if (head == NULL)
	{
		printf("리스트가 비어 삭제를 못함\n");
		return NULL; 
	}
	else
	{
		if (head->link == head)
		{
			temp = head;
			head = NULL;
			free(temp);
		}
		else
		{
			temp = head->link;
			head->link = head->link->link;
			free(temp);
		}
	}
	return head;
}
ListNode* delete_last (ListNode *head)
{
	ListNode* removed = head;
	ListNode* temp = head;
	if (head == NULL)
	{
		printf("리스트가 비어있음\n");
		return NULL; 
	}
	else
	{
		while (temp->link != head)
		{
			temp = temp->link;
		}
		head = temp;
		head->link = removed->link;
		free(removed);
	}
	return head;
}
// 탐색 
ListNode* search (ListNode *head, element data)
{
	ListNode *temp = head;
	while (temp->data != data)
	{
		temp = temp->link;
	}
	return temp;
}
// 크기반환 
int get_size (ListNode *head)
{
	ListNode *temp = head;
	int size = 1;
	if (head == NULL)
		return 0;
	else
	{
		while (temp->link != head)
		{
			temp = temp->link;
			size++;
		}	
	}
	
	return size;
}
//메인
int main(void)
{
	ListNode *head = NULL;

	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);
	
	head = insert_last(head, 30);
	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);

	head = delete_first(head);
	print_list(head);
	
//	printf("%d\n", search(head, 30));
	printf("%d\n", get_size(head));
	
	head = delete_last(head);
	print_list(head);
	printf("%d\n", get_size(head));
	head = delete_last(head);
	print_list(head);
	printf("%d\n", get_size(head));
	/**/
	return 0;

} 
