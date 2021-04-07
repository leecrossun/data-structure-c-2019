#include <stdio.h>
#include <stdlib.h>

// 차후에 스택이 필요하면 여기만 복사하여 붙인다. 
// ===== 스택 코드의 시작 ===== 
#define MAX_STACK_SIZE 6


typedef struct {
	short r;
	short c;
} element;

// 스택 초기화 함수
void init_stack(element *s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(element *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(element *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(element *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(element *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(element *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 


int main(void)
{
	element s;

	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}
