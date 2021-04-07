#define MAX_ELEMENTS 100
int scores[MAX_ELEMENTS];	// 자료구조

int get_max_score(int n) 	// 학생의 숫자는 n
{
	int i, largest;
	largest = scores[0];	// 알고리즘
	for (i = 1; i<n; i++) {
		if (scores[i] > largest) {
			largest = scores[i];
		}
	}
	return largest;
}