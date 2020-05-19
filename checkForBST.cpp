bool isBST(Node *root)
{
    // Your code here
    stack<Node *> s;
    int leftChild = -INT_MAX;
    while (!s.empty() || root != NULL)
    {
        while (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if (root->data <= leftChild)
            return false;
        leftChild = root->data;
        root = root->right;
    }

    return true;
}