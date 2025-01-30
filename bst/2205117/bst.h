#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
};

Node *insertNode(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and 
    // the value to be inserted
    // Returns the pointer to the root of the modified BST.
    if(node==nullptr)
    {
        Node *root=new Node;
        root->val=val;
        root->right=nullptr;
        root->left=nullptr;
        return root;
    }

    else 
    {
        if(val > node->val)
        {
            node->right = insertNode(node->right,val);
        }
        else node->left=insertNode(node->left,val);
    }
    return node;
}

Node *deleteNode(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and 
    // the value to be deleted.
    // Returns the pointer to the root of the modified BST.
    if(node==nullptr) return nullptr;
    
    if(val < node->val) node->left =  deleteNode(node->left,val);
    else if(val > node->val)  node->right = deleteNode(node->right,val);
    else 
    {
        if(node->right == nullptr && node->left == nullptr) 
        {
            delete node;
            return nullptr;
        }
        else if(node->right == nullptr || node->left == nullptr)
        {
            Node *temp;
            if(node->right) 
            {
                temp=node->right;
                delete node;
                return temp;
            }
            else 
            {
                temp=node->left;
                delete node;
                return temp;
            }
        }
        else 
        {
            Node *temp=node->right;
            while(temp->left) temp=temp->left;

            node->val=temp->val;

            node->right=deleteNode(node->right,temp->val);
            

        }
    }
    return node;


}

Node* find(Node *node, int val)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST and 
    // the value to be searched.
    // Returns the pointer to the node that contains val.
    // Returns NULL if not found.
    if(node == nullptr) return nullptr;
    if(node->val == val)
    {
        return node;
    }
    if(val > node->val) return find(node->right,val);
    else if(val < node->val) return find(node->left,val);
}

void inOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the in-order traversal of the given BST
    if(node==nullptr) return; 
    inOrder(node->left);
    cout<<node->val<<" ";
    inOrder(node->right);
}

void preOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the pre-order traversal of the given BST
    if(node==nullptr) return; 
    cout<<node->val<<" ";
    preOrder(node->left);

    preOrder(node->right);
}

void postOrder(Node *node)
{
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints the post-order traversal of the given BST
    if(node==nullptr) return;    
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->val<<" ";

}

void printTree(Node *root){
    // Write your codes here
    // This function takes a pointer to the root of the BST
    // Prints parenthesized representation of the given BST
    if(root==nullptr) return;
    cout<<root->val<<" ";
    if(root->left || root->right)
    {
    cout<<"(";
    if(root->left!=nullptr) printTree(root->left);
    else cout<<"_";
    cout<<",";
    if(root->right!=nullptr) printTree(root->right);
    else cout<<"_";
    cout<<")";
    }

}