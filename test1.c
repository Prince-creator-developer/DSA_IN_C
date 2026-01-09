#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node* link;

};
typedef struct node* NODE;

NODE first;
 NODE getnode(){
    NODE newnode;
    newnode=(NODE) malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("the memory has not been allocated\n");
        exit(0);
    }
    int ele;
    printf("Enter the element to be inserted:");
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
    if(first==NULL){
        printf("The list is empty\n");
        return;
    }
    temp=first;
    first=first->link;
    printf("the element deleted is %d",temp->info);
    free(temp);
    return;
 }

 void insert_at_end(){
    NODE temp;
    temp=getnode();
    if(first==NULL){
        first=temp;
        return;
    }
    NODE cur=first;
    while(cur->link!=NULL){
        cur=cur->link;
    }
    cur->link=temp;
    return;
 }
 void delete_at_end(){
    NODE prev,cur;
    if(first==NULL){
        printf("The list is empty\n");
        return;
    }
    if(first->link==NULL){
        printf("the element deleted is %d",first->info);
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
    printf("The element deleted is %d",cur->info);
    free(cur);
    prev->link=NULL;
    return;
}


void display(){
    NODE temp;
    if(first==NULL){
        printf("The list is empty\n");
        return;
    }
    temp=first;
    while(temp!=NULL){
        printf("%d->",temp->info);
        temp=temp->link;
    }printf("NULL");
    printf("\n");
    return;

}
void n_nodes(){
    int i,n;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        NODE newnode=getnode();
        newnode->link=first;
        first=newnode;

    }display();
    return;
}
int getcount(){
    NODE temp=first;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->link;
    }
    return count;
}
void count(){
    int count=getcount();
    printf("Total number of nodes are:%d",count);
    return;
}
void insert_at_pos(){
    int pos,i;
    NODE temp=getnode();
    int count=getcount();
    printf("Enter the postion between 1 to %d",count+1);
    scanf("%d",&pos);
    if(pos<1||pos>count+1){
        printf("Enter the proper position\n");
        return;
    }
    if(pos==1){
        temp->link=first;
        first=temp;
        

    }else{
        NODE prev=first;
        for(i=1;i<pos-1;i++){
            prev=prev->link;
        }
        temp->link=prev->link;
        prev->link=temp;
    }
    return;
}

int main(){
    int ch;
    for(;;){
    printf("1.insert_at_front\n2.delete_at_front\n3.insert_at_end\n4.delete_at_end\n5.n_nodes\n6.display\n7.getcount\n8.insert_at_pos\n9.exit\n\n");
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:insert_at_front(); break;
        case 2:delete_at_front(); break;
        case 3:insert_at_end(); break;
        case 4:delete_at_end(); break;
        case 5:n_nodes(); break;
        case 6:display(); break;
        case 7:count(); break;
        case 8:insert_at_pos(); break;
        case 9:exit(0);
 
        default:printf("Enter the correct choice\n");
    }
    }
    return 0;

}

