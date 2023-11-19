#include<stdio.h>
void bubble(int a[],int x){
    int i,j,temp;
    for(i=0;i<x-1;i++){
        for(j=0;j<x-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("Sorted array: \n");
    for(i=0;i<x;i++)
    printf("%d\t",a[i]);
}
void main(){
    int a[10]={12,23,11,5,45,98,10,32,7,14};
    bubble(a,10);
}