int GetNth(struct node *head, int index)
{
    // Code here
    int i = 0;
    while (head != NULL)
    {
        i++;
        if (i == index)
        {
            return head->data;
        }
        head = head->next;
    }
}