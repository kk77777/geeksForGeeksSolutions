int isSumProperty(Node *root)
{
    // Add your code here
    if (root == NULL)
        return 1;
    if (!root->left && !root->right)
        return 1;
    if (root->left && root->right)
    {
        return ((root->left->data + root->right->data == root->data) && isSumProperty(root->left) && isSumProperty(root->right));
    }
    else
    {
        if (root->left)
        {
            return ((root->left->data == root->data) && isSumProperty(root->left) && isSumProperty(root->right));
        }
        if (root->right)
        {
            return ((root->right->data == root->data) && isSumProperty(root->left) && isSumProperty(root->right));
        }
    }
}