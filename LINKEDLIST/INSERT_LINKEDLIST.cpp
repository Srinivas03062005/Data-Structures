#include <iostream>
using namespace std;
class Node
{
    public:
     int data;
     Node *next;
} *first = nullptr;

void create(int A[], int n)
{
    Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = nullptr;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void Display(Node *p)
{
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int count(Node *p)
{
    int count = 0;
    while (p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
}

void Insert(Node *p, int index, int x)
{
    if (index < 0 || index > count(p))
        return;

    Node *t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    Insert(first, 0, 5);
    Display(first);
    return 0;
}
