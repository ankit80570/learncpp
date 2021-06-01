#include<bits/stdc++.h>
using namespace std;
class Stack{
    vector<int> array;
    int top;
    public:
    Stack(){
        top = -1;
    }
    int getTop(){
        return top;
    }
    void push(int x){
        array.push_back(x);
        top++;
    }
    int pop(){
        int x = array[top];
        top--;
        array.pop_back();
        return x;
    }
    int peek(){
        return array[top];
    }
    bool isEmpty(){
        return top < 0;
    }

};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<< "Popping an element "<<s.pop()<<endl;
    cout<<"Top is "<<s.getTop()<<endl;
    while(!s.isEmpty()){
        cout<<s.pop()<<" ";
    }

    return 0;
}