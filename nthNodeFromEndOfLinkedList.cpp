int getNthFromLast(Node *head, int n)
{
    // Your code here
    Node *ref = head;
    Node *current = head;

    int cnt = 0;

    while (cnt < n)
    {

        if (ref == NULL)
            return -1;
        cnt++;
        ref = ref->next;
    }

    while (ref != NULL)
    {
        ref = ref->next;
        current = current->next;
    }

    return current->data;
}
