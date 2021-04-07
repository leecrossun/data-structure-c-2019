#include <stdio.h>
//순환연습2 (강의보충 8p) 20170581 이효선 
void print_fact_exp(int n)
{
	if(n <= 1)
		printf("1");
	else
	{
		printf("%d * ", n); 
		print_fact_exp(n-1);
	}
		
}
int main(void)
{
	int n;
	printf("Enter a number:");
	scanf("%d", &n);
	
	printf("%d! = ", n);
	print_fact_exp(n);
	printf("\n");	
}
