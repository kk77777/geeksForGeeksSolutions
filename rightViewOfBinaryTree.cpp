void rightView(Node *root)
{
    // Your Code here
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt > 0)
        {
            Node *temp = q.front();
            q.pop();
            if (cnt == 1)
            {
                cout << temp->data << " ";
            }
            cnt--;
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}