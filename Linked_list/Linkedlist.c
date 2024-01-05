#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
int count=0;


struct node* create(){
    struct node* x=(struct node*)malloc(sizeof(struct node));
    return x;
}

void insertbegin(){
    struct node *newhead=create();
    printf("Enter the data:");
    scanf("%d",&newhead->data);
    newhead->next=head;
    head=newhead;
    count++;
}

void insertend(){
    struct node *newend=create();
    printf("Enter the data:");
    scanf("%d",&newend->data);
    struct node *temp=head;
    if(head==NULL){
        head=newend;
        newend->next=NULL;
        count++;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newend;
        newend->next=NULL;
        count++;
    }
}

void insertpos(int pos){
    if(pos<=0 || pos>count){
        printf("Invalid position\n");
    }
    else{
        int i=1;
        struct node *temp=head;
        struct node *newpos=create();
        printf("Enter the data:");
        scanf("%d",&newpos->data);
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newpos->next=temp->next;
        temp->next=newpos;
        
    }
}

void insertele(int ele){
    struct node *temp=head;
    struct node *prev=NULL;
    struct node *new=create();
    struct node *nextnode=NULL;
    int newele;
    printf("Enter the element to be inserted:");
    scanf("%d",&newele);
    new->data=newele;
    while(temp->next!=NULL){
            if(temp->data==ele){
                prev=temp;
                nextnode=temp->next;
                prev->next=new;
                new->next=nextnode;
            }
            temp=temp->next;
    }
}

void delete(int ele){
    struct node *prev=NULL;
    struct node *nextadd=NULL;
    struct node *temp=head;
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        while(temp!=NULL){
            if(temp->data==ele){
                if(prev==NULL){
                    head=temp->next;
                    printf("%d deleted\n",temp->data);
                    count--;
                    break;
                }
                else{
                    nextadd=temp->next;
                    prev->next=nextadd;
                    printf("%d deleted\n",temp->data); 
                    count--;
                    break;
                }free(temp);
            }
            prev=temp;
            temp=temp->next;
        }
        printf("Element not found\n");
    }
}

void deletepos(int pos){
    struct node *nextadd=NULL;
    struct node *temp=head;
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        int i=1;
        if(pos>0 && pos<count){
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            nextadd=temp->next;
            temp->next=nextadd->next;
            printf("%d deleted\n",nextadd->data);
            free(temp);
            count--;
        }
        else{
            printf("Invalid Positon\n");
        }
    }

}

void display(){
    struct node * temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}


int main(){
    int ch,pos,ele;
    int flag=1;
    while(flag){
        printf("\n*********************************************************************\n");
        printf("1.Insertion at beginning\n2.Insertion at end\n3.Insetion(Position)\n4.Insertion(Element)\n5.Delete(Element)\n6.Delete(Positon)\n7.Display\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                insertbegin();
                break;
            case 2:
                insertend();
                break;
            case 3:
                printf("Enter the position(1 to %d):",count);
                scanf("%d",&pos);
                insertpos(pos);
                break;
            case 4:
                printf("Enter the element after node to be inserted:");
                scanf("%d",&ele);
                insertele(ele);
                break;
            case 5:
                printf("Enter the element to be deleted:");
                scanf("%d",&ele);
                delete(ele);
                break;
            case 6:
                printf("Enter the position of element to be deleted:(1 to %d)",count);
                scanf("%d",&pos);
                deletepos(pos);
                break;
            case 7:
                display();
                break;
            default:
                flag=0;
                break;


        }
    }
}