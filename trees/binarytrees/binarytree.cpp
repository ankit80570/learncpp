#include <bits/stdc++.h>
using namespace std;

struct bt
{
    int data;
    bt *left;
    bt *right;
};

class binarytree
{
    bt *root;

public:
    binarytree()
    {
        root = NULL;
    }
    void insertnode(int);
    void preorder();
    void preorderhelper(bt *node);
    void postorder();
    void postorderhelper(bt *node);
    void inorder();
    void inorderhelper(bt *node);
    int largestele();
    int largestelehelper(bt *node);
    int smallestele();
    int smallestelehelper(bt *node);
    void deleteele(int val);
    int countnodes();
    int countnodeshelper(bt *node);
    int countinternalnodes();
    int countinternalnodeshelper(bt *node);
    int countexternalnodes();
    int countexternalnodeshelper(bt *node);
    int height();
    int heighthelper(bt *node);
    void mirror();
};
void binarytree::insertnode(int val)
{
    bt *node = new bt;
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    if (root == NULL)
    {
        root = node;
        root->left = NULL;
        root->right = NULL;
    }
    else
    {
        bt *ptr, *parentptr;
        ptr = root;
        while (ptr != NULL)
        {
            parentptr = ptr;
            if (val < ptr->data)
            {
                ptr = ptr->left;
            }
            else
            {
                ptr = ptr->right;
            }
        }
        if (val < parentptr->data)
        {
            parentptr->left = node;
        }
        else
        {
            parentptr->right = node;
        }
    }
}
void binarytree::preorder()
{
    preorderhelper(root);
}
void binarytree::preorderhelper(bt *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preorderhelper(node->left);
        preorderhelper(node->right);
    }
}
void binarytree::postorder()
{
    postorderhelper(root);
}
void binarytree::postorderhelper(bt *node)
{
    if (node != NULL)
    {
        postorderhelper(node->left);
        postorderhelper(node->right);
        cout << node->data << " ";
    }
}
void binarytree::inorder()
{
    inorderhelper(root);
}
void binarytree::inorderhelper(bt *node)
{
    if (node != NULL)
    {
        inorderhelper(node->left);
        cout << node->data << " ";
        inorderhelper(node->right);
    }
}
int binarytree::largestele()
{
    return largestelehelper(root);
}
int binarytree::largestelehelper(bt *node)
{
    if (node == NULL || node->right == NULL)
        return node->data;
    else
        return largestelehelper(node->right);
}
int binarytree::smallestele()
{
    return smallestelehelper(root);
}
int binarytree::smallestelehelper(bt *node)
{
    if (node == NULL || node->left == NULL)
        return node->data;
    else
        return smallestelehelper(node->left);
}
int binarytree::countnodes()
{
    return countnodeshelper(root);
}
int binarytree::countnodeshelper(bt *node)
{
    if (node == NULL)
        return 0;
    else
        return 1 + countnodeshelper(node->left) + countnodeshelper(node->right);
}
int binarytree::countinternalnodes()
{
    return countinternalnodeshelper(root);
}
int binarytree::countinternalnodeshelper(bt *node)
{
    if (node == NULL || (node->left == NULL && node->right == NULL))
        return 0;
    else
        return (1 + countinternalnodeshelper(node->left) + countinternalnodeshelper(node->right));
}
int binarytree::countexternalnodes()
{
    return countexternalnodeshelper(root);
}
int binarytree::countexternalnodeshelper(bt *node)
{
    if (node == NULL)
        return 0;
    else if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return countexternalnodeshelper(node->left) + countexternalnodeshelper(node->right);
}
int binarytree::height(){
    return heighthelper(root);
}
int binarytree::heighthelper(bt *node){
    if(node == NULL)
        return 0;
    else{
        int leftheight, rightheight;
        leftheight = heighthelper(node->left);
        rightheight = heighthelper(node->right);
        return max(leftheight,rightheight) +1;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    binarytree tree;
    tree.insertnode(50);
    tree.insertnode(40);
    tree.insertnode(80);
    tree.insertnode(10);
    tree.insertnode(60);
    tree.insertnode(40);
    tree.preorder();
    cout << "\nSmallest Element: " << tree.smallestele() << endl;
    cout << "\nLargest Element: " << tree.largestele() << endl;
    cout << "\nTotal Nodes: " << tree.countnodes() << endl;
    cout << "\nTotal Internal Nodes: " << tree.countinternalnodes() << endl;
    cout << "\nTotal External Nodes: " << tree.countexternalnodes() << endl;
    cout << "\nHeight: " << tree.height() << endl;
    return 0;
}