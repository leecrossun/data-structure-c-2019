#include <stdio.h>
#include <stdlib.h>

typedef struct
	{
		int midterm;
		int final;
	} Score;
	
void printScore(Score *p)
	{
		printf("중간고사 성적은 %d\n", p->midterm);
		printf("학기말고사 성적은 %d\n", p->final); 
	}
Score *biggerScore(Score *p1, Score *p2)
{
	Score bigger;
	Score *p_bigger = &bigger;
	
	if (p1->midterm > p2->midterm)
		p_bigger->midterm = p1->midterm;
	else
		p_bigger->midterm = p2->midterm;
	if (p1->final > p2->final)
		p_bigger->final = p1->final;
	else
		p_bigger->final = p2->final;
		
	return p_bigger;
}
Score *totalScore(Score *p1, Score *p2)
{
	Score total;
	Score *p_total = &total;
	p_total->midterm = (p1->midterm + p2->midterm);
	p_total->final = (p1->final + p2->final);
	
	return p_total;
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
	Score s1 = {50,100}, s2 = {70,70}, s3;
	Score *p1 = &s1, *p2 = &s2, *p3 = &s3;
	
	printScore(p1);
	printScore(p2);
	
	printf("----------------------------\n");
	printf("둘중 성적이 좋은 점수:\n");
	printScore(biggerScore(p1, p2));	
	
	printf("----------------------------\n");
	printf("두 성적의 총합:\n");
	printScore(totalScore(p1, p2));
	
	printf("----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
}
