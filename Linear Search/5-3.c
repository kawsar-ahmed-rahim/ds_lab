//! Access Array Elements

#include <stdio.h>
#define MAX_SIZE 10
int main(){
    int n,i,arr[MAX_SIZE];
    printf("Enter size of array: ");
    scanf("%d",&n);

    printf("Enter %d elements: ",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    };

    printf("Elements in array: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    };
    
    return 0;
}