#include<stdio.h>
#include<stdlib.h>
 
typedef struct{
    int row;
    int col;
    int val;
}Sparse;

void main(){
    Sparse s[100];
    int m,n,i,j,k;
    printf("Enter the number of rows and columns:\n");
    scanf("%d%d",&m,&n);
    printf("Enter the elements of the matrix:\n");
    int ele;
    s[0].row=m;
    s[0].col=n;
    k=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&ele);
            if(ele!=0){
                s[k].row=i;
                s[k].col=j;
                s[k].val=ele;
                k++;
            }
        }
    }
    s[0].val=k-1;
    printf("The sparse matrix is:\n");
    printf("Row\tColumn\tValue\n");
    for(i=0;i<k;i++){
        printf("%d\t%d\t%d\n",s[i].row,s[i].col,s[i].val);
        
    }
}