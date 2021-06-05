#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
private:
    vector<int> arr;
    int parent(int idx)
    {
        return (idx - 1) / 2;
    }
    int left(int idx)
    {
        return 2 * idx + 1;
    }
    int right(int idx)
    {
        return 2 * idx + 2;
    }
    void upHeapify(int i)
    {
        if (i < 0)
        {
            return;
        }
        int pi = parent(i);
        if (arr[pi] < arr[i])
        {
            swap(arr[pi], arr[i]);
            upHeapify(pi);
        }
    }
    void downHeapify(int i)
    {
        int li = left(i);
        int ri = right(i);
        int largest = i;
        if (li < arr.size() and arr[li] > arr[i])
            largest = li;
        if (ri < arr.size() and arr[ri] > arr[i])
            largest = ri;
        if (largest == i)
            return;
        swap(arr[largest], arr[i]);
        downHeapify(arr[largest]);
    }

public:
    int top();
    int size();
    bool isEmpty();
    void push(int x);
    void pop();
    void display();
};
int PriorityQueue::top(){
    return arr[0];
}
int PriorityQueue::size(){
    return arr.size();
}
bool PriorityQueue::isEmpty(){
    return arr.size() == 0;
}
void PriorityQueue::push(int x){
    arr.push_back(x);
    upHeapify(arr.size()-1);
}
void PriorityQueue::pop(){
    arr[0] = arr.back();
    arr.pop_back();
    downHeapify(0);
}
void PriorityQueue::display(){
    for(int i= 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
        PriorityQueue pq;
 
    // Note: The element's value decides priority
 
    pq.push(3);
    pq.push(2);
    pq.push(15);
 
    cout << "Size is " << pq.size() << endl;
    pq.display();
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    pq.push(5);
    pq.push(4);
    pq.push(45);
 
    cout << endl << "Size is " << pq.size() << endl;
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << pq.top() << " ";
    pq.pop();
 
    cout << endl << boolalpha << pq.isEmpty();
    return 0;
}