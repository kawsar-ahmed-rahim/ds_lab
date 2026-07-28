//! Binary Search on a Sorted Array
#include <stdio.h>
#define MAX_SIZE 10
int main() {
    int n,i,arr[MAX_SIZE],key;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter %d sorted elements:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d",&key);

    int low=0;
    int high = n-1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(arr[mid]==key){
            printf("%d found at position %d",key,mid+1);
            return 0;
        } 
        else if(arr[mid]<key){
            low = mid+1;
        }else {
            high = mid - 1;
        }
    }

    printf("%d not found in the array\n", key);
    return 0;
}