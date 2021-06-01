#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
class circularlinkedlist
{
    node *head;

public:
    circularlinkedlist();
    void insertbeg(int data);
    void insertend(int data);
    void deletebeg();
    void deleteend();
    void display();
};
circularlinkedlist::circularlinkedlist()
{
    head = NULL;
}
void circularlinkedlist::insertbeg(int data)
{
    node *new_node = new node;
    if (head == NULL)
    {
        head = new_node;
        new_node->data = data;
        new_node->next = head;
    }
    else
    {
        node *ptr = head;
        new_node->next = head;
        new_node->data = data;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        head = new_node;
        ptr->next = head;
    }
}
void circularlinkedlist::insertend(int data)
{
    node *new_node = new node;
    if (head == NULL)
    {
        head = new_node;
        new_node->data = data;
        new_node->next = head;
    }
    else
    {
        node *ptr = head;
        new_node->next = head;
        new_node->data = data;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
void circularlinkedlist::deletebeg()
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = head->next;
    cout<<"\nDeleted data: "<<head->data<<endl;
    delete head;
    head = ptr->next;
}
void circularlinkedlist::deleteend()
{
    node *ptr = head, *preptr;
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
    while (ptr->next != head)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = head;
    cout<<"\nDeleted data: "<<ptr->data<<endl;
    delete ptr;
}
void circularlinkedlist::display()
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
    while (ptr->next != head)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << ptr->data << " " << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    circularlinkedlist l1;
    l1.insertend(10);
    l1.insertend(20);
    l1.insertend(30);
    l1.insertend(40);
    l1.insertend(50);
    l1.display();
    l1.deletebeg();
    l1.display();
    l1.deleteend();
    l1.display();

    return 0;
}