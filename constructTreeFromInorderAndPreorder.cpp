Node *convert(int in[], int pre[], int si, int ei, int &pIndex)
{
    if (si > ei)
        return NULL;

    Node *root = new Node(pre[pIndex]);
    pIndex++;

    int ini = 0;

    for (int i = si; i <= ei; i++)
    {
        if (in[i] == root->data)
        {
            ini = i;
            break;
        }
    }

    root->left = convert(in, pre, si, ini - 1, pIndex);
    root->right = convert(in, pre, ini + 1, ei, pIndex);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    //add code here.
    int pIndex = 0;
    return convert(in, pre, 0, n - 1, pIndex);
}