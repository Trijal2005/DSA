//1 Reversing of elements in c 
#include <stdio.h>
/*int main(){
    int n,i,j,temp;
    printf("Enter the no. of the elements in array:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of the array:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0,j=(n-1);i<j;i++,j--){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
    }
    printf("The reversed array:\n");
    for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }

return 0;}*/


// Insertion using array
// int main(){
//     int n=5;
//     int a[5]={1,2,3,4,5};
//     int pos,val;
//     printf("Enter the positon and element to be inserted:");
//     scanf("%d%d",&pos,&val);
//     for(int i=n-1;i>=(pos-1);i--){
//         a[i+1]=a[i];
        
//     }
//     a[pos-1]=val;
//     for(int i=0;i<n;i++){
//         printf("%d\n",a[i]);
//     }
//     return 0;


// }
// int dup(int x[9]){
//     int c=0;
//     for(int i=0;i<9;i++){
//         for(int j=0;j<9;j++){
//             if(x[i]==x[j]){
//                 c+=1;
//             }

//         }
//     }
//     if(c==1){
//         return 1;
//     }
//     else{
//         return 0;
//     }

// }
// int main(){
//     int x[9]={1,2,3,4,5,6,7,9,9};
//     int c=0;
//     for(int i=0;i<9;i++){
//         for(int j=0;j<9;j++){
//             if(x[i]==x[j]){
//                 c++;
//                 printf("%d and %d\n",i,c);
//             }

//         }
//     }
//     if(c==9){
//         printf("no dup");
//     }
//     else{
//         printf("yes dup");
//     }

// }


// 


int check(int q[9],int w[9]){
    int c=0;

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
        if((q[j]>0 && q[j]<10)&&(q[j]==w[i])){
            c++;
            w[i]=0;
        }
    }
    }
    if(c==9){
        return 1;
    }
    else{
        return 0;
    }

}
int main(){
    int z[9]={1,2,3,4,5,6,7,8,9};
    int o[9]={1,1,2,3,4,5,6,7,8};
    if(check(o,z)){
        printf("Yes");
    }
    else{
        printf("No");

    }
    return 0;
}