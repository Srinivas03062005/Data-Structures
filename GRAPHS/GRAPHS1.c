// Working in online c compiler

#include <stdio.h>
#include <stdlib.h>
#define max 1000000
int n;
/////////////////////////QUEUE DATA STRUCTURE
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        printf("Queue is FUll\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    int x = -1;
    struct Node *t;

    if (front == NULL)
        printf("Queue is Empty\n");
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}
/////////////////////////

void BFS(int G[][n], int start, int n)
{
    int i = start, j;
    int visited[max] = {0};
    printf("%d ", i);
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][n], int start, int n)
{
    static int visited[max] = {0};
    int j;

    if (visited[start] == 0)
    {
        printf("%d ", start);
        visited[start] = 1;

        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}

int searchGraph(int G[][n], int vertex, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == vertex && G[i][j] == 1)
                return 1; // Vertex found
        }
    }
    return 0; // Vertex not found
}

int main()
{
    int choice;
    printf("\n Graph operations\n");
    printf("1. Graph BFS\n");
    printf("2. Graph DFS\n");
    printf("3. SearchGraph\n");

    printf("\nEnter number of vertices:"); // In array we are not considering 0 so give required nodes + 1
    scanf("%d", &n);
    int G[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }
    do
    {
        printf("\nEnter choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            int value0;
            printf("Enter the first vertex value u want to insert first\n");
            scanf("%d", &value0);
            BFS(G, value0, n);
            break;
        case 2:
            int value1;
            printf("Enter the first vertex value u want to insert first\n");
            scanf("%d", &value1);
            DFS(G, value1, n);
            break;
        case 3:
            int searchValue;
            printf("Enter the value to search in the graph: ");
            scanf("%d", &searchValue);
            if (searchGraph(G, searchValue, n))
                printf("Vertex %d is found in the graph.\n", searchValue);
            else
                printf("Vertex %d is not found in the graph.\n", searchValue);
            break;
        case 4:
            printf("Exiting");
        }
    } while (choice != 4);
    return 0;
}