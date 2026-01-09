#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void maxHeapify(int arr[] , int n, int i){
    int largest =i;
    int lchild=2*i+1;
    int rchild=2*i+2;
    if(lchild<n && arr[lchild]>arr[largest]){
        largest =lchild;
    }
    if(rchild<n && arr[rchild]>arr[largest]){
        largest=rchild;
    }
    if(largest!=i){
        swap(&arr[largest], &arr[i]);
        maxHeapify(arr, n, largest);
    }
}
void minHeapify(int arr[], int n, int i){
    int smallest=i;
    int lchild=2*i+1;
    int rchild=2*i+2;
    if(lchild<n && arr[lchild]<arr[smallest]){
        smallest=lchild;
    }
    if(rchild<n && arr[rchild]<arr[smallest]){
        smallest=rchild;
    }
    if(smallest != i){
        swap(&arr[smallest], &arr[i]);
        minHeapify(arr, n, smallest);
    }
}
void buildHeap(int arr[], int n, int type){
    int startIdx=(n/2)-1;
    for(int i=startIdx;i>=0;i--){
        if(type==1){
            maxHeapify(arr, n, i);
        }else{
            minHeapify(arr, n, i);
        }
    }
    return;
}
void printHeap(int arr[], int n){
    printf("The representation is:\n");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    return;
}
int main(){
    int ch, i, n;
    int *arr;
    printf("Enter the no. of elements :\n");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    
    printf("Enter the eleemnts in the array: \n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Bfore:");
    printHeap(arr, n);
    while(1){
        printf("1. min Heap\n");
        printf("2. Max Heap\n");
        printf("3. exit\n");
        printf("Enter the choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1: buildHeap(arr, n, 2);
                    break;
            case 2: buildHeap(arr, n, 1);
                    break;
            case 3: exit(0);
                    break;
            default: printf("Enter the corerct choice\n");
        }
        printHeap(arr, n);
    }
    return 0;

}
