#include<stdio.h>
typedef struct{
    int coef;
    int expo;
    
}POLY;

void main(){
    POLY p[20];
    int n,i;
    printf("Enter the no. of terms in the poly:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the coefficient of term[%d]:",i+1);
        scanf("%d",&p[i].coef);
        printf("Enter the exponent of the term[%d]",i+1);
        scanf("%d",&p[i].expo);
        
    }
    for(i=0;i<n;i++){
        if(p[i].coef<0){
            printf("%d",p[i].coef);
            
        }else{
            printf("+%d",p[i].coef);
        }
        if(p[i].expo>0){
            printf(".x^%d ",p[i].expo);
        }else{
            printf("/x^%d",-p[i].expo);
        }
    }
}