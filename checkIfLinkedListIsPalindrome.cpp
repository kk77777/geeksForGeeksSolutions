bool isPalindrome(Node *head)
{
    //Your code here
    stack<int> s;
    Node *temp1 = head, *temp2 = head;
    while (temp1 != NULL && temp1->next != NULL)
    {
        s.push(temp2->data);
        temp1 = temp1->next->next;
        temp2 = temp2->next;
    }

    if (temp1 != NULL)
    {
        temp2 = temp2->next;
    }
    while (temp2 != NULL)
    {
        if (temp2->data != s.top())
        {
            return 0;
        }
        s.pop();
        temp2 = temp2->next;
    }
    return 1;
}