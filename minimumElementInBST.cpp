int minValue(Node *root)
{
    // Code here
    if (root == NULL)
        return -1;
    else if (root->left == NULL)
        return root->data;
    return minValue(root->left);
}
