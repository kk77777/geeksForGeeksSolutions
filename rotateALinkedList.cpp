Node *rotate(Node *head, int k)
{
    // Your code here
    if (k == 0)
        return head;
    Node *current = head;
    int cnt = 0;
    while (cnt < k - 1 && current != NULL)
    {
        cnt++;
        current = current->next;
    }
    if (current == NULL)
        return head;

    Node *kthNode = current;

    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = head;

    head = kthNode->next;
    kthNode->next = NULL;
    return head;
}