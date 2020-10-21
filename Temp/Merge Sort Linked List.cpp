/*
A code to sort the linked list using the merge sort.
*/

#include <bits/stdc++.h>
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
//utility function for adding the node in the start of linked list

void push(node **head_ref, int data)
{
    node *n = new node(data);

    n->next = *head_ref;
    *head_ref = n;
}

//it will work as the same code written for merge sort for arrays.
//we will split the original list in to two list having seperate heads
//and will call recursion on the two lists formed. Then we will merger the two lists
//and return the head.

//for splitting the list we'll pass the linked list as reference(double pointer)
//hence the splitting function will be a void function whereas whie we merge
//two lists we need to return head to the final list and hence the merge function
//will be a node* type function.

node *mergeS(node *a, node *b)
{
    node *result = NULL;
    //base cases must.
    if (a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }

    //now pick a or b and compare the data keep adding it to the result using recursion.
    if (a->data <= b->data)
    {
        result = a;
        result->next = mergeS(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeS(a, b->next);
    }

    return result;
}

void split(node **head_ref)
{
    node *a = *head_ref;
    node *b = NULL;
    if (a == NULL || a->next == NULL)
    {
        return;
    }
    node *slow = *head_ref;
    node *fast = slow->next;

    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    b = slow->next;
    slow->next = NULL;

    split(&a);
    split(&b);

    *head_ref = mergeS(a, b);
}

int main()
{
    node *a = NULL;
    push(&a, 189);
    push(&a, 9);
    push(&a, 10);
    push(&a, 0);
    push(&a, 6);
    push(&a, 99);
    push(&a, 103);

    split(&a);

    node *temp = a;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";

    return 0;
}