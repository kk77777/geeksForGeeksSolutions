// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse(struct node *head, int k);

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        head = reverse(head, k);
        printList(head);
    }

    return (0);
}

// } Driver Code Ends

/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

//dummy,prev,curr->1->2->3
struct node *reverse(struct node *head, int k)
{
    // Complete this method
    if (head == NULL || k == 1)
        return head;
    node *d = new node(0);
    d->next = head;
    node *curr = d, *prev = d, *nextNode = d;
    int cnt = 0;
    while (curr->next != NULL)
    {
        curr = curr->next;
        cnt++;
    }
    while (cnt > 1)
    {

        curr = prev->next;
        nextNode = curr->next;
        for (int i = 1; i < k && i < cnt; i++)
        {
            curr->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
            nextNode = curr->next;
        }
        prev = curr;
        // cout << prev->data << "\n";
        // cout << prev->next->data << "\n";
        cnt -= k;
    }
    return d->next;
}
