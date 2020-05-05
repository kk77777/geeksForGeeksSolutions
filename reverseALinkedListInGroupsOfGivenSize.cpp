struct node *reverse(struct node *head, int k)
{
    node *current = head;
    node *next = NULL;
    node *prev = NULL;

    int cnt = 0;

    while (current != NULL && cnt < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        cnt++;
    }

    if (next != NULL)
    {
        head->next = reverse(next, k);
    }
    return prev;
}