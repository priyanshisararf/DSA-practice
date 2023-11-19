#include<stdio.h>
void main(){
    int a[10]={12,23,11,5,45,98,10,32,7,14};
    insertion(a,10);
}
void insertion(int a[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[j]>a[i]){
                temp=a[j];
                a[j]=a[i];
                a[i]=temp;
            }
        }
    }
    printf("Sorted array:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}