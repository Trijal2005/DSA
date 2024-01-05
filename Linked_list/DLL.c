#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
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
        new->next=NULL;
        new->prev=NULL;
    }
    else{
        new->next=temp;
        temp->prev=new;
        new->prev=NULL;
        head=new;
    }
    count++;
}

void insertend(int ele){
    struct node *temp=head;
    struct node *new=create();
    new->data=ele;
    if(temp==NULL){
        head=new;
        new->next=NULL;
        new->prev=NULL;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
        new->prev=temp;
        new->next=NULL;
    }
    count++;
}

void insertatpos(int ele,int pos){
    struct node *temp=head;
    struct node *new=create();
    struct node *nextadd=NULL;
    new->data=ele;
    if(pos>0 && pos<=count){
        if(pos==1){
            insertbegin(ele);
        }
        else if(pos==count){
            insertend(ele);
        }
        else{
            int i=1;
            while(i<pos-1){
                temp=temp->next;
                i++;
            }
            nextadd=temp->next;  //store the next node address
            temp->next=new;
            new->prev=temp;
            new->next=nextadd;
            nextadd->prev=new;

        }count++;
    }
    else{
        printf("Invalid positon\n");
    }

}

void insertafterpos(int ele,int pos){
        struct node *temp=head;
    struct node *new=create();
    struct node *nextadd=NULL;
    new->data=ele;
    if(pos>0 && pos<=count){
        if(pos==1){
            insertbegin(ele);
        }
        else if(pos==count){
            insertend(ele);
        }
        else{
            int i=1;
            while(i<pos){
                temp=temp->next;
                i++;
            }
            nextadd=temp->next;  //store the next node address
            temp->next=new;
            new->prev=temp;
            new->next=nextadd;
            nextadd->prev=new;

        }count++;
    }
    else{
        printf("Invalid positon\n");
    }

}
void deletebegin(){
    struct node *temp=head;
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        head=head->next;
        head->prev=NULL;
        free(temp);
        count--;
    }
}

void deleteend(){
    struct node *temp=head;
    struct node *prevadd=NULL;
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        prevadd=temp->prev;
        prevadd->next=NULL;
        temp->prev=NULL;
        free(temp);
        count--;
    } 
}

void deletepos(int pos){
    struct node *temp=head;
    struct node *prevadd=NULL;
    struct node *nextadd=NULL;
    if(head==NULL){
        printf("Underflow\n");
    }
    else{
        if(pos>0 && pos<=count){
            if(pos==1){
                deletebegin();
            }
            else if(pos==count){
                deleteend();
            }
            else{
                int i=1;
                while(i<pos){
                    temp=temp->next;
                    i++;
                }
                prevadd=temp->prev;
                nextadd=temp->next;
                prevadd->next=nextadd;
                nextadd->prev=prevadd;
                free(temp);
            }
        }
    }
}

void deletele(int ele){
    struct node *temp=head;
    struct node *prevadd=NULL;
    struct node *nextadd=NULL;
    if(head==NULL){
        printf("Underflow\n");        
    }
    else{
        while(temp!=NULL){
            if(temp->data==ele){
                if(temp->prev==NULL){
                    head=temp->next;
                    head->prev=NULL;
                    printf("%d deleted:\n",temp->data);
                    free(temp);
                    break;
                }
                else if(temp->next==NULL){
                    prevadd=temp->prev;
                    prevadd->next=NULL;
                    temp->prev=NULL;
                    printf("%d deleted:\n",temp->data);
                    free(temp);
                    break;
                }
                else{
                    prevadd=temp->prev;
                    nextadd=temp->next;
                    printf("%d deleted\n",temp->data);
                    free(temp);
                    prevadd->next=nextadd;
                    nextadd->prev=prevadd;
                    break;
                }

            }
            temp=temp->next;
        }
        if(temp==NULL){
            printf("Element not found\n");
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
        printf("1.Insertion at beginning\n2.Insertion at end\n3.Insetion(At_Position)\n4.Insertion(After_Positon)\n5.Delete(FRONT)\n6.Delete(END)\n7.Delete(Postion)\n8.Delete(Element)\n9.Display\n");
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
                insertend(ele);
                break;
            case 3:
                printf("Enter the position(1 to %d):",count);
                scanf("%d",&pos);
                printf("Enter the element to be entered:");
                scanf("%d",&ele);
                insertatpos(ele,pos);
                break;
            case 4:
                printf("Enter the position(1 to %d):",count);
                scanf("%d",&pos);
                printf("Enter the element to be entered:");
                scanf("%d",&ele);
                insertafterpos(ele,pos);
                break;
            case 5:
                deletebegin();
                break;
            case 6:
                deleteend();
                break;
            case 7:
                printf("Enter position of node to be deleted:");
                scanf("%d",&pos);
                deletepos(pos);
                break;
            case 8:
                printf("Enter the element to be deleted:");
                scanf("%d",&ele);
                deletele(ele);
                break;
            case 9:
                display();
                break;
            default:
                flag=0;
                break;
        }
    }
    return 0;
}