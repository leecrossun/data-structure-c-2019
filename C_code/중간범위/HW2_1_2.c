#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 3
#define MAX_STRING 100

typedef struct {
	int num;
	char letter[MAX_STRING];
} element;
typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init(StackType *s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[--(s->top)];
}
// 피크함수
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[s->top];
}
// 스택 출력 함수
void stack_print(StackType *s) 
{
	if (is_empty(s))
		printf("<empty>\n");
	else
	{
		int i = s->top;
		printf("[%d, %s] <-- top\n", s->stack[i].num, s->stack[i].letter);
		for (i = s->top-1; i > -1; i--)
			printf("[%d, %s]\n", s->stack[i].num, s->stack[i].letter);
		printf("--\n");
			
	}
}
// ===== 스택 코드의 끝 ===== 


int main(void)
{
	StackType s;
	element e;
	
	init(&s);
	stack_print(&s);
	
	e.num = 10;
	strcpy(e.letter, "ten");
	push(&s, e);
	stack_print(&s);
	
	e.num = 20;
	strcpy(e.letter, "twenty");
	push(&s, e);
	stack_print(&s);
	
	e.num = 30;
	strcpy(e.letter, "therty");
	push(&s, e);
	stack_print(&s);
	
	e.num = 40;
	strcpy(e.letter, "fourty");
	push(&s, e);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	
	e.num = 50;
	strcpy(e.letter, "fifty");
	push(&s, e);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
	
	pop(&s);
	stack_print(&s);
}
