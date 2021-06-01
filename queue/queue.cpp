#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int front, back;
    vector<int> arr;

public:
    Queue()
    {
        front = -1;
        back = -1;
    }
    void push(int x)
    {
        if (front == -1)
        {
            front = back = 0;
        }
        else
            back++;
        arr.push_back(x);
    }
    int pop()
    {
        if (back == 0)
        {
            front = back = -1;
        }
        else
            front++;
        int val = arr[(front - 1)];
        return val;
    }
    int size()
    {
        return back - front + 1;
    }
    int front1()
    {
        return arr[front];
    }
    int back1()
    {
        return arr[back];
    }
    void display(){
        for (int i = front; i <= back; i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.display();
    q.pop();
    q.pop();
    q.display();

    return 0;
}