void deleteNode(Node *node)
{
    // Your code here
    if (node->next != NULL)
    {
        *node = *node->next;
        return;
    }
    node = NULL;
}
