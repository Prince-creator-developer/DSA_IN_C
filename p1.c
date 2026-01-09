#include<stdio.h>
#include<stdlib.h>
/*1. Design, Develop and Implement a menu driven Program in C for the 
following Array operations
 a. Creating an Array of N Integer Elements
 b. Display of Array Elements with Suitable Headings
 c. Inserting an Element (ELEM) at a given valid Position (POS) 
d. Deleting an Element at a given valid Position(POS)
 e. Exit.
 Support the program with functions for each of the above operations.*/
int arr[100],n,i,pos;
void create(){
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
}
void display(){
    printf("The elements of the array are:\n");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
void insert(){
    printf("Enter the position to insert the element :");
    scanf("%d",&pos);//the pos is in index form
    if(pos<0 || pos>n){
        printf("Invaid input");
        return;
    }
    for(i=n-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    int elem;
    printf("Enter the element to be inserted:");
    scanf("%d",&elem);
    arr[pos]=elem;
    n=n+1;
    printf("Element inserted successfully");
    printf("The new array is:\n");  
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
void delete(){
    printf("Enter the position to delete the element:");
    scanf("%d",&pos);
    if(pos<0||pos>n){
        printf("Invalid input:");
        return;
    }
    for(i=pos+1;i<n;i++){
        arr[i-1]=arr[i];
    }
    n=n-1;
    printf("Element deleted successfully");
    printf("The new array is:\n");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }

}
void main(){
    int ch;
    for(;;){
        printf("\n1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                    create();
                    break;
            case 2:if (n==0)

                        printf("array is empty");
                    else
                        display();
                        break;
            case 3:if (n==0)

                        printf("array is empty, create array first");
                    else
                        insert();
                        break;
            case 4:if (n==0)

                        printf("array is empty");
                    else
                        delete();
                        break;
            case 5:exit(0);
            default:printf("Invalid input");
        }
    }
}