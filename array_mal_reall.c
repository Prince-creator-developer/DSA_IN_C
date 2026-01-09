#include<stdio.h>
#include<stdlib.h>

int *a=NULL,n=0;

void create(){
    int i;
    printf("Enter the size of the array:\t");
    if(scanf("%d",&n) != 1 || n <= 0){
        printf("Invalid size\n");
        exit(1);
    }
    a = (int*)malloc(n * sizeof *a);
    if(a==NULL){
        printf("Memory is not allocated\n");
        exit(0);  
    }
    printf("Enter the elements in the array\n");
    for(i=0;i<n;i++){
        printf("a[%d]=",i);
        if(scanf("%d",&a[i]) != 1){
            printf("Invalid input\n");
            free(a);
            exit(1);
        }
    }
}
void display(){
    int i;
    printf("The elements in the aray are:\n");
    for(i=0;i<n;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
}
void insert(){
    int ele,pos,i;
    if(n==100){
        printf("Array is full\n");
        return;
    }
    printf("Enter the element to be inserted and its position\n");
    if(scanf("%d %d",&ele,&pos)!=2){
        printf("Invalid input\n");
        return;
    }
    if(pos>n||pos<0){
        printf("Invalid input\n");
            return;
    }
    int *temp=(int*)realloc(a,(n+1)*sizeof*a);
    if(temp==NULL){
        printf("Memory is not allocted\n");
        return;
    }else{
        
        a=temp;

    }
    
    for(i=n-1;i>=pos;i--){
        a[i+1]=a[i];
    }
    a[pos]=ele;
    n=n+1;
    printf("Element inserted successfully\n");
}

void del(){
    int pos,i;
    if(n==0){
        printf("Array is empty\n");
        return;
    }

    printf("Enter the position to delete element:\t");

    if(scanf("%d",&pos)!=1){
        printf("Invalid input\n");
        return;
    }
    
    if(pos<0||pos>=n){
        printf("Invalid position\n");
        return;
    }
    printf("Element deleted is %d\n",a[pos]);
    for(i=pos;i<n-1;i++){
        a[i]=a[i+1];
    }
    n=n-1;
    printf("Element deleted successfully\n");
}
int main(){
    create();
    display();
    insert();
    display();
    del();
    display();
    free(a);
    return 0;
}