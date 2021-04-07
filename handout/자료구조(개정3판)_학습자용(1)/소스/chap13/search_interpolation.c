#include <stdio.h>

#define MAX_SIZE 1000
int list[MAX_SIZE];

//
//
//
init_list()
{
	int i;
	for(i=0;i<1000;i++)
		list[i] = 7*i;
}

//
int search_binary(int key, int low, int high)
{  
   int middle;
   if(low<=high){
      middle = (low+high)/2;
      if(key==list[middle])    // 탐색 성공
	   return middle;
      else if(key<list[middle]) // 왼쪽 부분리스트 탐색 
	   return search_binary(key, low, middle-1);
      else                   // 오른쪽 부분리스트 탐색 
	   return search_binary(key, middle+1, high);
     }
   return -1;        // 탐색 실패
}

int search_binary2(int key, int low, int high)	
{  
  int middle;   

	while( low <= high ){       // 아직 숫자들이 남아 있으면
	   middle = (low+high)/2;   
	   if( key == list[middle] )
			return middle;
		else if( key > list[middle] )
			low = middle+1;
		else 
			high = middle-1;
	}   
	return -1;   // 발견되지 않음 
}

//
int search_interpolation(int key, int n)
{
     int low, high, j;
     low = 0;
     high = n-1;
	 while ((list[high] >= key) && (key > list[low])){
          j = ((float)(key-list[low]) / (list[high]-list[low]) *
                         (high-low) ) + low;
          if( key > list[j] ) low = j+1;
          else if (key < list[j]) high = j-1;
          else low  = j;
	 }
     if (list[low] == key) return(low);  //found(r[low])
     else return -1;  // notfound(key)
}

//
void main()
{
		int i =0;
		init_list();
		i = search_binary2(49, 0, 999);
		if( i >= 0 ) {
			printf("탐색 성공 i=%d\n", i);
		}
		else {
			printf("탐색 실패\n");
		}
}


