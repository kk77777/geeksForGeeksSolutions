// { Driver Code Starts
#include <iostream>
#include <stdio.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node *a, Node *b)
{
    // Your Code Here
    Node *d1 = a, *d2 = b;
    int la = 0, lb = 0;
    while (d1 != NULL)
    {
        la++;
        d1 = d1->next;
    }
    d1 = a;
    while (d2 != NULL)
    {
        lb++;
        d2 = d2->next;
    }
    d2 = b;
    // cout << "la = " << la << "  lb = " << lb << "\n";
    if (la > lb)
    {
        swap(la, lb);
        swap(d1, d2);
    }
    int x = lb - la;
    while (x)
    {
        d2 = d2->next;
        x--;
    }
    while (d1 != NULL && d2 != NULL)
    {
        if (d1 == d2)
            return d1->data;
        d1 = d1->next;
        d2 = d2->next;
    }
    return -1;
}
