//! Selection Sort
#include <stdio.h>
#define MAX_SIZE 10

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(&arr[min],&arr[i]);

    }

}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}
int main() {
    int i,n,arr[MAX_SIZE];

    printf("Array size: ");
    scanf("%d",&n);

    printf("Original array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    selectionSort(arr,n);

    printf("sorted array: ");
    printArray(arr,n);
    return 0;
}