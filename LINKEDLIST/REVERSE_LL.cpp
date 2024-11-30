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


int count(Node *p)
{
    int count=0;
    while (p != nullptr)
    {
        count++;
        p=p->next;
    }
    return count;
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

void Reverse1(Node *p)
{
    int *A, i = 0;
    Node *q = p;
    A = new int[count(p)];
    while (q != nullptr)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != nullptr)
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse2(Node *p)
{
    Node *q = nullptr, *r = nullptr;
    while (p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3( Node *q,  Node *p)
{
    if (p)
    {
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}

int main()
{
    int A[] = {10, 20, 40, 50, 60};
    create(A, 5);
    Reverse1(first);
    Display(first);
    return 0;
}