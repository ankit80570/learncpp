#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *prev;
    int data;
    node *next;
};
class doublylinkedlist
{
    node *head;

public:
    doublylinkedlist();
    void insertbeg(int);
    void insertend(int);
    void insertafter(int, int);
    void insertbefore(int, int);
    void deletebeg();
    void deleteend();
    void deleteafter(int);
    void deletebefore(int);
    void display();
};
doublylinkedlist::doublylinkedlist()
{
    head = NULL;
}
void doublylinkedlist::insertbeg(int data)
{
    node *new_node = new node;
    if (head == NULL)
    {
        head = new_node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        head->prev = new_node;
        new_node->data = data;
        new_node->prev = NULL;
        new_node->next = head;
        head = new_node;
    }
}
void doublylinkedlist::insertend(int data)
{
    node *new_node = new node;
    if (head == NULL)
    {
        head = new_node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->data = data;
        new_node->prev = ptr;
        new_node->next = NULL;
    }
}
void doublylinkedlist::insertafter(int data, int num)
{
    node *new_node;
    if (head == NULL)
    {
        cout << "List is Empty Inserting at Beginning";
        head = new_node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        node *ptr = head, *preptr;
        new_node->data = data;
        while (preptr->data != num)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = new_node;
        ptr->prev = new_node;
        new_node->prev = preptr;
        new_node->next = ptr;
    }
}
void doublylinkedlist::insertbefore(int data, int num)
{
    node *new_node;
    if (head == NULL)
    {
        cout << "List is Empty Inserting at Beginning";
        head = new_node;
        new_node->data = data;
        new_node->next = NULL;
        new_node->prev = NULL;
    }
    else
    {
        node *ptr = head;
        new_node->data = data;
        while (ptr->data != num)
        {
            ptr = ptr->next;
        }
        new_node->next = ptr;
        new_node->prev = ptr->prev;
        ptr->prev->next = new_node;
        ptr->prev = new_node;
    }
}
void doublylinkedlist::deletebeg()
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
    head = head->next;
    head->prev = NULL;
    cout<<"\nDeleted data: "<<ptr->data<<endl;
    delete ptr;
}
void doublylinkedlist::deleteend()
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
    while(ptr->next!=NULL){
        ptr = ptr->next;
    }
    ptr->prev->next = NULL;
    cout<<"\nDeleted data: "<<ptr->data<<endl;
    delete ptr;
}
void doublylinkedlist::deleteafter(int data)
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
}
void doublylinkedlist::deletebefore(int data)
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
}
void doublylinkedlist::display()
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    doublylinkedlist l1;
    l1.insertend(10);
    l1.insertend(20);
    l1.insertend(30);
    l1.insertend(40);
    l1.insertend(50);
    l1.insertend(60);
    l1.insertend(70);
    l1.insertend(80);
    l1.display();
    l1.deletebeg();
    l1.display();
    l1.deleteend();
    l1.display();
    // l1.insertbefore(35, 40);
    // l1.display();
    // l1.insertafter(65, 60);
    // l1.display();

    return 0;
}