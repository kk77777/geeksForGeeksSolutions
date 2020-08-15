Node *convert(int in[], int post[], int si, int ei, int &pIndex)
{
    if (si > ei)
        return NULL;

    Node *root = new Node(post[pIndex]);
    pIndex--;
    int ini = 0;
    for (int i = si; i <= ei; i++)
    {
        if (in[i] == root->data)
        {

            ini = i;
            break;
        }
    }
    root->right = convert(in, post, ini + 1, ei, pIndex);
    root->left = convert(in, post, si, ini - 1, pIndex);

    return root;
}

Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    int pIndex = n - 1;
    return convert(in, post, 0, n - 1, pIndex);
}