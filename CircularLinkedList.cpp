//In circular linked list, no pointer will be pointing to NULL.
//No need to maintain head also, tail->next will give head.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    if (tail == NULL) //empty list
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else //inserting a node after the node having data=element.
    {
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        //curr is pointing to the node having data=element
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    if (tail == NULL) //empty list
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

void deleteNode(Node *&tail, int value)
{
    //empty list
    if (tail == NULL)
    {
        cout << "List is empty. Nothing can be deleted." << endl;
        return;
    }
    else //Deleting the node having data=value. Value passed to function should be present in list.
    {
        Node *prev = tail;
        Node *curr = prev->next;
        if (prev == curr) //single node in list
        {
            delete curr;
            tail = NULL;
            return;
        }
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        if (tail == curr) //>=2 nodes list
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *tail = NULL;

    //inserting in empty list
    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    deleteNode(tail, 5);
    print(tail);

    deleteNode(tail, 3);
    print(tail);

    return 0;
}