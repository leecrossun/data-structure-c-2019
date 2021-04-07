#include <stdio.h>
#include <stdlib.h>
// 문헌정보학과 20170581 이효선 
typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;

// 오류 처리 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 노드 pre 뒤에 새로운 노드 삽입
ListNode*  insert_next(ListNode *head, ListNode *pre, element value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;		//(4)	
	return head;		//(5)	

}

ListNode* insert_first(ListNode *head, int value)
{
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;					// (2)
	p->link = head;	// 헤드 포인터의 값을 복사	//(3)
	head = p;	// 헤드 포인터 변경		//(4)

	return head;	// 변경된 헤드 포인터 반환
}

ListNode* insert_last(ListNode *head, int value)
{

	ListNode *temp = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)
	p->data = value;	
	p->link = NULL;
	// (2)
	if (head == NULL) // 공백 리스트이면
		head = p;
	else {
		while (temp->link != 0) 
			temp = temp->link;

		temp->link = p;
	}


	return head;	//헤드 포인터 반환
}
// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete_next(ListNode *head, ListNode *pre) // pre가 정확이 있다고 가정(NULL이 아니고)
{
	ListNode *removed;
	removed = pre->link;
	pre->link = removed->link;		// (2)
	free(removed);			// (3)

	return head;			// (4)
}
void print_list(ListNode *head)
{
	ListNode *p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

ListNode *search(ListNode *head, int x)
{
	ListNode *p;
	p = head;
	while( p != NULL ){
		if( p->data == x ) return p;              // 탐색 성공
		p = p->link;
	}
	return NULL;  // 탐색 실패일 경우 NULL 반환



}
ListNode *concat(ListNode *head1, ListNode *head2)
{
	ListNode *p;
	if( head1 == NULL ) return head2;
	else if( head2 == NULL ) return head1;
	else {
		p = head1;             
		while( p->link != NULL ) 
			p = p->link;    
		p->link = head2;        
		return head1;           



	}
}
ListNode *reverse(ListNode *head)
{
   // 순회 포인터로 p, q, r을 사용
   ListNode *p, *q, *r;
   p = head;         // p는 역순으로 만들 리스트
   q = NULL;         // q는 역순으로 만들 노드
   while (p != NULL){
       r = q;            // r은 역순으로 된 리스트.    r은 q, q는 p를 차례로 따라간다.
       q = p          ;
       p = p->link     ;
       q->link =r;      // q의 링크 방향을 바꾼다.
    }
    return q; 	// q는 역순으로 된 리스트의 헤드 포인터



}

ListNode* delete_first(ListNode *head)
{
	ListNode *removed;
	if (head == NULL) error("삭제할 항목이 없음");
	removed = head;	// (1)
	head = removed->link;	// (2)
	free(removed);		// (3)
	return head;		// (4)

}

ListNode* delete_last(ListNode *head)
{
	ListNode *temp = head;
	ListNode *prevTemp;
	ListNode *removed;
	if (head == NULL) error("삭제할 항목이 없음");
		if (temp->link == NULL) { // 하나의 노드
		removed = temp->link;
		free(removed);
		return NULL;
	}
	else { // 둘 이상의 노드

		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}
		removed = temp;
		prevTemp->link = NULL;
		free(removed);
		return head; // 그대로
	}
}
// item이 리스트에 있으면 1을 아니면 0을 반환
int is_in_list(ListNode *head, element item)
{
	ListNode *p;
	p = head;
	while( p != NULL ){
		if( p->data == item ) return 1;  
		p = p->link;
	}
	return 0; 
}
int get_length(ListNode *head)
{
	int length = 0;
	while ( head != NULL )
	{
		head = head->link;
		length++;
	}
	return length;
}
int get_total(ListNode *head)
{
	int sum = 0;
	while ( head != NULL )
	{
		sum += head->data;
		head = head->link;
	}
	return sum;
}
element get_entry(ListNode *head, int pos)
{
	int i = 0;
	while ( i != pos )
	{
		head = head->link;
		i++;
	}
	return head->data;
}
ListNode * insert_pos(ListNode *head, int pos, element value)
{
	int i = 0;
	ListNode *preTemp = head;
	ListNode *temp = head;
	ListNode *p = (ListNode *)malloc(sizeof(ListNode));	//(1)

	while ( i != pos - 1)
	{
		preTemp = temp;
		temp = temp->link;
		i++;
	}
	p->data = value;					// (2)
	p->link = temp->link;
	preTemp->link->link = p;

	return head;	
}
ListNode * delete_pos(ListNode *head, int pos)
{
	int i = 0;
	ListNode *temp = head;
	ListNode *prevTemp;
	ListNode *removed;
	if (head == NULL) error("삭제할 항목이 없음");
		if (temp->link == NULL) { // 하나의 노드
		removed = temp->link;
		free(removed);
		return NULL;
	}
	else { // 둘 이상의 노드

		while ( i != pos)
		{
			prevTemp = temp;
			temp = temp->link;
			i++;
		}
		removed = temp;
		prevTemp->link = temp->link;
		free(removed);
		return head; // 그대로
	}
}
int main(void)
{
	ListNode *list1 = NULL, *list2 = NULL, *list3;
	
	//list1 = 30->20->10->를 만든다. 이때 10, 20, 30의 순으로 노드를 삽입한다.
	list1 = insert_first(list1, 10);
	list1 = insert_first(list1, 20);
	list1 = insert_first(list1, 30);
	// list1을 출력
	printf("list1 = ");
	print_list(list1);

	//list1의 맨 앞 노드를 삭제한다 즉, list1 = 20->10->
	list1 = delete_first(list1);
	// list1을 출력
	print_list(list1);

	//list2 = 11->22->33->44->를 만든다. 이때 11, 22, 33, 44의 순으로 노드를 삽입한다.
	list2 = insert_last(list2, 11);
	list2 = insert_last(list2, 22);
	list2 = insert_last(list2, 33);
	list2 = insert_last(list2, 44);
	
	// list2를 출력
	print_list(list2);
	// list2의 맨 뒤 노드를 삭제한다. 즉, list2 = 11->22->33->
	list2 = delete_last(list2);
	// list2를 출력
	print_list(list2);
	//list2를 역순으로 바꾼 리스트를 list3가 가리키게 한다. list3 = 33->22->11->를 만든다.
	list3 = reverse(list2);
	//list3를 출력한다.  
	print_list(list3);
	// list1 = 20->10->33->22->11->를 만든다. 즉, list1과 list3를 합쳐서 list1이 가리키게 한다.
	list1 = concat(list1, list3);
	//list1을 출력한다.
	print_list(list1);
	//(A) 주의: 여기서부터는 list1만 사용하여 함수들을 테스트하자4
	// 20 탐색 (있으므로 1 출력) 
	printf("%d\n", is_in_list(list1, 20));
	// 21 탐색 (없으므로 0 출력) 
	printf("%d\n", is_in_list(list1, 21));
	// 길이(5) 출력
	printf("%d\n", get_length(list1)); 
	// 합(96) 출력 
 	printf("%d\n", get_total(list1));
 	// pos = 2 의 값 (33) 출력
	printf("%d\n", get_entry(list1, 2)); 
	// pos = 2 위치에 value 55 추가 추 출력 20->10->55->33->22->11->
	list1 = insert_pos(list1, 2, 55); 
	print_list(list1);
	// pos = 1 의 값 삭제 후 출력  20->55->33->22->11->
	list1 = delete_pos(list1, 1); 
	print_list(list1);
}

