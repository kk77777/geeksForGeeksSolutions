bool search(Node *root, int x)
{
    //Your code here
    if (root == NULL)
        return 0;
    if (root->data == x)
        return 1;
    if (root->data > x)
        return search(root->left, x);
    return search(root->right, x);
}