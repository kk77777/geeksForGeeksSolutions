// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree(int inorder[], int preorder[], int n);

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];

        Node *root = buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

Node *construct(int *in, int *pre, int &pIndex, int s, int e)
{
    if (s > e)
        return NULL;
    Node *root = new Node(pre[pIndex++]);
    int index;
    for (int i = s; i <= e; i++)
    {
        if (in[i] == root->data)
        {
            index = i;
        }
    }
    root->left = construct(in, pre, pIndex, s, index - 1);
    root->right = construct(in, pre, pIndex, index + 1, e);
    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    //add code here.
    int pIndex = 0;
    return construct(in, pre, pIndex, 0, n - 1);
}