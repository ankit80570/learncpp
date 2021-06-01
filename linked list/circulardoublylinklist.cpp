#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *prev;
    int data;
    node *next;
};
class cdll
{
    node *head;

public:
    cdll();
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
cdll::cdll()
{
    head = NULL;
}
void cdll::insertbeg(int data)
{
    node *new_node = new node;
    if (head == NULL)
    {
        head = new_node;
        new_node->data = data;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        head->prev = new_node;
        new_node->data = data;
        new_node->prev = ptr;
        new_node->next = head;
        head = new_node;
        ptr->next = head;
    }
}
void cdll::insertend(int data)
{
    node *new_node = new node;
    if (head == NULL)
    {
        head = new_node;
        new_node->data = data;
        new_node->next = new_node;
        new_node->prev = new_node;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != head)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->data = data;
        new_node->prev = ptr;
        new_node->next = head;
        head->prev = new_node;
    }
}
void cdll::insertafter(int data, int num)
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
void cdll::insertbefore(int data, int num)
{
    node *new_node;
    if (head == NULL)
    {
        cout << "List is Empty Inserting at Beginning";
        head = new_node;
        new_node->data = data;
        new_node->next = new_node;
        new_node->prev = new_node;
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
void cdll::deletebeg()
{
    node *ptr = head, *temp=head;
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
    head = head->next;
    head->prev = ptr;
    cout << "\nDeleted data: " << temp->data << endl;
    delete temp;
}
void cdll::deleteend()
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
    ptr->prev->next = head;
    head->prev = ptr->prev;
    cout << "\nDeleted data: " << ptr->data << endl;
    delete ptr;
}
void cdll::deleteafter(int data)
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
}
void cdll::deletebefore(int data)
{
    node *ptr = head;
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
}
void cdll::display()
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
    cdll l1;
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