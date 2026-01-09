#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *rlink, *llink;
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
    newnode->rlink=NULL;
    newnode->llink=NULL;
    return newnode;
    
}
void insert_at_front(){
    NODE temp=getnode();
    if(first==NULL){
        first=temp;
        return;
    }if(first!=NULL){
        first->llink=temp;
        temp->rlink=first;
        first=temp;
        return;
    }

    return;
}
void delete_at_front(){
    NODE temp;
    if (first==NULL){
        printf("the list is empty\n");
        return;
    }
    if(first->rlink==NULL){
        printf("the deleted element is %d\n"),first->info;
        free(first);
        first=NULL;
        return;
    }
   
    temp=first;
    first=first->rlink;
    printf("the deleted element is %d\n",temp->info);
    free(temp);
    first->llink=NULL;
    return;
}
void insert_at_end(){
    NODE temp=getnode();
    if (first==NULL){
        first=temp;
        return;
    }
    NODE cur=first;
    while(cur->rlink!=NULL){
        cur=cur->rlink;
    }
    cur->rlink=temp;
    temp->llink=cur;
    return;

}
 void delete_at_end(){
    NODE cur,prev;
    if(first==NULL){
        printf("the list is empty\n");
        return;
    }
    if(first->rlink==NULL){
        printf("the deleted element is %d\n",first->info);
        free(first);
        first=NULL;
        return;
    }
    prev=NULL;
    cur=first;
    while(cur->rlink!=NULL){
        prev=cur;
        cur=cur->rlink;
    }
    printf("the deleted element is %d\n",cur->info);
    free(cur);
    prev->rlink=NULL;
    return;
 }
 int getcount(){
    NODE cur;
    int count=0;
    cur=first;
    while(cur!=NULL){
        count++;
        cur=cur->rlink;

    }
    printf("the number of nodes in the list is %d\n",count);
    return count;
 }
 void search(){
    NODE cur;
    int ele, pos=1, flag=0;
    if(first==NULL){
        printf("the list is empty\n");
        return;
    }
    printf("Enter the elemnt to be searched:\n");
    scanf("%d",&ele);
    cur=first;
    while(cur!=NULL){
        if(cur->info==ele){
            printf("The element %d is found at the position %d\n",ele,pos);
            flag=1;
            return;
        }
        pos++;
        cur=cur->rlink;

    }
    if(flag==0){
        printf("The element %d is not found in the list\n",ele);
        return;
    }
    return;
 }

 void reverse(){
    NODE prev,cur, next;
    if(first==NULL){
        printf("the list is empty\n");
        return;
    }
    prev=NULL;
    cur=first;
    next=NULL;
    while(cur!=NULL){
        next=cur->rlink;
        cur->rlink=prev;
        cur->llink=next;
        prev=cur;
        cur=next;
        first=prev;

    }
    return;
 }
 void sort(){
    NODE i,j;
    int temp;
    if(first==NULL){
        printf("the list is empty\n");
        return;
    }
    for(i=first;i->rlink!=NULL;i=i->rlink){
        for(j=i->rlink;j!=NULL;j=j->rlink){
            if(i->info>j->info){
                temp=i->info;
                i->info=j->info;
                j->info=temp;
            }
        }
    }
    return;
 }
 void insert_at_pos(){
    NODE temp, cur, prev;
    temp=getnode();
    int pos, count=0,i;
    if(first==NULL){
        printf("The list empty\n");
        return;

    }
    printf("ENter teh position to insert the node:\n");
    scanf("%d",&pos);
    count=getcount();
    if(pos<1||pos>count+1){
        printf("Invalid position\n");
        return;
    }
    if(pos==1){
        insert_at_front();
        return;
    }
    if(pos==count+1){
        insert_at_end();
        return;
    }
    prev=NULL;
    cur=first;
    if(pos>1&&pos<=count){
        for(i=1;i<pos;i++){
            prev=cur;
            cur=cur->rlink;
            
        }

    }
    prev->rlink=temp;
    temp->llink=prev;
    temp->rlink=cur;
    cur->llink=temp;
    return;

 }
 void delete_at_pos(){
    NODE cur, prev;
    int pos, count=0,i;

    if(first==NULL){
        printf("THe list is empty\n");
        return;
    }
    printf("Enetr the position to delete the mode:\n");
    scanf("%d",&pos);
    count=getcount();
    if(pos<1||pos>count){
        printf("Invalid position\n");
        return;
    }
    if(pos==1){
        delete_at_front();
        return;
    }
    if(pos==count){
        delete_at_end();
        return;

    }
    prev=NULL;
    cur=first;
    for(i=1;i<pos;i++){
        prev=cur;
        cur=cur->rlink;

    }
    prev->rlink=cur->rlink;
    cur->rlink->llink=prev;
    printf("The deleted element is%d\n",cur->info);
    free(cur);
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
    printf("NULL->");
    while(cur!=NULL){
        printf("%d\t",cur->info);
        cur=cur->rlink;
    }printf("->NULL");
    printf("\n");

 }
  void main(){
    int choice;
    while(1){
        printf("WELCOME TO DOUBLY LINKED-LIST\n1.insert at front\n 2.delete at front\n 3.insert at end\n 4.delete at end\n 5. display\n 6.exit\n");
        printf("enter the choice:\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert_at_front();break;
            
            case 2: delete_at_front();break;
            
            case 3: insert_at_end();break;
            case 4: delete_at_end();break;            
            case 5: display();break;
            case 6: insert_at_pos(); break;
            case 7: delete_at_pos(); break;
            case 8: search(); break;
            case 9: getcount(); break;
            case 10: reverse(); break;
            case 11: sort(); break;
            case 12: exit(0);
            default: printf("enter a valid choiice\n");

        }
    }
  }
  ///complete all fXns as of in the singly Linked List.

