//! ternary Search on a Sorted Array
#include <stdio.h>
#define MAX_SIZE 10
int main() {
    int n,i,arr[MAX_SIZE],key;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d",&key);

    int low=0;
    int high = n-1;
    while(low<=high){
        int mid1 = low+(high-low)/3;
        int mid2 = high-(high-low)/3;

        if(arr[mid1]==key){
            printf("%d found at position %d",key,mid1+1);
            return 0;
        } 
        if(arr[mid2]==key){
            printf("%d found at position %d",key,mid2+1);
            return 0;
        } 
        if(key<arr[mid1]){
            high = mid1-1;
        }else if(key>arr[mid2]) {
            low = mid2 + 1;
        }else {
            low=mid1+1;
            high=mid2-1;
        }

    }
    
    printf("%d not found in the array\n", key);
    return 0;
}