#include<stdio.h>
void main(){
    int a[10]={12,23,11,5,45,98,10,32,7,14};
    selection(a,10);
}
void selection(int a[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];a[j]=temp;
            }
        }
    }
    printf("Sorted array:\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
}