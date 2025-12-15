#include <stdio.h>

void swap(int *x, int *y){
    int temp = (*x);
    (*x) = (*y);
    (*y) = temp;
}

int partition(int arr[], int  left, int right){
	int pivot = right;
	right--;
	while(left < right){
	    while(arr[left] <= arr[pivot]){
	        left++;
	    }
	    while(arr[right] >= arr[pivot]){
	        right--;
	    }
	    if(left < right){
	        swap(&arr[left], &arr[right]);
	    }
	}
	swap(&arr[left], &arr[pivot]);
	return left;
}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        printf("%d  ", arr[i]);
    }
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int pivot = partition(arr, left, right);
        for(int i=left; i<=right; i++){
            printf("%d  ", arr[i]);
        }
        printf("\n");
        quickSort(arr, left, pivot-1);
        quickSort(arr, pivot+1, right);
    }
}

int main(){
    int arr[] = {3, 1, 2, -4, 5, 10, 6, -4, 11, 9,-2};
    int n = 11;
    printf("Mang ban dau:\n");
    printArray(arr, n);
    printf("\n\n");
    quickSort(arr,0, n-1);
    printf("Mang sau sap xep:\n");
    printArray(arr, n);
    
}

/*
Phân tích hàm quickSort theo quy trình 4 bước:
B1: Base case: left >= right
B2: Kết quả Base case: ngừng gọi đệ quy
B3: Một trường hợp đằng trước Base case: quickSort(arr, )

