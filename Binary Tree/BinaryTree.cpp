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
            BinaryTree          ()
    {
        this->binary_tree = NULL;
    }
            BinaryTree          (Node *binary_tree)
    {
        this->binary_tree = binary_tree;
    }
    void    print_preorder      (Node *binary_tree)
    {
        if (binary_tree)
        {
            printf("%d ", binary_tree->data);
            print_preorder(binary_tree->left_child);
            print_preorder(binary_tree->right_child);
        }
    }
    void    print_inorder       (Node *binary_tree)
    {
        if (binary_tree)
        {
            print_inorder(binary_tree->left_child);
            printf("%d ", binary_tree->data);
            print_inorder(binary_tree->right_child);
        }
    }
    void    print_postorder     (Node *binary_tree)
    {
        if (binary_tree)
        {
            print_postorder(binary_tree->left_child);
            print_postorder(binary_tree->right_child);
            printf("%d ", binary_tree->data);
        }
    }
    int     height              (Node *binary_tree)
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
    void    print_levelorder    (Node *binary_tree)
    {
        /* Function to line by line print level order traversal a tree*/
        int h = height(binary_tree);
        int i;
        for (i = 1; i <= h; i++)
        {
            printGivenLevel(binary_tree, i);
            // printf("\n");
        }
    }
    void    printGivenLevel     (Node *binary_tree, int level)
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
    int     numberofnodes       (Node *binary_tree){
        if (binary_tree)
        {
            return numberofnodes(binary_tree->left_child)+numberofnodes(binary_tree->right_child)+1;
        }
        else return 0;

    }
    Node*   BuildTreePreIn      (int in[], int pre[], int inStrt, int inEnd)
    {
        static int preIndex = 0;
        if (inStrt > inEnd) return NULL;
        Node *tNode = new Node(pre[preIndex++]);
        if (inStrt == inEnd) return tNode;
        int inIndex = -1;
        for (int i = inStrt; i <= inEnd; i++) if (in[i] == tNode->data) inIndex = i;
        tNode->left_child = BuildTreePreIn(in, pre, inStrt, inIndex - 1);
        tNode->right_child = BuildTreePreIn(in, pre, inIndex + 1, inEnd);
        return tNode;
    }
    void    BuildTree           (int in[], int pre[], int inStrt, int inEnd)
    {
        this->binary_tree = BuildTreePreIn(in,pre, inStrt, inEnd);

    }
    Node*   Returntreehead      ()
    {
        return binary_tree;
    }
};

int main()
{
    int n, in[MAXN], pre[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int j = 0; j < n; j++)
        scanf("%d", &in[j]);
    BinaryTree t1;
    t1.BuildTree(in, pre, 0, n - 1);
    t1.print_postorder(t1.Returntreehead());
    printf("\n");
    t1.print_levelorder(t1.Returntreehead());
    printf("\n");
    cout<<t1.numberofnodes(t1.Returntreehead())<<endl;
}
