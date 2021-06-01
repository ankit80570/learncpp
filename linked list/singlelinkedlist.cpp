#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
class linklist
{
private:
    node *head;

public:
    linklist();
    void insertbeg(int data);
    void insertend(int data);
    void deletebeg();
    void deleteend();
    void display();
};

linklist::linklist()
{
    head = NULL;
}
void linklist::insertbeg(int data)
{
    node *new_node = new node;
    if (head == NULL)
    {
        head = new_node;
        new_node->data = data;
        new_node->next = NULL;
    }
    else
    {
        new_node->data = data;
        new_node->next = head;
        head = new_node;
    }
}
void linklist::insertend(int data)
{
    node *new_node = new node;
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
        head = new_node;
    else
    {
        node *ptr;
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
}
void linklist::deletebeg()
{
    node *ptr;
    if (head == NULL)
    {
        cout << "\nList is empty";
        return;
    }
    else{
        cout<<"\nData Deleted: "<<head->data<<endl;
        ptr = head;
        head = head->next;
        delete ptr;
    }
}
void linklist::deleteend()
{
    node *ptr, *preptr;
    if (head == NULL)
    {
        cout << "\nList is empty";
        return;
    }
    ptr = head;
    while(ptr->next != NULL){
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    cout<<"\nDeleted data: "<<ptr->data<<endl;
    delete ptr;
}
void linklist::display()
{
    if (head == NULL)
    {
        cout << "\nList is Empty";
        return;
    }
    node *ptr;
    ptr = head;
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

    linklist l1;
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