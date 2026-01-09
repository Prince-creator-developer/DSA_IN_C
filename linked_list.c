#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* link;
};typedef struct node* NODE;

NODE first;
NODE getnode(){
    NODE newnode;
    newnode=(NODE) malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory not allocated\n");
        exit(0);
    }
    int ele;
    printf("enter the element to be inserted:\n");
    scanf("%d",&ele);

    newnode->info=ele;
    newnode->link=NULL;
    return newnode;
    
}
void insert_at_front(){
    NODE temp=getnode();
    temp->link=first;
    first=temp;
    return;
}
void delete_at_front(){
    NODE temp;
    if (first==NULL){
        printf("the list is empty\n");
        return;
    }
    temp=first;
    first=first->link;
    printf("the deleted element is %d\n",temp->info);
    free(temp);
    return;
}
void insert_at_end(){
    NODE temp=getnode();
    if (first==NULL){
        first=temp;
        return;
    }
    NODE cur=first;
    while(cur->link!=NULL){
        cur=cur->link;  
    }
    cur->link=temp;
}
 void delete_at_end(){
    NODE cur,prev;
    if(first==NULL){
        printf("the list is empty\n");
        return;
    }
    if(first->link==NULL){
        printf("the deleted element is %d\n",first->info);
        free(first);
        first=NULL;
        return;
    }
    prev=NULL;
    cur=first;
    while(cur->link!=NULL){
        prev=cur;
        cur=cur->link;
    }
    printf("the deleted element is %d\n",cur->info);
    free(cur);
    prev->link=NULL;
    return;
 }
 void display(){
    NODE cur;
    if(first==NULL){
        printf("the  list is empty\n");
        return;
    }
    printf("the contents of the list are:\n");
    cur=first;
    while(cur!=NULL){
        printf("%d\t",cur->info);
        cur=cur->link;
    }printf("->NULL");
    printf("\n");

 }
  void main(){
    int choice;
    while(1){
        printf("1.insert at front\n 2.delete at front\n 3.insert at end\n 4.delete at end\n 5. display\n 6.exit\n");
        printf("enter the choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert_at_front();break;
            
            case 2: delete_at_front();break;
            
            case 3: insert_at_end();break;
            case 4: delete_at_end();break;            
            case 5: display();break;
            
            case 6: exit(0);
            default: printf("enter a valid choiice\n");

        }
    }
  }
