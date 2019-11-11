#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector> 
#include <math.h>
using namespace std;

struct node{
    int key;
    struct node *left, *right;};// A utility function to create a new BST node
    struct node *newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key){
/* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);
/* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
/* return the (unchanged) node pointer */
    return node;
    
}


void preorder(struct node *root){
    if (root != NULL){
        printf("%d \n", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root,vector<node*> &tree){
    if (root != NULL){
        inorder(root->left,tree);
        tree.push_back(root);
        inorder(root->right,tree);
    }
}

struct node* balance(vector<node*> list, int inicio, int final){
    if(inicio>final){
        return NULL;
    }
    int mid = ceil((final+inicio)/2);
    struct node* root = newNode(list.at(mid)->key);
    root->left = balance(list,inicio, mid-1);
    root->right = balance(list,mid+1,final);
    return root;
}


int main(){
    
    struct node *root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 13);
    vector<node*> lista;
    inorder(root,lista);
    
    preorder(balance(lista,0,lista.size()-1));
    // print inoder traversal of the BST
    //preorder(root);
    
    return 0;
}
