//! Compare Two Numbers

#include <stdio.h>

int main () {
    int a,b;
    printf("Enter two integers: ");
    scanf("%d%d",&a,&b);
    if(a==b){
        printf("%d and %d are equal",a,b);
    }else {
        printf("%d and %d are not equal",a,b);
    }
    return 0;

}