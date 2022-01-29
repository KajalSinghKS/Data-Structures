#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
//traversing linked list and printing all elements
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
//length of linked list
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL) //EMPTY LIST
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL) //EMPTY LIST
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int count = 1;
    while (count < position - 1) //traversing  till (n=position-1) nth node
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL) //insertion at tail
    {
        insertAtTail(head, tail, d);
        return;
    }
    //creating the node to be inserted
    Node *toBeInserted = new Node(d);

    toBeInserted->next = temp->next;
    toBeInserted->next->prev = toBeInserted;
    temp->next = toBeInserted;
    toBeInserted->prev = temp;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else //deleting middle or last node
    {
        Node *curr = head;
        Node *pre = NULL;

        int count = 1;

        while (count < position)
        {
            pre = curr;
            curr = curr->next;
            count++;
        }
        if (curr->next == NULL) //updating the tail if last node is deleted
        {
            tail = pre; 
        }

        pre->next = curr->next;
        curr->prev = NULL;
        if(curr->next!=NULL)
        {
            curr->next->prev = curr->prev;
        }
        curr->next = NULL;

        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    print(head);

    
    insertAtTail(head, tail, 20);
    print(head);

    cout << "Head: " << head->data<<" ";
    cout << "Tail: " << tail->data<<endl;

    insertAtHead(head, tail, 15); 
    print(head);

    cout << "Head: " << head->data<<" ";
    cout << "Tail: " << tail->data<<endl;

    insertAtPosition(head, tail, 3, 25);
    print(head);

    cout << "Head: " << head->data<<" ";
    cout << "Tail: " << tail->data<<endl;

    insertAtPosition(head, tail, 2, 24);
    print(head);

    cout << "Head: " << head->data<<" ";
    cout << "Tail: " << tail->data<<endl;

    insertAtPosition(head, tail, 1, 23);
    print(head);

    cout << "Head: " << head->data<<" ";
    cout << "Tail: " << tail->data<<endl;

    deleteNode(1,head,tail);
    print(head);

    cout << "Head: " << head->data<<" ";
    cout << "Tail: " << tail->data<<endl;

    deleteNode(4,head,tail);
    print(head);

    cout << "Head: " << head->data<<" ";
    cout << "Tail: " << tail->data<<endl;

    deleteNode(2,head,tail);
    print(head);

    cout << "Head: " << head->data<<" ";
    cout << "Tail: " << tail->data<<endl;

    return 0;
}
