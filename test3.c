#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100
struct item{
    int value;
    int priority;
};
typedef struct item Node;

Node pq[Maxsize];
int size =0;

int isFull(){
    return size==Maxsize-1;
}

int isEmpty(){
    return size==0;
}

void queue(){
    if(isFull()){
        printf("The queue is full\n");
        return;
    }
    int value;
    int priority;
    printf("Enter the value:");
    scanf("%d",&value);
    printf("Enter the priority(higher number emeans higher priority)");
    scanf("%d",&priority);
    
    Node Newitem;
    Newitem.value=value;
    Newitem.priority=priority;
    int i;
    for(i=size-1;i>=0;i--){
        if(pq[i].priority>priority){
            pq[i+1]=pq[i];
        }else{
            break;
        }
        
    }
    pq[i+1]=Newitem;
    size++;
    return;
}

void dequeue(){
    if(isEmpty()){
        printf("ETeh queue is empty\n");
        return;
    }
    Node removedItem=pq[size-1];
    printf("The removed item is : %d value with priority of %d",removedItem.value,removedItem.priority);
    size--;
    return;
}

void display(){
    for(int i=0;i<size;i++){
        printf("[%d]->(%d,%d)",i,pq[i].value,pq[i].priority);

    }
    return;
}
int main(){
    int ch;
    while(1){
        printf("Enter the correct choice\n");
        printf("1.queue\n");
        printf("2.dequeue\n");
        printf("3.exit\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:queue(); break;
            case 2:dequeue(); break;
            case 3:display(); break;
            case 4:exit(0);
            default: printf("Enter the correct choice.\n");
        }
    }
    return 0;
}

