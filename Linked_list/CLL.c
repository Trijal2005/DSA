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

void insertbegin(int ele){
    struct node *temp=head;
    struct node *new=create();
    new->data=ele;
    if(temp==NULL){
        head=new;
        new->next=head;
    }
    else{
        while(temp->next!=head){
            temp=temp->next;
        }
        new->next=head;
        temp->next=new;
        head=new;
    }
    count++;
}

void insertlast(int ele){
    struct node *temp=head;
    struct node *new=create();
    new->data=ele;
    if(temp==NULL){
        head=new;
        new->next=head;
    }
    else{
        while(temp->next!=head){
           temp=temp->next;
        }
        temp->next=new;
        new->next=head;
    }
}

void insertele(int ele,int ele1){
    struct node *temp=head;
    struct node *nextadd=NULL;
    struct node *new=create();
    new->data=ele;
    while(temp->next!=head){
        if(temp->data==ele1){ 
            nextadd=temp->next;
            temp->next=new;
            new->next=nextadd;
        }
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("Element not found\n");
    }
}

void display(){
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        struct node *temp=head;
        do{
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        while(temp!=head);
    }
}



void deletefirst(){
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        struct node *temp1=head;
        struct node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;
        printf("%d deleted:\n",temp1->data);
        free(temp1);
    }
}

void deletelast(){
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        struct node *temp=head;
        struct node *prev=NULL;
        while(temp->next!=head){
            prev=temp;
            temp=temp->next;
        }
        prev->next=head;

    }
}
void deleteele(int ele){
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        struct node *temp=head;
        struct node *prevadd=NULL;
        while(temp->next!=head){
            if(temp->data==ele){
                if(prevadd==NULL){
                    deletefirst();
                    break;
                }
                // else if(temp==head){
                //     deletelast();
                //     break;
                // }
                else{
                    prevadd->next=temp->next;
                    printf("%d deleted:\n",temp->data);
                    free(temp);
                    break;
                }

            }
            prevadd=temp;
            temp=temp->next;
        }
        if(temp->next==NULL){
            printf("Element not found\n");
        }
    }
}














int main(){
    int ch,ele,ele1;
    int flag=1;
    while(flag){
        printf("\n*********************************************************************\n");
        printf("1.Insertion at beginning\n2.Insertion at end\n3.Insetion(Element)\n4.Delete(FRONT)\n5.Delete(END)\n6.Delete(Element)\n7.Display\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:
                printf("Enter the element to be entered:");
                scanf("%d",&ele);
                insertbegin(ele);
                break;
            case 2:
                printf("Enter the element to be entered:");
                scanf("%d",&ele);
                insertlast(ele);
                break;
            case 3:
                printf("Enter element after which its inserted:");
                scanf("%d",&ele1);
                printf("Enter the element to be entered:");
                scanf("%d",&ele);
                insertele(ele,ele1);
                break;
            case 4:
                deletefirst();
                break;
            case 5:
                deletelast();
                break;
            case 6:
                printf("Enter the element to be deleted:");
                scanf("%d",&ele);
                deleteele(ele);
                break;
            case 7:
                display();
                break;
            default:
                flag=0;
                break;
        }
    }return 0;
}