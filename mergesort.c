#include <stdio.h>
#include <stdlib.h>

void merge(int *list, int *sorted, int begin, int mid, int end){
	int l_begin=begin, l_mid=mid+1, s_begin=begin, i=0;

	// 부분 정렬(정복) 
	while( l_begin<=mid && l_mid<=end ){
		if( list[l_begin] <= list[l_mid] ){
			sorted[s_begin] = list[l_begin];
			l_begin+=1;	s_begin+=1;
		}else{
			sorted[s_begin] = list[l_mid];
			l_mid+=1; s_begin+=1; 
		}
	}
	
	// 남아 있는 값들을 임시배열로 일괄 복사
	if(l_begin>mid)
		for(i=l_mid; i<=end; i++){
			sorted[s_begin] = list[i];
			s_begin += 1;	
		} 
	else
		for(i=l_begin; i<=mid; i++){
			sorted[s_begin] = list[i];
			s_begin += 1;
		}

	// 임시 배열을 list로 복사
	for(i=begin; i<=end; i++) list[i] = sorted[i];
}

// 합병 정렬
void merge_sort(int *list, int *sorted, int begin, int end){
	int mid;

	if(begin<end){
		mid = (begin+end)/2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
		merge_sort(list, sorted, begin, mid); // 1. 재귀 분할, 마지막 2~1개 남을때까지 -분할(Divide)
		merge_sort(list, sorted, mid+1, end); // 2. 부분 배열을 합병 -결합(Combine)
		merge(list, sorted, begin, mid, end); // 분할 부분 정렬 -정복(Conquer)
	}
}

void main(){
	int i;
	int n = 8;
	//int list[MAX_SIZE] = {21, 10, 12, 20, 25, 13, 15, 22};
	int *list = (int *)malloc(sizeof(int)*n);
	list[0]=21;list[1]=10;list[2]=12;list[3]=20;list[4]=25;list[5]=13;list[6]=15;list[7]=22;
	
	// 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)
	int *sorted = (int *)malloc(sizeof(int)*n);
	merge_sort(list, sorted, 0, n-1);
	free(sorted);

	// 정렬 결과 출력
	for(i=0; i<n; i++) printf("%d ", list[i]);
}
