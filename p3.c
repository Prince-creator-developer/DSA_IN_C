#include <stdio.h>
typedef struct{
    int rows;
    int cols;
    int val;
    
}st;
void main(){
    st p[20];
    int i,j,m,n,k;
    printf("Enter the nno. of rows:");
    scanf("%d",&m);
    printf("Enter the no. of cols:\n");
    scanf("%d",&n);
    int ele;
    p[0].rows=m;
    p[0].cols=n;
    k=1;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("Enter the elemnt[%d][%d]:\n",i,j);
            scanf("%d",&ele);
            if(ele>0){
                p[k].rows=i;
                p[k].cols=j;
                p[k].val=ele;
                k++;};
            
        }
    }p[0].val=k-1;
    printf("HEre is the chart:\n");
    printf("rows \t cols \t val \t\n");
    for(i=0;i<k;i++){
        printf("%d \t %d \t %d \t ",p[i].rows,p[i].cols,p[i].val);
        printf("\n");
    }
}