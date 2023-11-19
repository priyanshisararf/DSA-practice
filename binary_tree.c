#include<stdio.h>
struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node* createNode(int value){
    struct node* nw=(struct node*)malloc(sizeof(struct node));
    nw->data=value;
    nw->right=NULL;
    nw->left=NULL;
    return nw;
}
struct node* insertLeft(struct node*root,int value){
    root->left=createNode(value);
    return root->left;
}
struct node* insertRight(struct node*root,int value){
    root->right=createNode(value);
    return root->right;
}
void inorder(struct node* root){
    if(root==NULL)
    return;
    else{
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
    }
}
void preorder(struct node* root){
    if(root==NULL)
    return;
    else{
    printf("%d",root->data);
    inorder(root->left);
    inorder(root->right);
    }
}
void postorder(struct node* root){
    if(root==NULL)
    return;
    else{
        inorder(root->left);
        inorder(root->right);
        printf("%d",root->data);
    }
}
void main(){
    struct node* root=createNode(1);
    insertLeft(root,2);
    insertRight(root,3);
    insertLeft(root->left,4);
    insertRight(root->left,5);
    insertLeft(root->right,6);
    insertRight(root->right,7);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postorder(root);
}