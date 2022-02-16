#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left_child;
    Node *right_child;
    Node(int data)
    {
        this->data = data;
        this->left_child = NULL;
        this->right_child = NULL;
    }
};
class BST {
public:
    Node* Binary_Tree_Root;
    Node* makeBSTEmpty(Node* Current_Tree_Node) {
        if(Current_Tree_Node == NULL)
            return NULL;
        {
            makeBSTEmpty(Current_Tree_Node->left_child);
            makeBSTEmpty(Current_Tree_Node->right_child);
            delete Current_Tree_Node;
        }
        return NULL;
    }
    Node* insert(int x, Node* Current_Tree_Node)
    {
        if(Current_Tree_Node == NULL) 
            Current_Tree_Node = new Node(x);
        else if(x < Current_Tree_Node->data)
            Current_Tree_Node->left_child = insert(x, Current_Tree_Node->left_child);
        else if(x > Current_Tree_Node->data)
            Current_Tree_Node->right_child = insert(x, Current_Tree_Node->right_child);
        return Current_Tree_Node;
    }
    Node* findMin(Node* Current_Tree_Node)
    {
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(Current_Tree_Node->left_child == NULL)
            return Current_Tree_Node;
        else
            return findMin(Current_Tree_Node->left_child);
    }
    Node* findMax(Node* Current_Tree_Node) {
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(Current_Tree_Node->right_child == NULL)
            return Current_Tree_Node;
        else
            return findMax(Current_Tree_Node->right_child);
    }
    Node* remove(int x, Node* Current_Tree_Node) {
        Node* temp;
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(x < Current_Tree_Node->data)
            Current_Tree_Node->left_child = remove(x, Current_Tree_Node->left_child);
        else if(x > Current_Tree_Node->data)
            Current_Tree_Node->right_child = remove(x, Current_Tree_Node->right_child);
        else if(Current_Tree_Node->left_child && Current_Tree_Node->right_child)
        {
            temp = findMin(Current_Tree_Node->right_child);
            Current_Tree_Node->data = temp->data;
            Current_Tree_Node->right_child = remove(Current_Tree_Node->data, Current_Tree_Node->right_child);
        }
        else
        {
            temp = Current_Tree_Node;
            if(Current_Tree_Node->left_child == NULL)
                Current_Tree_Node = Current_Tree_Node->right_child;
            else if(Current_Tree_Node->right_child == NULL)
                Current_Tree_Node = Current_Tree_Node->left_child;
            delete temp;
        }

        return Current_Tree_Node;
    }
    void inorder(Node* Current_Tree_Node) {
        if(Current_Tree_Node == NULL)
            return;
        inorder(Current_Tree_Node->left_child);
        cout << Current_Tree_Node->data << " ";
        inorder(Current_Tree_Node->right_child);
    }
    Node* find(Node* Current_Tree_Node, int x) {
        if(Current_Tree_Node == NULL)
            return NULL;
        else if(x < Current_Tree_Node->data)
            return find(Current_Tree_Node->left_child, x);
        else if(x > Current_Tree_Node->data)
            return find(Current_Tree_Node->right_child, x);
        else
            return Current_Tree_Node;
    }
    BST() {
        Binary_Tree_Root = NULL;
    }
    ~BST() {
        Binary_Tree_Root = makeBSTEmpty(Binary_Tree_Root);
    }
    void insert(int x) {
        Binary_Tree_Root = insert(x, Binary_Tree_Root);
    }
    void remove(int x) {
        Binary_Tree_Root = remove(x, Binary_Tree_Root);
    }
    void display() {
        inorder(Binary_Tree_Root);
        cout << endl;
    }
    void search(int x) {
        Binary_Tree_Root = find(Binary_Tree_Root, x);
    }
};

int main() {
    BST Current_Tree_Node;
    Current_Tree_Node.insert(29);
    Current_Tree_Node.insert(28);
    Current_Tree_Node.insert(25);
    Current_Tree_Node.insert(10);
    Current_Tree_Node.insert(30);
    Current_Tree_Node.display();
    Current_Tree_Node.remove(20);
    Current_Tree_Node.display();
    Current_Tree_Node.remove(25);
    Current_Tree_Node.display();
    Current_Tree_Node.remove(30);
    Current_Tree_Node.display();
    cout<<Current_Tree_Node.findMax(Current_Tree_Node.Binary_Tree_Root)->data<<endl;
    return 0; 
}