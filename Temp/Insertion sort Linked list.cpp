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

//utility functions
void addInFront(node **head_ref, int data)
{
    node *n = new node(data);
    n->next = *head_ref;
    *head_ref = n;
}

//make a sorted list initialised to null and take up elements from the
//unsorted list and find the insertion point in the sorted list.

void util(node **final, node *tba)
{
    //if final is NULL or the incoming node's data is less than the head
    if (!(*final) || (*final)->data >= tba->data)
    {
        //insert at front
        tba->next = (*final);
        (*final) = tba;
        return;
    }

    //for the rest
    node *current = *final;

    while (current->next && current->next->data < tba->data)
    {
        current = current->next;
    }

    tba->next = current->next;
    current->next = tba;
}

void sortll(node **head_ref)
{
    node *final = NULL;
    node *current = *head_ref;
    while (current)
    {
        node *temp = current->next;
        util(&final, current);
        current = temp;
    }

    *head_ref = final;
}

int main()
{

    FIO;

    node *a = NULL;
    addInFront(&a, 1);
    addInFront(&a, 2);
    addInFront(&a, 3);
    addInFront(&a, 4);
    addInFront(&a, 5);
    addInFront(&a, 6);
    addInFront(&a, 8);
    addInFront(&a, 9);
    addInFront(&a, 10);

    sortll(&a);
    node *temp = a;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";

    return 0;
}