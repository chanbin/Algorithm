#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int begin, int end)
{
	int pivot, temp;
    pivot = (int)(begin+end)/2;
    
    while(begin<end){
    	while((arr[begin] <= arr[pivot]) && (begin <= end)) begin++;
    	while((arr[end] > arr[pivot]) && (begin <= end)) end--;
    	if(begin<end){
    		temp = arr[begin];
    		arr[begin] = arr[end];
    		arr[end] = temp;
    		if(end == pivot) return begin;
		}
	}
	//(begin>end)가 된 경우
	temp = arr[pivot];
	arr[pivot] = arr[end];
	arr[end] = temp;
	return end;
}

void quickSort(int arr[], int begin, int end){
	if(begin < end){
		int p = partition(arr, begin, end);
		quickSort(arr, begin, p-1);
		quickSort(arr, p+1, end);
	}
}

void main(){
    int n,i;

    //printf("몇개의 숫자로 정렬하시겠습니까?\n");
    //scanf("%d",&n);
    n=10000000;

	int *arr = (int*)malloc(sizeof(int)*n);
	for(i = 0 ; i < n ; i++)
		 arr[i]=rand()%1000;

	quickSort(arr,0,n-1);
    
	for(i = 0 ; i < 10 ; i++)
		printf("%d ", arr[i]);
}
