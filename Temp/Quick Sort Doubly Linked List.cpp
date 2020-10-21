/*
 below is the implementation to perform a quicksort on a doubly linked list
*/

//in singly linked list we cannot iterate backward because there is no prev pointer to the previous node
//but in doubly linked list we have an array like appearance i.e. we can iterate backwards on to the
//previous node just like we can do it on array.
//thus we can apply the same logic as that of the quicksort on array.
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

//utility functions
void pushNode(node **headref, int data)
{
    node *n = new node(data);
    n->next = *headref;

    if (*headref)
    {
        //the below code will generate error if headref is null i.e. while appending the first node.
        (*headref)->prev = n;
    }
    *headref = n;
}

void PrintNode(node *head)
{
    node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

//partition function that will return the pivot node.
node *partition(node *head, node *tail)
{
    //to take the last node for pivot we need to pass the tail of the linked list also.
    node *pivot = tail;
    node *temp = head;

    for (node *i = head; i != tail; i = i->next)
    {
        if (i->data <= pivot->data)
        {
            swap(i->data, temp->data);
            temp = temp->next;
        }
    }

    swap(temp->data, pivot->data);
    return temp;
}

void quicksortRecur(node *head, node *tail)
{
    //base case
    if (!head || !tail || tail->next == head) //conditions to remember
    {
        return;
    }

    node *pivot = partition(head, tail);

    quicksortRecur(head, pivot->prev);
    quicksortRecur(pivot->next, tail);
}

int main()
{
    node *n = NULL;
    pushNode(&n, 1);
    pushNode(&n, 2);
    pushNode(&n, 3);
    pushNode(&n, 4);
    pushNode(&n, 5);
    pushNode(&n, 6);
    pushNode(&n, 7);

    PrintNode(n);

    node *tail = n;
    while (tail->next)
    {
        tail = tail->next;
    }

    quicksortRecur(n, tail);

    PrintNode(n);

    return 0;
}