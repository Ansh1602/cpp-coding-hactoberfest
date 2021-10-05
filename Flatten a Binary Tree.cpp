/*

Given a binary tree, flatten it into linked list in-
place. After flattening, left of each node should
point to NULL and right should contain next node
in preorder sequence.
(It's NOT allowed to use other data structures)

1. Recursively, flatten the left and right subtrees
2. Store the left tail and right tail
3. Store the right subtree in "Temp" & make left subtree as the right subtree
4. Join the right subtree with left subtree
5. Return the Right tail
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flatten(Node* root){

    if(root == NULL || (root->left == NULL  && root->right == NULL))
        return;

    if(root->left != NULL){
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right != NULL){
            t = t->right;
        }

        t->right = temp;
    }

    flatten(root->right);
}

void inorderPrint(struct Node* root){

    if(root==NULL)      // Base Conditiom
        return; 
    
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

/*
                                               1
                                             /   \
                                            2     3
                                           / \   / \
                                          4   5  6  7
                                    Flatten == 1 2 4 5 3 6 7 same as inorder print
*/

int main()
{
     Node *root = new Node(1);
    root->left = new Node(2);           
    root->right = new Node(3);
    root->left->left = new Node(4);   
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    flatten(root);  // 1 2 4 5 3 6 7
    inorderPrint(root); // 1 2 4 5 3 6 7    
    cout<<endl;  


    return 0;
}


