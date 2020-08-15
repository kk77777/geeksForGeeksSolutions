void levelOrder(Node *root)
{
    //Your code here
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() != 1)
    {
        root = q.front();
        q.pop();
        if (root != NULL)
        {
            cout << root->data << " ";
        }
        else if (root == NULL)
        {
            cout << "$ ";
            q.push(NULL);
            continue;
        }
        if (root->left != NULL)
            q.push(root->left);
        if (root->right != NULL)
            q.push(root->right);
    }
    cout << "$ ";
}