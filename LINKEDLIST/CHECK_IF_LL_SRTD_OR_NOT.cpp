#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
      int data;
      Node *next;
} *first = nullptr;

void Display(Node *p)
{
    while (p != nullptr)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
}
void create(int A[], int n)
{
    int i;
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}
int isSorted(Node *p)
{
    int x = INT_MIN;
    while (p != nullptr)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    cout<<isSorted(first);
    return 0;
}