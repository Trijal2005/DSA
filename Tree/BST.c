#include <stdio.h>
#include <stdlib.h>

struct node {
 int data;
 struct node* left;
 struct node* right;
};

// Create a new Node
struct node* create(int value) {
 struct node* newNode = malloc(sizeof(struct node));
 newNode->data = value;
 newNode->left = NULL;
 newNode->right = NULL; 
 return newNode;
}

//Insertion

void insert(struct node *root,int ele){
    struct node *prev=NULL;
    while(root!=NULL){
        prev=root;
        if(ele==root->data){
            printf("Cannot insert as %d already in BST\n",ele);
        }
        else if(ele<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }

    }

    struct node *new=create(ele);
    if(ele<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
    }
}

// Searching

struct node *search(struct node *root,int ele){
    if(root==NULL){
        printf("Element no found\n");
        return NULL;
    }

    if(ele==root->data){
        printf("Element found\n");
        return root;
    }
    else if(ele<root->data){
        return search(root->left,ele);
    }
    else{
        return search(root->right,ele);
    }
}

//Deleting
struct node *findmin(struct node *min){
    struct node *temp=min;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

struct node *delete(struct node *root,int ele){
    if(root==NULL){
        return NULL;
    }
    else if(ele<root->data){
         root->left=delete(root->left,ele);
    }
    else if(ele<root->data){
        root->right= delete(root->right,ele); // element found now to delete it
    }
    else{
    // case 1
        if(root->left==NULL && root->right==NULL){
            printf("%d 1deleted\n",root->data);
            free(root);
            root=NULL;
        }

        //case 2 in two diff parts
        else if(root->left==NULL){ // right child present
            printf("%d 2deleted\n",root->data);
            struct node *temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL){
            printf("%d 2deleted\n",root->data);
            struct node *temp=root;
            root=root->left;
            free(temp);
        }
        //case 3
        else{
            printf("%d 3deleted\n",root->data);
            struct node *temp=findmin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,temp->data);
        }
        
    }
    return root;

}

//displaying
void inorderTraversal(struct node* root) {
 if (root == NULL) 
	return;
 inorderTraversal(root->left);
 printf("%d ", root->data);
 inorderTraversal(root->right);
}


int main(){
    int ele,ch,flag=1;
    struct node *root=NULL;
    while(flag){
        printf("\n******************\n");
        printf("\n1.Set root\n2.Insert node\n3.Search node\n4.Delete node\n5.Inorder Display\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter the element:");
                scanf("%d",&ele);
                root=create(ele);
                break;
            case 2:
                printf("Enter the element:");
                scanf("%d",&ele);
                insert(root,ele);
                break;
            case 3:
                printf("Enter the element:");
                scanf("%d",&ele);
                printf("Element found : %d",search(root,ele)->data);
                break;
            case 4:
                printf("Enter the element:");
                scanf("%d",&ele);
                delete(root,ele);
                break;
            case 5:
                inorderTraversal(root);
                break;
            default:
                flag=0;
                break;
        }
    }
    return 0;
}