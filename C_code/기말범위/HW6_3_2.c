#include <stdio.h>
#define TRUE 1
#define FALSE 0

#define VERTICES 6
#define INF 1000L

int weight[VERTICES][VERTICES]={
{  0, 10, INF,  20,  70, INF },
{ 10,  0,  50,  30,  60, INF}, 
{ INF,50,   0, INF,  40, INF},
{ 20, 30, INF,   0, INF, 80},
{ 70, 60,  40, INF,   0, INF},
{ INF,INF,INF,  80, INF,   0}};

int selected[VERTICES]; // 0으로 초기화, 즉 선택된 <신장트리집합>은 공집합으로 시작
int dist[VERTICES]; // <신장트리집합>내의 정점과의 최소거리
int connected[VERTICES];	
// for all v such as selected[v] == FALSE, dist[v]가 최소값인 v를 반환
int get_min_vertex(int n)
{
  int v,i;
  for (i = 0; i <n; i++)
    if (!selected[i]) {
      v = i; 
	  break;
    }
  for (i = 0; i < n; i++)
    if ( !selected[i] && (dist[i] < dist[v])) v = i;
  return (v);
}

void prim(int s, int n) // s는 시작점, n은 정점개수
{
	int i, u, v;
	int a;

	for(u = 0; u < n; u++) {
		dist[u] = INF;
	}

	// 시작 정점인 s의 거리를 변경 
	dist[s] = 0;

	for(i=0;i<n;i++)
	{
		u = get_min_vertex(n); // 선택안 된 정점 중에서 dist[u]가 가장 적은 정점 u를 찾음
		selected[u]=TRUE; // <신장트리집합>에 u를 포함시킴
		printf("\n<%d %d> %d\n", connected[u], u, weight[u][connected[u]]);

		printf("selected[] =\t");
		for (a = 0; a < n; a++)
			printf("%5d ", selected[a]);
		printf("\n");

		// u를 <신장트리집합>에 포함시키면서 dist[..]를 재조정
		for(v = 0; v < n; v++)
				if(!selected[v] && weight[u][v]< dist[v]) 
				{
					dist[v] = weight[u][v];
					connected[v] = u;
				}

		printf("dist[] =\t");
		for (a = 0; a < n; a++)
			printf("%5d ", dist[a]);
		printf("\n");

	}
}
//
main()
{
	prim(0, VERTICES);
}
