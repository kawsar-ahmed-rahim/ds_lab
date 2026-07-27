#include<stdio.h>
#define MAX_SIZE 100

void recursionArray(int arr[], int start, int end){
    if(start >= end){
        return;
    }
    printf("%d ", arr[start]);
    recursionArray(arr, start+1, end);
}

int main() {
    int arr[MAX_SIZE],n,items;
    printf("Enter size of the array: ");
    scanf("%d",&n);

    printf("Enter elements: ");
    for(int i=0; i<n; i++){
         scanf("%d", &arr[i]);
    }

    printf("Elements (printed recursively): ");
    recursionArray(arr,0,n);

    return 0;

}

// gcc 1-2.c -o program.exe ; ./program.exe


