#include <stdio.h>
#include <stdlib.h>

typedef struct
	{
		int midterm;
		int final;
	} Score;
	
void printScore(Score p)
	{
		printf("중간고사 성적은 %d\n", p.midterm);
		printf("학기말고사 성적은 %d\n", p.final); 
	}
Score biggerScore(Score p1, Score p2)
{
	Score bigger;
	
	if (p1.midterm > p2.midterm)
		bigger.midterm = p1.midterm;
	else
		bigger.midterm = p2.midterm;
	if (p1.final > p2.final)
		bigger.final = p1.final;
	else
		bigger.final = p2.final;
		
	return bigger;
}
Score totalScore(Score p1, Score p2)
{
	Score total;
	total.midterm = (p1.midterm + p2.midterm);
	total.final = (p1.final + p2.final);
	
	return total;
}
Score *createScore(int m, int f)
{
	Score pnew;
	Score *p_pnew = &pnew;
	p_pnew->midterm = m;
	p_pnew->final = f;
	return p_pnew; 
}
int main(void)
{
	Score s1 = {50,100}, s2 = {70,70};
	Score *p3;
		
	printScore(s1);
	printScore(s2);
	
	printf("----------------------------\n");
	printf("둘중 성적이 좋은 점수:\n");
	printScore(biggerScore(s1, s2));	
	
	printf("----------------------------\n");
	printf("두 성적의 총합:\n");
	printScore(totalScore(s1, s2));
	
	printf("----------------------------\n");
	p3 = createScore(100, 100);
	printScore(*p3);
}
