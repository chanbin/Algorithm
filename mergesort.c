#include <stdio.h>
#include <stdlib.h>

void merge(int *list, int *sorted, int begin, int mid, int end){
	int l_begin=begin, l_mid=mid+1, s_begin=begin, i=0;

	// �κ� ����(����) 
	while( l_begin<=mid && l_mid<=end ){
		if( list[l_begin] <= list[l_mid] ){
			sorted[s_begin] = list[l_begin];
			l_begin+=1;	s_begin+=1;
		}else{
			sorted[s_begin] = list[l_mid];
			l_mid+=1; s_begin+=1; 
		}
	}
	
	// ���� �ִ� ������ �ӽù迭�� �ϰ� ����
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

	// �ӽ� �迭�� list�� ����
	for(i=begin; i<=end; i++) list[i] = sorted[i];
}

// �պ� ����
void merge_sort(int *list, int *sorted, int begin, int end){
	int mid;

	if(begin<end){
		mid = (begin+end)/2; // �߰� ��ġ�� ����Ͽ� ����Ʈ�� �յ� ���� -����(Divide)
		merge_sort(list, sorted, begin, mid); // 1. ��� ����, ������ 2~1�� ���������� -����(Divide)
		merge_sort(list, sorted, mid+1, end); // 2. �κ� �迭�� �պ� -����(Combine)
		merge(list, sorted, begin, mid, end); // ���� �κ� ���� -����(Conquer)
	}
}

void main(){
	int i;
	int n = 8;
	//int list[MAX_SIZE] = {21, 10, 12, 20, 25, 13, 15, 22};
	int *list = (int *)malloc(sizeof(int)*n);
	list[0]=21;list[1]=10;list[2]=12;list[3]=20;list[4]=25;list[5]=13;list[6]=15;list[7]=22;
	
	// �պ� ���� ����(left: �迭�� ���� = 0, right: �迭�� �� = 7)
	int *sorted = (int *)malloc(sizeof(int)*n);
	merge_sort(list, sorted, 0, n-1);
	free(sorted);

	// ���� ��� ���
	for(i=0; i<n; i++) printf("%d ", list[i]);
}
