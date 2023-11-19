#include<stdio.h>
void main(){
    int key,i;
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements in array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter element to be searched: ");
    scanf("%d",&key);
    int l,r,m;
    int f=0;
    l=0;r=n-1;
    while(l<=r){
        m=(l+r)/2;
        if(a[m]==key){
            f=m+1;
            break;
        }
        else if(a[m]>key){
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    if(f!=0)
    printf("Element is present at position %d",f);
    else
    printf("Element is not present");
}
