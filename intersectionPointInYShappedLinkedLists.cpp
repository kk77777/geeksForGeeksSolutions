int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    Node *a = head1;
    Node *b = head2;

    int l1 = 0, l2 = 0;

    while (a->next != NULL)
    {
        l1++;
        a = a->next;
    }
    while (b->next != NULL)
    {
        l2++;
        b = b->next;
    }
    int diff = abs(l1 - l2);
    Node *m = head1;
    Node *n = head2;
    if (l1 > l2)
    {
        for (int i = 0; i < diff; i++)
        {
            m = m->next;
        }
    }
    else
    {
        for (int i = 0; i < diff; i++)
        {
            n = n->next;
        }
    }
    while (m != NULL && n != NULL)
    {
        if (m == n)
        {
            return m->data;
        }
        m = m->next;
        n = n->next;
    }
}
