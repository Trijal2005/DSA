#include<stdio.h>

void root(char tree[],char x){
    if(tree[1]=='a'){
        printf("Root already set");
    }
    else{
        tree[1]=x;
    }
}

void set_left(char tree[],char x,int parent){
    if(tree[parent]=='a'){
        printf("No parent node present at %d",parent);
    }
    else{
        tree[2*parent]=x;
    }
}

void set_right(char tree[],char x,int parent){
    if(tree[parent]=='a'){
        printf("No parent node present at %d",parent);
    }
    else{
        tree[(2*parent)+1]=x;
    }
}

void print_tree(char tree[],int n){
    for(int i=0;i<n;i++){
        if(tree[i]=='\0'){
            printf("-\t");
        }
        else{
            printf("%c\t",tree[i]);
        }
    }

}

int  main(){
    int n,parent,ch,flag=1;
    char ele;
    printf("Enter the total no. of elements:");
    scanf("%d",&n);
    char tree[n];
    while(flag){
        printf("\n***************************\n");
        printf("1.Root\n2.Left\n3.Right\n4.Print tree\n");
        printf("Enter your choice:");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter the root:");
                scanf(" %c",&ele);
                root(tree,ele);
                break;
            case 2:
                printf("Enter the left: and its parent position");
                scanf(" %c%d",&ele,&parent);
                set_left(tree,ele,parent);
                break;
            case 3:
                printf("Enter the right: and its parent position");
                scanf(" %c%d",&ele,&parent);    //////// very imp to give space "  %c"for input buffer newline
                set_right(tree,ele,parent);
                break;
            case 4:
                print_tree(tree,n);
                break;
            default:
                flag=0;

        }
    }
    return 0;


}