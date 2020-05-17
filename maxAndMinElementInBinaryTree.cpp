int findMax(struct node *root)
{
    // Your code goes here

    if (root == NULL)
        return -1;
    int x = root->data;
    int l = findMax(root->left);
    int r = findMax(root->right);
    if (x > max(l, r))
        return x;
    else
    {
        return max(l, r);
    }
}
// Returns minimum value in a given Binary Tree
int findMin(struct node *root)
{
    // Your code goes here
    if (root == NULL)
        return 999999;
    int x = root->data;
    int l = findMin(root->left);
    int r = findMin(root->right);
    if (x < min(l, r))
        return x;
    else
    {
        return min(l, r);
    }
}