#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

Node *root = new Node;
//======================================================================================
class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q; 
public:
    Queue(int size);
    ~Queue();
    bool isFull();
    bool isEmpty();
    void enqueue(Node *x);
    Node *dequeue();
};

Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node *[size];
}

Queue::~Queue()
{
    delete[] Q;
}

bool Queue::isEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

bool Queue::isFull()
{
    if (rear == size - 1)
    {
        return true;
    }
    return false;
}

void Queue::enqueue(Node *x)
{
    if (isFull())
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = nullptr;
    if (isEmpty())
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}
//======================================================================================
void createTree()
{
    Node *p;
    Node *t;
    int x;
    Queue q(100);
    cout << "Enter root value: ";
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter Right child value of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void preorder(Node *p)
{
    if (p)
    {
        cout << p->data << ", " << flush;
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << ", " << flush;
        inorder(p->rchild);
    }
}
void postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}
int main()
{
    createTree();
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    return 0;
}
