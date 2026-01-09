#include<stdio.h>
#include<stdlib.h>
void main(){

    int n,i,*ptr;
    
    printf("enter the size:\n");
    scanf("%d",&n);
    
    ptr=(int*)malloc(n*sizeof(int));

    if(ptr==NULL){
        printf("memory is insufficient\n");
        }

    printf("Enter the values:\n");

    for(i=0;i<n;i++){
        scanf("%d",&ptr[i]);    
    }

    printf("HEre:\n");
    for(i=0;i<n;i++){
        printf("%d",ptr[i]);
    }
}