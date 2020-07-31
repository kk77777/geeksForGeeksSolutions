int sum = 0;
void revInorder(Node *root)
{
    if (root == NULL)
        return;
    revInorder(root->right);
    sum += root->data;
    root->data = sum;
    revInorder(root->left);
}

Node *modify(Node *root)
{
    // Your code here
    sum = 0;
    revInorder(root);
    return root;
}