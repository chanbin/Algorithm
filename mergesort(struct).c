#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int begin;
	int end;
}Node;

void merge(Node **list, Node **sorted, int begin, int mid, int end){
	int l_begin=begin, l_mid=mid+1, s_begin=begin, i=0;
	
	// 부분 정렬(정복) end로 선 정렬 후 begin으로 정렬 
	while( l_begin<=mid && l_mid<=end ){
		if( list[l_begin]->end < list[l_mid]->end ){
			sorted[s_begin]->begin = list[l_begin]->begin;
			sorted[s_begin]->end = list[l_begin]->end;
			l_begin+=1;	s_begin+=1;
		}else if(list[l_begin]->end == list[l_mid]->end){ // 동일한 end값 일 때 
			if(list[l_begin]->begin < list[l_mid]->begin){ // begin 값을 비교하여 정복 
				sorted[s_begin]->begin = list[l_begin]->begin;
				sorted[s_begin]->end = list[l_begin]->end;
				l_begin+=1;	s_begin+=1;
			}else{
				sorted[s_begin]->begin = list[l_mid]->begin;
				sorted[s_begin]->end = list[l_mid]->end;
				l_mid+=1; s_begin+=1; 
			}
		}
		else{
			sorted[s_begin]->begin = list[l_mid]->begin;
			sorted[s_begin]->end = list[l_mid]->end;
			l_mid+=1; s_begin+=1; 
		}
	}
	
	if(l_begin>mid)
		for(i=l_mid; i<=end; i++){
			sorted[s_begin]->begin = list[i]->begin;
			sorted[s_begin]->end = list[i]->end;
			s_begin += 1;
		}
	else
		for(i=l_begin; i<=mid; i++){
			sorted[s_begin]->begin = list[i]->begin;
			sorted[s_begin]->end = list[i]->end;
			s_begin += 1;	
		}

	for(i=begin; i<=end; i++){
		list[i]->begin = sorted[i]->begin;
		list[i]->end = sorted[i]->end;
	} 
}

/* 병합 정렬 */
void merge_sort(Node **list, Node **sorted, int begin, int end){
	int mid;
	int i=0;
	if(begin<end){
		mid = (begin+end)/2;
		merge_sort(list, sorted, begin, mid);
		merge_sort(list, sorted, mid+1, end);
		merge(list, sorted, begin, mid, end);
	}
}

int main(int argc, char *argv[]){
	int N=0,i=0,j=0;
	scanf("%d",&N);
	
	Node **list = (Node **)malloc(sizeof(Node*)*N);
	Node **sorted = (Node **)malloc(sizeof(Node*)*N);
	for(i=0;i<N;i++){
		list[i] = (Node *)malloc(sizeof(Node));
		sorted[i] = (Node *)malloc(sizeof(Node));
		scanf("%d %d",&list[i]->begin,&list[i]->end);	
	}
	
	merge_sort(list, sorted, 0, N-1);
	free(sorted);
	
	return 0;
}
