/*
Problem Link  :
About Problem : Binary Tree Implementation
Tags          :
 */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int max(int inorder[], int strt, int end);
class Node
{
public:
    int data;
    Node *left_child;
    Node *right_child;
    Node()
    {
        this->data = data;
        this->left_child = NULL;
        this->right_child = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->left_child = NULL;
        this->right_child = NULL;
    }
};
class BinaryTree
{
private:
    Node *binary_tree;

public:
    BinaryTree()
    {
        this->binary_tree = NULL;
    }
    BinaryTree(Node *temp)
    {
        this->binary_tree = temp;
    }
    void insertfunction(Node **binary_tree, int value)
    {
        Node *tmp = NULL;
        if (!(*binary_tree))
        {
            tmp = new Node(value);
            *binary_tree = tmp;
            return;
        }
        if (value < (*binary_tree)->data)
        {
            insertfunction(&(*binary_tree)->left_child, value);
        }
        else if (value > (*binary_tree)->data)
        {
            insertfunction(&(*binary_tree)->right_child, value);
        }
    }
    Node *searchfunction1(Node **binary_tree, int value)
    {
        if (!(*binary_tree))
        {
            return NULL;
        }
        if (value == (*binary_tree)->data)
        {
            return *binary_tree;
        }
        else if (value < (*binary_tree)->data)
        {
            searchfunction1(&((*binary_tree)->left_child), value);
        }
        else if (value > (*binary_tree)->data)
        {
            searchfunction1(&((*binary_tree)->right_child), value);
        }
        return NULL;
    }
    void insert(int value)
    {
        insertfunction(&this->binary_tree, value);
    }
    Node *search(Node *binary_tree, int value)
    {
        if (binary_tree)
        {
            Node *temp1 = search(binary_tree->left_child, value);
            if(temp1!=NULL)return temp1;
            if (binary_tree->data == value)
            if(binary_tree!=NULL) return binary_tree;
            Node *temp2 = search(binary_tree->right_child, value);
            if(temp2!=NULL) return temp2;
        }
        return NULL;
    }
    void print_preorder(Node *binary_tree)
    {
        if (binary_tree)
        {
            printf("%d\n", binary_tree->data);
            print_preorder(binary_tree->left_child);
            print_preorder(binary_tree->right_child);
        }
    }
    void print_inorder(Node *binary_tree)
    {
        if (binary_tree)
        {
            print_inorder(binary_tree->left_child);
            printf("%d\n", binary_tree->data);
            print_inorder(binary_tree->right_child);
        }
    }
    void print_postorder(Node *binary_tree)
    {
        if (binary_tree)
        {
            print_postorder(binary_tree->left_child);
            print_postorder(binary_tree->right_child);
            printf("%d\n", binary_tree->data);
        }
    }
    int height1(Node *node)
    {
        if (node == NULL)
            return -1;
        else
        {
            int left_depth = height(node->left_child);
            int right_depth = height(node->right_child);
            if (left_depth > right_depth)
                return (left_depth + 2); // interms of madepth return  left_depth+1)
            else
                return (right_depth + 2);
        }
    }
    int height(Node *binary_tree)
    {
        int depth = 0;

        queue<Node *> q;
        q.push(binary_tree);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                depth++;
            }
            if (temp != NULL)
            {
                if (temp->left_child)
                {
                    q.push(temp->left_child);
                }
                if (temp->right_child)
                {
                    q.push(temp->right_child);
                }
            }
            else if (!q.empty())
            {
                q.push(NULL);
            }
        }
        return depth;
    }
    void print_levelorder(Node *binary_tree)
    {
        /* Function to line by line print level order traversal a tree*/
        int h = height(binary_tree);
        int i;
        for (i = 1; i <= h; i++)
        {
            printGivenLevel(binary_tree, i);
            printf("\n");
        }
    }
    void printGivenLevel(Node *binary_tree, int level)
    {
        /* Print nodes at a given level */
        if (binary_tree == NULL)
            return;
        if (level == 1)
            printf("%d ", binary_tree->data);
        else if (level > 1)
        {
            printGivenLevel(binary_tree->left_child, level - 1);
            printGivenLevel(binary_tree->right_child, level - 1);
        }
    }
    Node *Returntreehead()
    {
        return binary_tree;
    }
};
int search(int arr[], int strt, int end, int value)
{
	int i;
	for (i = strt; i <= end; i++)
	{
		if (arr[i] == value)
			return i;
	}
    return -1;
}
Node* newNode(int data)
{
    Node* Nnode = new Node();
    Nnode->data = data;
    Nnode->left_child = NULL;
    Nnode->right_child = NULL;
 
    return (Nnode);
}
Node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;
	Node* tNode = newNode(pre[preIndex++]);

	if (inStrt == inEnd)
		return tNode;
	int inIndex = search(in, inStrt, inEnd, tNode->data);
	tNode->left_child = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right_child = buildTree(in, pre, inIndex + 1, inEnd);

	return tNode;
}

int main()
{
    int n, in[MAXN],pre[MAXN];
    cin>>n;
    for(int i=0; i<n; i++) scanf("%d",&pre[i]);
    for(int j=0; j<n; j++) scanf("%d",&in[j]);
	int len = n;
	Node* root = buildTree(in, pre, 0, len - 1);
    BinaryTree t1 = BinaryTree(root);
    t1.print_postorder(t1.Returntreehead());
    printf("\n");
    t1.print_levelorder(t1.Returntreehead());
    printf("\n");
}

// void Solution()
// {
//     // BinaryTree t1 = BinaryTree();
//     // t1.insert(10);
//     // t1.insert(27);
//     // t1.insert(39);
//     // t1.insert(11);
//     // t1.insert(8);
//     // t1.insert(4);
//     // t1.insert(6);
//     // t1.insert(3);
//     // t1.insert(2);
//     // postorder
//     // preorder
//     // levelorder
//     int arr[] = {2, 3, 4, 6, 8, 10, 11, 27, 39};
//     // vector<int> preorder= {10,8,4,3,2,6,27,11,39} ;//preorder

//     // vector<int> inorder = preordertoinorder(preorder);
//     BinaryTree t2 = BinaryTree(build_tree_inorder(arr, 0, 8));
//     Node * temp = t2.search(t2.Returntreehead(), 3);
//     if(temp==NULL) cout<<"Data Not Found"<<endl;
//     else printf("Data Found! %d",temp->data );

// }

// int main()
// {
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);

//     Solution();

//     return 0;
// }