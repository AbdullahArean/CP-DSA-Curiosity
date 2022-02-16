//12
//12
//12
//12
//12
//12
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
class Node
{
public:
    int data;
    int count;
    Node *left_child;
    Node *right_child;
    Node(int data)
    {
        this->data = data;
        this->count = 1;
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
        else if(Current_Tree_Node->data==x) 
            Current_Tree_Node->count++;
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
        else if(Current_Tree_Node->data==x && Current_Tree_Node->count>1) {
            Current_Tree_Node->count--;
            return Current_Tree_Node;
        }
        else if(Current_Tree_Node->count==1 && Current_Tree_Node->left_child && Current_Tree_Node->right_child)
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
    bool search(int x) {
        if(find(Binary_Tree_Root, x)) return 1;
        return 0;
    }

   
};
void inorder2(Node* Current_Tree_Node,vector<int>& v) 
    {
        if(Current_Tree_Node == NULL)
            return;
        if (Current_Tree_Node->left_child)
            inorder2(Current_Tree_Node->left_child,v);
        v.push_back(Current_Tree_Node->data);
        if (Current_Tree_Node->right_child)
            inorder2(Current_Tree_Node->right_child,v);
    }
int main()
{
    int n, q,x;
    BST t1;
    char c;
    cin>>n>>q;
    while(n--) {cin>>x; t1.insert(x);}
    //cin>>c;
    for(int i=0; i<q; i++)
    {
        cin>>c>>x;
         if(c=='I')
         {
           t1.insert(x);

         }
        else if(c=='D'){
        if(t1.search(x)) t1.remove(x);
        }
        else if(c=='S'){
            vector<int> v1;
            inorder2(t1.Binary_Tree_Root,v1);
            sort(v1.begin(), v1.end());
            //for(int i=0; i<3; i++) cout<<v1[i]<<endl;
            if(x<v1[0]) printf("%d\n", v1[0]);
            else if(x>=v1[v1.size()-1]) printf("No such number\n");
            else cout<<*upper_bound(v1.begin(), v1.end(),x)<<endl;
            
            
        }
        //t1.display();
    }

}