Node *insert(Node *root, int data)
{
    // Your code here
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }
    if (root->data == data)
    {
        return root;
    }
    else if (root->data >= data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}