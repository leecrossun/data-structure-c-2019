#include <stdio.h>
#include <string.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	100		/* 노드의 수 */
#define INF 	9999		/* 무한 값(연결이 없는 경우) */

int distance[MAX_VERTICES];	/* 시작노드로부터의 최단경로 거리 */
int previous[MAX_VERTICES];	/* 경유 노드  */
int found[MAX_VERTICES];	/* 방문한 노드 표시 */

typedef struct GraphType {
	int n;					// 정점의 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 지하철역명 
typedef struct station 
{
	char name[INF];
}STATION;
// 그래프 초기화 
void graph_init(GraphType *g)
{
	int r,c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = INF;

     for (r = 0; r < MAX_VERTICES; r++) // pak 추가, 자기자신에로의 거리를 0으로
          g->adj_mat[r][r] = 0;
}

/*  */
void read_graph(GraphType *g, char *filename)
{
	int n, u, v;
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) { 
		fprintf(stderr, "파일 %s을 열 수 없음!\n", filename); return;  
	}
	fscanf(fp, "%d\n", &n);
	g->n = n;
	while (fscanf(fp, "%d %d", &u, &v) != EOF) {
		fscanf(fp, "%d\n", &g->adj_mat[u][v]);
		g->adj_mat[v][u] = g->adj_mat[u][v];
	}
	fclose(fp);
}

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i=0; i < n; i++)
		if (distance[i] < min && ! found[i]) {
			min = distance[i];
			minpos=i;
		}
	return minpos;
}

void print_path(STATION *s, int start, int end) // 역을 출력할 수있게 수정
{  
	if (start == end) 
		printf("%s", s[start].name);
	else {
		print_path(s, start, previous[end]);
		printf("-> %s ", s[end].name);
	}
}

void shortest_path(STATION *s, GraphType *g, int start, int end)
{  
	int i, u, w;
	for(i=0; i<g->n; i++) /* 초기화 */
	{
		distance[i] = g->adj_mat[start][i];
		found[i] = FALSE;
        previous[i] = start;
	}

	found[start] = TRUE;    /* 시작노드 방문 표시 */
	distance[start] = 0;	
     
     for(i = 0; i < (g->n)-1; i++) {
		u = choose(distance, g->n, found); 
		found[u] = TRUE;
    
		for(w=0; w<g->n; w++) {
			if(!found[w])
				if( distance[u] + g->adj_mat[u][w] < distance[w] ) {
					distance[w] = distance[u] + g->adj_mat[u][w];	
					previous[w] = u;		/* 경유노드 저장 */
                    }
		}
		// 도착점 선택 시 조기종료 
		if (u==end)
			break;
	 }
	// 경로와 거리 출력 
	print_path(s, start, end);
    printf(" (%d)\n", distance[end]);
}

void main()
{
	GraphType g;		// 입력 그래프
	char start[50], dest[50];
    int i, sIndex, dIndex;
    char sName[10], dName[10];
	STATION st [12] = {"월곡","동대문","종로3가","시청","서울역","을지로3가","충무로","동대문역사","약수","청구","신당","종묘"};
    graph_init(&g);
     
	read_graph(&g, "input.txt");
	
     printf("시작점:");
     scanf("%s", sName);
     
    for(i = 0; i < 12; i++)
    {
    	if (strcmp(st[i].name, sName) == 0)
    		sIndex = i;
	}
	 
    printf("도착점:");
    scanf("%s", dName);
     
    for(i = 0; i < 12; i++)
    {
    	if (strcmp(st[i].name, dName) == 0)
    		dIndex = i;
	}
	shortest_path(st, &g, sIndex, dIndex);
}
