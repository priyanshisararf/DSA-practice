#include<stdio.h>
void main(){
    int a[10];
    int key,i;
    printf("Enter elements in array:\n");
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    int p=0;
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    for(i=0;i<10;i++){
        if(a[i]==key){
            p=i+1;
            break;
        }
    }
    if(p!=0)
    printf("Element is present at position %d",p);
    else
    printf("Element is not present");
}