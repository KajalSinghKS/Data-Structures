#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next; //=NULL

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp; //now head points to the new node inserted.
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
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
        insertAtTail(tail, d);
        return;
    }
    //creating the node to be inserted
    Node *toBeInserted = new Node(d);

    toBeInserted->next = temp->next;
    temp->next = toBeInserted; //changing where the pointer points
}
void print(Node *&head) //printing all elements of linked list.
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteNode(int position, Node *&head,Node* &tail)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else //deleting middle or last node
    {
        Node *curr = head;
        Node *prev = NULL;

        int count = 1;

        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        if(curr->next==NULL)//updating the tail if last node is deleted
        {
            tail=prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10); //created a new node
    //in C struct Node* node1=(struct Node*)malloc(sizeof(struct Node));

    //values in node when it is created
    //cout<< node1->data <<endl;
    //cout<< node1->next <<endl;

    //head is pointing to node1
    Node *head = node1;
    Node *tail = node1;
    print(head);

    insertAtHead(head, 12);
    print(head);

    insertAtTail(tail, 13);
    print(head);

    insertAtPosition(head, tail, 3, 16);
    print(head);

    insertAtPosition(head, tail, 1, 20);
    print(head);

    insertAtPosition(head, tail, 6, 25);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    deleteNode(1,head,tail);
    print(head);

    deleteNode(3,head,tail);
    print(head);

    deleteNode(4,head,tail);
    print(head);

    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    return 0;
}
