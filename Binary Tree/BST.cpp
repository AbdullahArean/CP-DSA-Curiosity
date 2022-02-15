#include<iostream>
using namespace std;

class BST {
    
    struct Node {
        int data;
        Node* left_child;
        Node* right_child;
    };
    Node* root;
    Node* makeBSTEmpty(Node* t) {
        if(t == NULL)
            return NULL;
        {
            makeBSTEmpty(t->left_child);
            makeBSTEmpty(t->right_child);
            delete t;
        }
        return NULL;
    }
    Node* insert(int x, Node* t)
    {
        if(t == NULL)
        {
            t = new Node;
            t->data = x;
            t->left_child = t->right_child = NULL;
        }
        else if(x < t->data)
            t->left_child = insert(x, t->left_child);
        else if(x > t->data)
            t->right_child = insert(x, t->right_child);
        return t;
    }
    Node* findMin(Node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left_child == NULL)
            return t;
        else
            return findMin(t->left_child);
    }
    Node* findMax(Node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right_child == NULL)
            return t;
        else
            return findMax(t->right_child);
    }
    Node* remove(int x, Node* t) {
        Node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left_child = remove(x, t->left_child);
        else if(x > t->data)
            t->right_child = remove(x, t->right_child);
        else if(t->left_child && t->right_child)
        {
            temp = findMin(t->right_child);
            t->data = temp->data;
            t->right_child = remove(t->data, t->right_child);
        }
        else
        {
            temp = t;
            if(t->left_child == NULL)
                t = t->right_child;
            else if(t->right_child == NULL)
                t = t->left_child;
            delete temp;
        }

        return t;
    }
    void inorder(Node* t) {
        if(t == NULL)
            return;
        inorder(t->left_child);
        cout << t->data << " ";
        inorder(t->right_child);
    }
    Node* find(Node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left_child, x);
        else if(x > t->data)
            return find(t->right_child, x);
        else
            return t;
    }

public:
    BST() {
        root = NULL;
    }
    ~BST() {
        root = makeBSTEmpty(root);
    }
    void insert(int x) {
        root = insert(x, root);
    }
    void remove(int x) {
        root = remove(x, root);
    }
    void display() {
        inorder(root);
        cout << endl;
    }
    void search(int x) {
        root = find(root, x);
    }
};

int main() {
    BST t;
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.insert(30);
    t.display();
    t.remove(20);
    t.display();
    t.remove(25);
    t.display();
    t.remove(30);
    t.display();
    return 0; 
}