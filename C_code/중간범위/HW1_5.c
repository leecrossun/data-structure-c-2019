#include <stdio.h>
#include <stdlib.h>
// 이중 연결 리스트 
typedef int element;
typedef struct DListNode {	// 이중연결 노드 타입
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

// 이중 연결 리스트를 초기화
void init(DListNode* phead)
{
	phead->llink = phead;
	phead->rlink = phead;
}

// 이중 연결 리스트의 노드를 출력
void print_dlist(DListNode* phead)
{
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink)
	{
		printf("<-| |%d| |-> ", p->data);
	}
	printf("\n");
}

// 새로운 데이터를 노드 before의 오른쪽에 삽입한다.
void dinsert(DListNode *before, element data)
{
	DListNode *newnode = (DListNode *)malloc(sizeof(DListNode));
	newnode->data = data;

	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;

}
// 노드 removed를 삭제한다.
void ddelete(DListNode* head, DListNode* removed)
{
	if (removed == head) return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);

}

// 거꾸로 출력하기 
void print_reverse_dlist(DListNode* head)
{
	DListNode *p;
	for (p = head->rlink; p != head; p = p->rlink)
		printf("<-| |%d| |->", p->data);
	printf("\n");
}

// data를 갖는 값을 찾아서 반환 
DListNode* search(DListNode *head, element data)
{
	DListNode *p;
	while (p->data != data)
	{
		p = p->llink;
	}
	return p->data;
}
int main(void)
{
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);
	printf("추가 단계\n");
	
	// 맨 앞에 노드를 삽입
	dinsert(head, 10);
	print_dlist(head);
	dinsert(head, 20);
	print_dlist(head);
	dinsert(head, 30);
	print_dlist(head);
	
	// 맨 뒤에 노드를 삽입하려면?
	dinsert(head->llink, 99);
	print_dlist(head);
	
	printf("\n삭제 단계\n");
	// 맨 앞의 노드를 삭제
	ddelete(head, head->rlink);
	print_dlist(head);
	
	// 맨 뒤의 노드를 삭제하려면?
	ddelete(head, head->llink);
	print_dlist(head);
	
	printf("거꾸로 출력하기\n"); 
	print_reverse_dlist(head);

	printf("값 찾기\n"); 
	printf("<-| |%d| |->", search(head, 20));
		free(head);
	return 0;
}

