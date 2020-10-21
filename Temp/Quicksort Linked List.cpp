#include <iostream>
using namespace std;

#define FIO                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insert(node **refhead, int data)
{
    node *temp = new node(data);
    temp->next = (*refhead);
    *refhead = temp;
}

node *partition(node *start, node *end, node **modhead, node **modtail)
{
    node *pivot = end;
    node *prev = NULL;
    node *curr = start;

    while (curr != pivot)
    {
        if (curr->data < pivot->data)
        {
            if (!(*modhead))
            {
                *modhead = curr;
            }
            prev = curr;
            curr = curr->next;
        }
        else
        {
            if (prev)
            {
                prev->next = curr->next; //will generate an error if prev is NULL
            }
            node *temp = curr->next;
            curr->next = NULL;
            end->next = curr;
            end = curr;
            curr = temp;
        }
    }
    //this could be a possibility that pivot is the smallest of all elements
    //this means that modhead will still remain NULL so
    if (!(*modhead))
    {
        *modhead = pivot;
    }

    *modtail = end;

    return pivot;
}

node *quickSortRecur(node *head, node *tail)
{
    if (!head || head == tail)
    {
        return head;
    }

    node *modhead = NULL, *modtail = NULL;

    node *pivot = partition(head, tail, &modhead, &modtail);

    if (modhead != pivot) //if pivot is the starting element of the list then
    //there is no need to recur on the left side
    {
        node *temp = modhead;
        while (temp->next != pivot)
        {
            temp = temp->next;
        }
        temp->next = NULL;

        modhead = quickSortRecur(modhead, temp);

        temp = modhead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = pivot;
    }

    pivot->next = quickSortRecur(pivot->next, modtail);

    return modhead;
}

int main()
{
    node *a = NULL;
    insert(&a, 5);
    insert(&a, 10);
    insert(&a, 4);
    insert(&a, 3);
    insert(&a, 30);
    insert(&a, 99);

    node *tail = a;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    a = quickSortRecur(a, tail);

    node *temp = a;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";

    return 0;
}