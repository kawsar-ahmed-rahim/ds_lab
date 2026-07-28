//! Linear Search on an Array
#include <stdio.h>

int main() {
    int arr[100],n,key,found=0,i;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    for(i=0; i<n; i++){
        scanf("%d",&arr[i]);
    };
    printf("Enter element to search: ");
    scanf("%d",&key);

    for(i=0;i<n;i++){
        if(arr[i]==key){
            found = 1;
            break;
        }
    }
    if(found){
        printf("Element %d found at index %d\n",key,i);
    }else {
       printf("Element %d not found in the array",key);
    }

    return 0;
}